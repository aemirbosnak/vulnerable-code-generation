//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

void printPoints(Point points[], int count) {
    printf("Points:\n");
    for (int i = 0; i < count; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
}

double distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double computePerimeter(Point points[], int count) {
    double perimeter = 0.0;
    for (int i = 0; i < count; i++) {
        perimeter += distance(points[i], points[(i + 1) % count]);
    }
    return perimeter;
}

double areaOfTriangle(Point a, Point b, Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

double computeArea(Point points[], int count) {
    double area = 0.0;
    for (int i = 1; i < count - 1; i++) {
        area += areaOfTriangle(points[0], points[i], points[i + 1]);
    }
    return area;
}

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;

    if (pointA->y == pointB->y) {
        return (pointA->x > pointB->x) ? 1 : -1;
    }
    return (pointA->y > pointB->y) ? 1 : -1;
}

void sortPoints(Point points[], int count) {
    qsort(points, count, sizeof(Point), compare);
}

int convexHull(Point points[], int count, Point hull[]) {
    sortPoints(points, count);
    
    int hullCount = 0;

    for (int i = 0; i < count; i++) {
        while (hullCount >= 2 &&
               (hull[hullCount - 1].x - hull[hullCount - 2].x) * (points[i].y - hull[hullCount - 1].y) - 
               (hull[hullCount - 1].y - hull[hullCount - 2].y) * (points[i].x - hull[hullCount - 1].x) <= 0) {
            hullCount--;
        }
        hull[hullCount++] = points[i];
    }

    int lowerHullCount = hullCount + 1;

    for (int i = count - 1; i >= 0; i--) {
        while (hullCount >= lowerHullCount &&
               (hull[hullCount - 1].x - hull[hullCount - 2].x) * (points[i].y - hull[hullCount - 1].y) -  
               (hull[hullCount - 1].y - hull[hullCount - 2].y) * (points[i].x - hull[hullCount - 1].x) <= 0) {
            hullCount--;
        }
        hull[hullCount++] = points[i];
    }
    
    return hullCount - 1; // Last point is repeated
}

void displayConvexHull(Point hull[], int hullCount) {
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullCount; i++) {
        printf("Hull Point %d: (%.2f, %.2f)\n", i + 1, hull[i].x, hull[i].y);
    }
}

int main() {
    Point points[MAX_POINTS];
    Point hull[MAX_POINTS];
    int pointCount;
    
    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &pointCount);

    if (pointCount < 3 || pointCount > MAX_POINTS) {
        printf("Please enter a valid number of points between 3 and %d.\n", MAX_POINTS);
        return 1;
    }

    for (int i = 0; i < pointCount; i++) {
        printf("Enter coordinates for Point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printPoints(points, pointCount);
    
    double perimeter = computePerimeter(points, pointCount);
    double area = computeArea(points, pointCount);
    
    printf("Perimeter of the polygon: %.2f\n", perimeter);
    printf("Area of the polygon: %.2f\n", area);

    int hullCount = convexHull(points, pointCount, hull);
    displayConvexHull(hull, hullCount);

    return 0;
}