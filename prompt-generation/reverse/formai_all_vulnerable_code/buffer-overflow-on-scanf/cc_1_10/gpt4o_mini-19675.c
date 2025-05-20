//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

Point points[100];
int n;

void readPoints() {
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : (val > 0) ? 1 : 2;
}

void convexHull() {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points\n");
        return;
    }

    Point hull[100];
    int hullIndex = 0;

    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }

    int p = l, q;
    do {
        hull[hullIndex++] = points[p];
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;

    } while (p != l);

    printf("Convex hull points:\n");
    for (int i = 0; i < hullIndex; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    readPoints();
    convexHull();
    return 0;
}