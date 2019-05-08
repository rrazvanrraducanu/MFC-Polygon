
// PolygonView.cpp : implementation of the CPolygonView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Polygon.h"
#endif

#include "PolygonDoc.h"
#include "PolygonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPolygonView

IMPLEMENT_DYNCREATE(CPolygonView, CView)

BEGIN_MESSAGE_MAP(CPolygonView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPolygonView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CPolygonView construction/destruction

CPolygonView::CPolygonView() noexcept
{
	// TODO: add construction code here

}

CPolygonView::~CPolygonView()
{
}

BOOL CPolygonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPolygonView drawing

void CPolygonView::OnDraw(CDC* /*pDC*/)
{
	CPolygonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPolygonView printing


void CPolygonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPolygonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPolygonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPolygonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPolygonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPolygonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPolygonView diagnostics

#ifdef _DEBUG
void CPolygonView::AssertValid() const
{
	CView::AssertValid();
}

void CPolygonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolygonDoc* CPolygonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonDoc)));
	return (CPolygonDoc*)m_pDocument;
}
#endif //_DEBUG


// CPolygonView message handlers


void CPolygonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	CBrush brush(RGB(0, 0, 255));
	dc.SelectObject(&brush);
	CPoint a[10];
	a[0] = CPoint(10, 10);
	a[1] = CPoint(20, 190);
	a[2] = CPoint(150, 180);
	a[3] = CPoint(200, 30);
	dc.Polygon(a, 4);
	CView::OnLButtonDown(nFlags, point);
}
