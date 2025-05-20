//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    float x, y;
} Point;

// Function Declarations
void generateRandomPoints(Point points[], int count);
float crossProduct(Point a, Point b, Point c);
int compare(const void *p1, const void *p2);
void computeConvexHull(Point points[], int count, Point hull[], int *hullCount);
void printPoints(Point points[], int count);

int main() {
    int numPoints;
    Point points[MAX_POINTS];
    Point hull[MAX_POINTS];
    int hullCount = 0;

    printf("Enter the number of random points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);

    if(numPoints > MAX_POINTS) {
        printf("The number of points exceeds the maximum limit (%d).\n", MAX_POINTS);
        return 1;
    }

    generateRandomPoints(points, numPoints);
    
    printf("Generated Random Points:\n");
    printPoints(points, numPoints);

    computeConvexHull(points, numPoints, hull, &hullCount);

    printf("Convex Hull Points:\n");
    printPoints(hull, hullCount);

    return 0;
}

// Function to generate random points in 2D space
void generateRandomPoints(Point points[], int count) {
    for (int i = 0; i < count; i++) {
        points[i].x = (float)(rand() % 100);
        points[i].y = (float)(rand() % 100);
    }
}

// Function to compute the cross product of vectors
float crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to compare points based on their polar angle with respect to the first point
int compare(const void *p1, const void *p2) {
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;

    if(point1->x == point2->x) {
        return (point1->y > point2->y) ? 1 : -1;
    }
    return (point1->x > point2->x) ? 1 : -1;
}

// Function to compute the convex hull using Graham scan algorithm
void computeConvexHull(Point points[], int count, Point hull[], int *hullCount) {
    // Find the point with the lowest y-coordinate
    Point start = points[0];
    for (int i = 1; i < count; i++) {
        if (points[i].y < start.y || (points[i].y == start.y && points[i].x < start.x)) {
            start = points[i];
        }
    }

    // Sort the points based on the polar angle with the start point
    qsort(points, count, sizeof(Point), compare);

    hull[*hullCount] = start;
    (*hullCount)++;

    for (int i = 1; i < count; i++) {
        while (*hullCount >= 2 && 
               crossProduct(hull[*hullCount - 2], hull[*hullCount - 1], points[i]) <= 0) {
            (*hullCount)--;
        }
        hull[*hullCount] = points[i];
        (*hullCount)++;
    }
}

// Function to print points
void printPoints(Point points[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
    printf("\n");
}