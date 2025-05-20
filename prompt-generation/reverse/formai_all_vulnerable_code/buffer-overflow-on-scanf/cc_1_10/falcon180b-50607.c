//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point;

void init(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
}

void print_points(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

int convex_hull(Point points[], int n) {
    int hull_size = 0;
    int lower[MAX_POINTS], upper[MAX_POINTS];
    Point hull[MAX_POINTS];

    for (int i = 0; i < n; i++) {
        lower[i] = upper[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        while (lower[j] > lower[i]) {
            j = (j + 1) % n;
        }

        while (upper[j] < upper[i]) {
            j = (j - 1 + n) % n;
        }

        if (lower[j] <= lower[i] && upper[j] >= upper[i]) {
            lower[i] = lower[j];
            upper[i] = upper[j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (lower[i] == i && upper[i] == i) {
            hull[hull_size++] = points[i];
        }
    }

    return hull_size;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[MAX_POINTS];
    init(points, n);

    int hull_size = convex_hull(points, n);

    printf("Convex hull has %d points:\n", hull_size);
    print_points(points, hull_size);

    return 0;
}