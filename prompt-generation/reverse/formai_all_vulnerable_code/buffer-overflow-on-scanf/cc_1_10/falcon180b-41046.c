//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

void init(int n, Point p[]) {
    for (int i = 0; i < n; i++) {
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}

void print(int n, Point p[]) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", p[i].x, p[i].y);
    }
}

void convexHull(int n, Point p[], Point q[]) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m >= 2 && crossProduct(p[m - 1], p[m], p[i]) <= 0) {
            m--;
        }
        p[m++] = p[i];
    }
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        while (j >= 0 && crossProduct(p[j], p[j + 1], p[i]) <= 0) {
            j--;
        }
        q[j++] = p[i];
    }
}

int crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point p[n], q[n];
    init(n, p);
    convexHull(n, p, q);
    printf("Convex Hull:\n");
    print(n, p);
    printf("\n");
    print(n, q);
    return 0;
}