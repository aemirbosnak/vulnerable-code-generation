//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int size;
} Polygon;

void initPolygon(Polygon *p) {
    p->size = 0;
}

void addPoint(Polygon *p, double x, double y) {
    if (p->size < MAX_POINTS) {
        p->points[p->size].x = x;
        p->points[p->size].y = y;
        p->size++;
    } else {
        printf("Polygon can only have a maximum of %d points.\n", MAX_POINTS);
    }
}

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perimeter(Polygon *p) {
    double total = 0.0;
    for (int i = 0; i < p->size; i++) {
        total += distance(p->points[i], p->points[(i + 1) % p->size]);
    }
    return total;
}

double area(Polygon *p) {
    double total = 0.0;
    for (int i = 0; i < p->size; i++) {
        total += (p->points[i].x * p->points[(i + 1) % p->size].y) - 
                  (p->points[i].y * p->points[(i + 1) % p->size].x);
    }
    return fabs(total) / 2.0;
}

void printPolygon(Polygon *p) {
    printf("Polygon with %d points:\n", p->size);
    for (int i = 0; i < p->size; i++) {
        printf("Point %d: (%f, %f)\n", i + 1, p->points[i].x, p->points[i].y);
    }
}

void freePolygon(Polygon *p) {
    // Currently, nothing is dynamically allocated, but could be used for cleanup.
    p->size = 0;
}

int main() {
    Polygon polygon;
    initPolygon(&polygon);

    int n;
    printf("Enter the number of points in the polygon (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n > MAX_POINTS) {
        printf("Exceeded maximum number of points (%d). Exiting.\n", MAX_POINTS);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        double x, y;
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        addPoint(&polygon, x, y);
    }

    printPolygon(&polygon);

    double perim = perimeter(&polygon);
    printf("Perimeter of the polygon: %f\n", perim);

    double areaVal = area(&polygon);
    printf("Area of the polygon: %f\n", areaVal);

    freePolygon(&polygon);
    return EXIT_SUCCESS;
}