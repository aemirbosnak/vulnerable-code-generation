//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

int comparePoints(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x != p2->x) {
        return (p1->x > p2->x) ? 1 : -1;
    }
    return (p1->y > p2->y) ? 1 : -1;
}

double crossProduct(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

void computeConvexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull is not possible with less than 3 points.\n");
        return;
    }

    // Sort points lexicographically (by x, then by y)
    qsort(points, n, sizeof(Point), comparePoints);

    // Allocate space for the convex hull
    Point *hull = (Point *)malloc(sizeof(Point) * (n + 1));
    int hullSize = 0;

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (hullSize >= 2 && crossProduct(hull[hullSize - 2], hull[hullSize - 1], points[i]) <= 0) {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    // Build upper hull
    int lowerHullSize = hullSize + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (hullSize >= lowerHullSize && crossProduct(hull[hullSize - 2], hull[hullSize - 1], points[i]) <= 0) {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    // Print the convex hull
    printf("Convex hull points:\n");
    for (int i = 0; i < hullSize - 1; i++) {
        printf("(%.2f, %.2f)\n", hull[i].x, hull[i].y);
    }

    free(hull);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(sizeof(Point) * n);
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    computeConvexHull(points, n);

    free(points);
    return 0;
}