//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
/* This program uses the Graham Scan algorithm to find the convex hull of a set of points in a 2D plane */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

struct point {
    double x,y;
};

/* Global variables */
int num_points;
struct point points[MAX_POINTS];
int hull[MAX_POINTS];
int top;

/* Function to compare two points based on the angle they make with the x-axis */
int cmp(const void *a, const void *b) {
    struct point *p1 = (struct point *)a;
    struct point *p2 = (struct point *)b;
    double angle1 = atan2(p1->y - points[0].y, p1->x - points[0].x);
    double angle2 = atan2(p2->y - points[0].y, p2->x - points[0].x);
    if (angle1 < angle2)
        return -1;
    else if (angle1 > angle2)
        return 1;
    else
        return 0;
}

/* Function to calculate the distance between two points */
double dist(struct point *p1, struct point *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

/* Function to determine whether a point is to the left of, right of, or on a line */
int orientation(struct point *p1, struct point *p2, struct point *p3) {
    double val = (p2->y - p1->y) * (p3->x - p2->x) - (p2->x - p1->x) * (p3->y - p2->y);
    if (val == 0.0)
        return 0;
    else if (val > 0.0)
        return 1;
    else
        return -1;
}

/* Function to find the convex hull of a set of points */
void convex_hull() {
    int i,j,k;
    
    /* Find the point with the smallest y-coordinate */
    int min = 0;
    for (i = 1; i < num_points; i++) {
        if (points[i].y < points[min].y ||
            (points[i].y == points[min].y && points[i].x < points[min].x))
            min = i;
    }
    
    /* Put the point with the smallest y-coordinate at the beginning */
    struct point temp = points[0];
    points[0] = points[min];
    points[min] = temp;
    
    /* Sort the remaining points by angle with respect to the first point */
    qsort(&points[1], num_points-1, sizeof(struct point), cmp);
    
    /* Add the first three points to the hull */
    hull[0] = 0;
    top = 2;
    for (i = 1; i < 3; i++) {
        hull[i] = i;
    }
    
    /* Scan the remaining points one by one */
    for (i = 3; i < num_points; i++) {
        /* Remove any points that are inside the current triangle */
        while (orientation(&points[hull[top-1]], &points[hull[top]], &points[i]) <= 0) {
            top--;
        }
        /* Add the new point to the hull */
        top++;
        hull[top] = i;
    }
}

int main() {
    int i;
    
    /* Read in the number of points */
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    
    /* Read in the points */
    printf("Enter the points (x y): ");
    for (i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    
    /* Find the convex hull */
    convex_hull();
    
    /* Print out the hull */
    printf("Convex hull: ");
    for (i = 0; i <= top; i++) {
        printf("(%lf,%lf) ", points[hull[i]].x, points[hull[i]].y);
    }
    printf("\n");
    
    return 0;
}