//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <math.h>

typedef struct point {
    int x, y;
} point;

int orientation(point a, point b, point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    point poly[n];

    // Taking input for polygon vertices
    printf("Enter the x and y coordinates of the vertices: \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &poly[i].x, &poly[i].y);
    }

    double area = 0;
    point p = poly[0];
    for (int i = 1; i < n-1; ++i) {
        point q = poly[i];
        point r = poly[i+1];
        double a = hypot(q.x - p.x, q.y - p.y);
        double b = hypot(r.x - q.x, r.y - q.y);
        double c = hypot(p.x - r.x, p.y - r.y);
        double s = (a + b + c) / 2;
        area += sqrt(s * (s - a) * (s - b) * (s - c));
    }

    printf("Area of the polygon is: %.2lf sq units\n", area);

    // Checking if a point lies inside or outside the polygon
    point test;
    printf("Enter the x and y coordinates of the test point: ");
    scanf("%d%d", &test.x, &test.y);

    int count = 0;
    point extreme = {1e9, test.y};
    for (int i = 0; i < n; ++i) {
        int j = (i+1) % n;
        if (orientation(poly[i], poly[j], test) == 0 && 
            test.x >= fmin(poly[i].x, poly[j].x) && test.x <= fmax(poly[i].x, poly[j].x) && 
            test.y >= fmin(poly[i].y, poly[j].y) && test.y <= fmax(poly[i].y, poly[j].y)) {
               printf("Point lies on the polygon boundary.\n");
               return 0;
        }
        if (orientation(poly[i], poly[j], test) != orientation(poly[i], poly[j], extreme) &&
            orientation(test, extreme, poly[i]) != orientation(test, extreme, poly[j])) {
                count++;
        }
    }
    if (count % 2 == 1) {
        printf("Point lies inside the polygon.\n");
    } else {
        printf("Point lies outside the polygon.\n");
    }

    return 0;
}