//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

void print_points(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d,%d)\n", points[i].x, points[i].y);
    }
}

int* convex_hull(Point* points, int n) {
    Point upper[n];
    Point lower[n];
    int k = 0;
    int j = n - 1;

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_product(upper[k - 1], points[i], upper[k]) <= 0) {
            k--;
        }
        upper[k++] = points[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 && cross_product(lower[j + 1], points[i], lower[j]) >= 0) {
            j--;
        }
        lower[j++] = points[i];
    }

    int* hull = malloc(2 * n - 2 * sizeof(int));
    int m = 0;

    for (int i = 0; i < n; i++) {
        while (cross_product(lower[j - 1], upper[k - 1], points[i]) <= 0) {
            j--;
        }
        hull[m++] = lower[j - 1].x;
        hull[m++] = lower[j - 1].y;
    }

    free(lower);
    free(upper);

    return hull;
}

int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    Point points[] = {{0,0}, {1,0}, {1,1}, {0,1}};
    int n = sizeof(points) / sizeof(points[0]);

    int* hull = convex_hull(points, n);

    printf("Convex hull:\n");
    for (int i = 0; i < 2 * n - 2; i += 2) {
        printf("(%d,%d)\n", hull[i], hull[i + 1]);
    }

    free(hull);

    return 0;
}