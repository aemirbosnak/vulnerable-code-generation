//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

Point pivot; // Global pivot point for the convex hull

// Function to compare two points based on polar angle with respect to the pivot
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    int orientation = (p1->x - pivot.x) * (p2->y - pivot.y) - (p2->x - pivot.x) * (p1->y - pivot.y);
    return (orientation == 0) ? (p1->x - p2->x) : (orientation < 0) ? -1 : 1;
}

// Function to find the pivot point (point with the lowest y-coordinate)
Point findPivot(Point points[], int n) {
    Point minPoint = points[0];

    for (int i = 1; i < n; i++) {
        if (points[i].y < minPoint.y || (points[i].y == minPoint.y && points[i].x < minPoint.x)) {
            minPoint = points[i];
        }
    }
    return minPoint;
}

// Function to compute the convex hull using Graham's scan algorithm
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull is not possible with less than 3 points.\n");
        return;
    }

    // Step 1: Find the pivot point
    pivot = findPivot(points, n);

    // Step 2: Sort points based on polar angle with respect to the pivot
    qsort(points, n, sizeof(Point), compare);

    // Step 3: Initialize the hull with the first three points
    Point hull[n];
    int hullSize = 0;

    for (int i = 0; i < 3; i++) {
        hull[hullSize++] = points[i];
    }

    // Step 4: Process remaining points
    for (int i = 3; i < n; i++) {
        while (hullSize >= 2) {
            Point p1 = hull[hullSize - 2];
            Point p2 = hull[hullSize - 1];

            // Check for a counter-clockwise turn
            int orientation = (p2.x - p1.x) * (points[i].y - p1.y) - (points[i].x - p1.x) * (p2.y - p1.y);
            if (orientation > 0) {
                break; // We have a valid turn
            }
            hullSize--; // Remove the last point
        }
        hull[hullSize++] = points[i]; // Add the current point to the hull
    }

    // Step 5: Print the convex hull points
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Function to read points from user input
int readPoints(Point points[]) {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    return n;
}

// Main function
int main() {
    Point points[100]; // Allocate space for maximum 100 points
    int n = readPoints(points);
    convexHull(points, n);
    return 0;
}