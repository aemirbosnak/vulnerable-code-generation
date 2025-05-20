//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow((p2.x-p1.x), 2) + pow((p2.y-p1.y), 2));
}

// Function to calculate slope of line between two points
double slope(Point p1, Point p2) {
    return ((p2.y-p1.y)/(p2.x-p1.x));
}

// Function to calculate midpoint of line between two points
Point midpoint(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x)/2;
    mid.y = (p1.y + p2.y)/2;
    return mid;
}

// Function to calculate intersection point of two lines
Point intersection(Point p1, Point p2, Point p3, Point p4) {
    Point inter;
    double m1 = slope(p1, p2);
    double m2 = slope(p3, p4);
    inter.x = (p3.y-p1.y + m1*p1.x - m2*p3.x)/(m1-m2);
    inter.y = p1.y + m1*(inter.x-p1.x);
    return inter;
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {4, 3};
    Point p3 = {2, 1};
    Point p4 = {6, 5};
    
    double dist = distance(p1, p2);
    double slp = slope(p1, p2);
    Point mid = midpoint(p1, p2);
    Point inter = intersection(p1, p2, p3, p4);
    
    printf("Distance between p1 and p2: %lf\n", dist);
    printf("Slope of line between p1 and p2: %lf\n", slp);
    printf("Midpoint of line between p1 and p2: (%lf, %lf)\n", mid.x, mid.y);
    printf("Intersection point of line formed by p1 and p2, and line formed by p3 and p4: (%lf, %lf)\n", inter.x, inter.y);
    
    return 0;
}