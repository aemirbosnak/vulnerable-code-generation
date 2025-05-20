//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct {
    int x;
    int y;
} Point;

void readPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter point %d coordinates: ", i + 1);
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
    int hullSize = 0;
    Point hull[MAX];

    // Initialize the hull array with the first point
    hull[0] = points[0];
    hullSize = 1;

    // Add the remaining points to the hull
    for (i = 1; i < n; i++) {
        int flag = 0;
        for (j = 0; j < hullSize; j++) {
            if (ccw(hull[j], points[i], hull[(j + 1) % hullSize]) > 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            hull[(hullSize + 1) % MAX] = points[i];
            hullSize++;
        }
    }

    // Print the convex hull
    printf("Convex hull: ");
    for (i = 0; i < hullSize; i++) {
        printf("(%d, %d) ", hull[i].x, hull[i].y);
    }
    printf("\n");
}

int ccw(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (p.x - q.x);
    if (val == 0)
        return 0;
    else if (val > 0)
        return 1;
    else
        return -1;
}

int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    Point points[MAX];
    readPoints(points, n);

    convexHull(points, n);

    return 0;
}