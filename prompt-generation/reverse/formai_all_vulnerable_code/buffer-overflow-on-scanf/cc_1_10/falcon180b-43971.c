//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point;

Point points[MAX_POINTS];

void read_points() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void convex_hull(int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_product(points[k - 2], points[k - 1], points[i]) <= 0)
            k--;
        points[k++] = points[i];
    }
    n = k;
    for (int i = n - 2; i >= 0; i--) {
        points[i].x = points[i + 1].x;
        points[i].y = points[i + 1].y;
    }
    n--;
}

int cross_product(Point p1, Point p2, Point p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

void print_points(int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

int main() {
    read_points();
    convex_hull(MAX_POINTS);
    print_points(MAX_POINTS);

    return 0;
}