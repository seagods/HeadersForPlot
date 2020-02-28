//g++ -o tracer tracer.cpp -L/usr/X11R6/lib -lX11

#include <stdio.h>  //standard input output
#include <iostream> // input output (cin cout etc)
#include <fstream>  //file stream
#include <stdlib.h> //string conversion + malloc and calloc
#include <math.h>
#include <iomanip>  //setprecision
#include <sstream>  //string stream
#include <string>   // nice string operations
#include <vector>   // a bit like a souped up stack
#include <sys/stat.h>  //POSIX stuff including file queries
#include <new>   // use nothrow
#include <cstdlib> //general utilities
#include <time.h>
#include <complex>
#include <ctime>
#include <cmath>

#include <X11/Xlib.h>


using namespace std;

int main(int argc, char* argv[]){

    Bool result;
    Window root_window;
    Window window_returned;
    int root_x, root_y;
    int win_x, win_y;
    unsigned int mask_return;

    Display *display = XOpenDisplay(NULL);

    root_window = (Window)malloc(sizeof(Window));
    int iwind=0;
    root_window = XRootWindow(display, iwind);  //initialise


    XGrabPointer(display,
               root_window,
               False,
               ButtonPressMask |
               ButtonReleaseMask |
               PointerMotionMask |
               FocusChangeMask |
               EnterWindowMask |
               LeaveWindowMask,
               GrabModeAsync,
               GrabModeAsync,
               root_window, 
               None,
               CurrentTime);

   XEvent event;

bool quitprog=false;

while(!quitprog){

bool result;

result = XQueryPointer(display, root_window, &window_returned, &window_returned, &root_x, &root_y, &win_x, &win_y,&mask_return);

printf("Mouse is at (%d,%d)\n", root_x, root_y);
XNextEvent(display, &event);
   if(event.type==ButtonPress){
         cout << "Button Pressed" << endl;
         cout << "Button=" << event.xbutton.button << endl;
         if(event.xbutton.button==2)quitprog=true;
   }
}

XUngrabPointer(display,CurrentTime);

return 0;

}

