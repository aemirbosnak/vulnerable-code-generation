//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_EDGES 2000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
} Edge;

Edge edges[MAX_EDGES];
int num_edges = 0;

void add_edge(int x1, int y1, int x2, int y2) {
    Point p1 = {x1, y1};
    Point p2 = {x2, y2};
    edges[num_edges++] = (Edge) {p1, p2};
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        Edge e = edges[i];
        printf("(%d,%d) -- (%d,%d)\n", e.p1.x, e.p1.y, e.p2.x, e.p2.y);
    }
}

void convex_hull(int num_points, Point points[]) {
    if (num_points < 3) {
        printf("Need at least 3 points for convex hull.\n");
        return;
    }

    int n = 0;
    Point hull[MAX_POINTS];
    hull[n++] = points[0];

    for (int i = 1; i < num_points; i++) {
        while (n >= 2 && ccw(hull[n-2], hull[n-1], points[i]) <= 0) {
            n--;
        }
        hull[n++] = points[i];
    }

    for (int i = n-2; i >= 0; i--) {
        add_edge(hull[i].x, hull[i].y, hull[i+1].x, hull[i+1].y);
    }

    print_edges();
}

int ccw(Point a, Point b, Point c) {
    double ab = b.x - a.x;
    double bc = c.x - b.x;
    double ca = a.x - c.x;
    double cb = c.y - b.y;
    double abc = ab * bc + bc * ca + ca * ab;

    if (abc == 0) {
        return 0;
    }

    return (abc > 0)? 1 : -1;
}

int main() {
    int num_points;
    printf("Enter number of points: ");
    scanf("%d", &num_points);

    Point points[MAX_POINTS];
    for (int i = 0; i < num_points; i++) {
        printf("Enter point %d (x y): ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convex_hull(num_points, points);

    return 0;
}