// avi_trackbar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<highgui.h>
#include<cv.h>
int g_slider_position = 0;
CvCapture *g_capture = NULL;
void onTrackbarSilder(int pos)
{
	cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);
}
int _tmain(int argc, _TCHAR* argv[])
{
	cvNamedWindow("avi_trackbar",CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("D:\\Beyond - 光辉岁月opencv.avi");
	int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
	if (frames != 0)
	{
		cvCreateTrackbar("positons","avi_trackbar",&g_slider_position,frames,onTrackbarSilder);
	}
	IplImage *frame;
	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame)
			break;
		cvShowImage("avi_trackbar",frame);
		
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("avi_trackbar");
}

