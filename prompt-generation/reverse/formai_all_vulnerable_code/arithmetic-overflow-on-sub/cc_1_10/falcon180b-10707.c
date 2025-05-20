//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

void print_points(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void read_points(Point points[], int n) {
    printf("Enter %d points:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void convex_hull(Point points[], int n) {
    int upper = 0, lower = 0;
    Point stack[MAX_POINTS];
    stack[0] = points[0];
    for (int i = 1; i < n; i++) {
        while (cross_product(stack[upper - 1], points[i], stack[upper]) <= 0) {
            upper--;
        }
        stack[++upper] = points[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        while (cross_product(stack[lower + 1], points[i], stack[lower]) <= 0) {
            lower++;
        }
        stack[--lower] = points[i];
    }
    printf("Convex hull:\n");
    for (int i = lower; i <= upper; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }
}

int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point points[MAX_POINTS];
    read_points(points, n);
    convex_hull(points, n);
    return 0;
}