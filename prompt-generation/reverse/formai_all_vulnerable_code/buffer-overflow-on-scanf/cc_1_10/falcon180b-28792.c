//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MIN_POINTS 3

typedef struct {
    int x;
    int y;
} Point;

void readPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter x and y coordinates for point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void printPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void convexHull(Point points[], int n) {
    int i, j, k;
    Point hull[MAX_POINTS];
    int hullSize = 0;

    // Initialize hull with the first three points
    for (i = 0; i < 3; i++) {
        hull[i] = points[i];
        hullSize = i + 1;
    }

    // Build the hull iteratively
    for (i = 3; i < n; i++) {
        // Remove the last point from the hull
        j = hullSize - 1;
        hull[j] = points[i];

        // Rebuild the hull
        for (k = 0; k < j; k++) {
            while (ccw(hull[k], hull[j], points[i]) <= 0) {
                j--;
                hull[j] = hull[j + 1];
            }
        }
        hullSize = j + 1;
    }

    // Print the hull
    printf("Convex hull:\n");
    for (i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int ccw(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    else if (val > 0)
        return 1;
    else
        return -1;
}

int main() {
    int n;
    Point points[MAX_POINTS];

    // Read the number of points
    printf("Enter the number of points (at least %d): ", MIN_POINTS);
    scanf("%d", &n);

    // Read the points
    readPoints(points, n);

    // Calculate the convex hull
    convexHull(points, n);

    return 0;
}