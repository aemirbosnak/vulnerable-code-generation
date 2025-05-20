//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x, y;
} Point;

int compare_points(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x < p2->x) {
        return -1;
    } else if (p1->x > p2->x) {
        return 1;
    } else {
        return 0;
    }
}

int convex_hull(Point points[], int n) {
    int i, j, k;
    int hull_size = 0;
    Point hull[MAX_POINTS];
    Point *sorted_points = malloc(n * sizeof(Point));
    for (i = 0; i < n; i++) {
        sorted_points[i] = points[i];
    }
    qsort(sorted_points, n, sizeof(Point), compare_points);
    for (i = 0; i < n; i++) {
        while (hull_size >= 2 && (hull[hull_size - 1].x - hull[hull_size - 2].x) * (sorted_points[i].y - hull[hull_size - 2].y) <= (hull[hull_size - 1].y - hull[hull_size - 2].y) * (sorted_points[i].x - hull[hull_size - 2].x)) {
            hull_size--;
        }
        hull[hull_size++] = sorted_points[i];
    }
    for (i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
    free(sorted_points);
    return hull_size;
}

int main() {
    int n;
    scanf("%d", &n);
    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    int hull_size = convex_hull(points, n);
    printf("The convex hull has %d points.\n", hull_size);
    return 0;
}