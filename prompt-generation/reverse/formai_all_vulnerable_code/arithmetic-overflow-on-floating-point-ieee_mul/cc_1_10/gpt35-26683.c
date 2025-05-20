//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include<stdio.h>
#include<math.h>

// Define a structure to represent a point in 2D space
typedef struct Point{
    double x;
    double y;
}Point;

// Define a structure to represent a line in 2D space
typedef struct Line{
    Point p1;
    Point p2;
}Line;

// Calculate distance between two given points
double distance(Point p1, Point p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Calculate slope of a given line
double slope(Line l){
    return (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
}

// Calculate y-intercept of a given line
double y_intercept(Line l){
    return l.p1.y - slope(l) * l.p1.x;
}

// Check if two lines are parallel
int is_parallel(Line l1, Line l2){
    return slope(l1) == slope(l2);
}

// Check if two lines are perpendicular
int is_perpendicular(Line l1, Line l2){
    return slope(l1) * slope(l2) == -1;
}

// Calculate intersection point of two given lines
Point intersection_point(Line l1, Line l2){
    Point p;
    if(is_parallel(l1, l2)){
        printf("Lines are parallel!\n");
        return p;
    }
    double x = (y_intercept(l2) - y_intercept(l1)) / (slope(l1) - slope(l2));
    double y = slope(l1) * x + y_intercept(l1);
    p.x = x;
    p.y = y;
    return p;
}

int main(){
    Point p1 = {1, 2};
    Point p2 = {4, 3};
    Point p3 = {2, 3};
    Point p4 = {5, 4};
    Line l1 = {p1, p2};
    Line l2 = {p3, p4};
    printf("Distance between p1 and p2: %lf\n", distance(p1, p2));
    printf("Slope of line l1: %lf\n", slope(l1));
    printf("Y-intercept of line l1: %lf\n", y_intercept(l1));
    printf("Are l1 and l2 parallel? %s\n", is_parallel(l1, l2) ? "Yes" : "No");
    printf("Are l1 and l2 perpendicular? %s\n", is_perpendicular(l1, l2) ? "Yes" : "No");
    Point intersection = intersection_point(l1, l2);
    printf("Intersection point of l1 and l2: (%lf, %lf)\n", intersection.x, intersection.y);
    return 0;
}