//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/* The following C program implements a statistical algorithm to compute the area of a convex polygon. This is accomplished through an application of Green's theorem, a mathematical tool that relates lines integrals to surface integrals. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double crossProduct(struct Point p1, struct Point p2) {
    return (p1.x*p2.y - p1.y*p2.x);
}

double areaConvexPolygon(struct Point vertices[], int numVertices) {
    double area = 0.0;
    double signedArea = 0.0;
    struct Point current, next;
    int i;
 
    for (i = 0; i < numVertices; i++) {
        current = vertices[i];
        next = vertices[(i+1)%numVertices];
        signedArea += crossProduct(current, next);
    }
    area = fabs(signedArea)/2.0;
    return area;
}

int main() {
    int n, i;
    double x, y;
    struct Point vertices[100];

    printf("\nEnter the number of vertices in the convex polygon: ");
    scanf("%d", &n);

    printf("\nEnter the coordinates of the vertices in order: ");

    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        vertices[i].x = x;
        vertices[i].y = y;
    }

    printf("\nThe area of the convex polygon is: %lf\n", areaConvexPolygon(vertices, n));

    return 0;
}