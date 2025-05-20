//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

Point* points = NULL;
int pointCount = 0;

int compare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->x != p2->x) {
        return (p1->x > p2->x) ? 1 : -1;
    } else {
        return (p1->y > p2->y) ? 1 : -1;
    }
}

double crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

void convexHull(Point* points, int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    qsort(points, n, sizeof(Point), compare);

    Point* hull = malloc(2 * n * sizeof(Point));
    
    int hullCount = 0;

    for (int i = 0; i < n; i++) {
        while (hullCount >= 2 && crossProduct(hull[hullCount - 2], hull[hullCount - 1], points[i]) <= 0) {
            hullCount--;
        }
        hull[hullCount++] = points[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        while (hullCount >= 2 && crossProduct(hull[hullCount - 2], hull[hullCount - 1], points[i]) <= 0) {
            hullCount--;
        }
        hull[hullCount++] = points[i];
    }

    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullCount - 1; i++) { // hullCount - 1 to avoid printing the last repeated point
        printf("(%lf, %lf)\n", hull[i].x, hull[i].y);
    }

    free(hull);
}

void readPoints() {
    printf("Enter the number of points: ");
    scanf("%d", &pointCount);

    if (pointCount < 3) {
        printf("At least 3 points are needed to form a convex hull.\n");
        exit(1);
    }

    points = malloc(pointCount * sizeof(Point));

    for (int i = 0; i < pointCount; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

int main() {
    readPoints();
    convexHull(points, pointCount);
    free(points);
    return 0;
}