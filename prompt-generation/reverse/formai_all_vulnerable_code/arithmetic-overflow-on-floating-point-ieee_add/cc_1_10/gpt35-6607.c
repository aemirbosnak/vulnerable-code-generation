//FormAI DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct point{
  double x,y;
} Point;

void drawFractal(Point A, Point B, double scale_factor, int level){
    // Base case
    if(level == 0){
        printf("%.2f,%.2f,",A.x,A.y);
        printf("%.2f,%.2f,",B.x,B.y);
        return;
    }
    
    // Find the midpoint of two given points
    Point mid;
    mid.x = (A.x + B.x)/2.0;
    mid.y = (A.y + B.y)/2.0;
    
    // Create two new points which are equidistant from mid
    Point P,Q;
    P.x = mid.x + scale_factor*(B.y - mid.y);
    P.y = mid.y + scale_factor*(mid.x - B.x);
    Q.x = mid.x + scale_factor*(mid.y - A.y);
    Q.y = mid.y + scale_factor*(A.x - mid.x);
    
    // Recursively draw the smaller sub-fractals
    drawFractal(A,Q,scale_factor,level-1);
    drawFractal(Q,P,scale_factor,level-1);
    drawFractal(P,B,scale_factor,level-1);
}

int main(){
    Point A,B;
    double scale_factor;
    int level;

    printf("Enter coordinates of point A(x,y): ");
    scanf("%lf,%lf",&A.x,&A.y);
    printf("Enter coordinates of point B(x,y): ");
    scanf("%lf,%lf",&B.x,&B.y);
    printf("Enter scaling factor (between 0 and 1): ");
    scanf("%lf",&scale_factor);
    printf("Enter fractal level (between 0 and 10): ");
    scanf("%d",&level);
    
    // Print the starting points
    printf("%.2f,%.2f,",A.x,A.y);
    printf("%.2f,%.2f,",B.x,B.y);
    
    drawFractal(A,B,scale_factor,level);
    return 0;
}