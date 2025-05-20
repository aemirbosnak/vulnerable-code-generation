//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

void polygon_area(Polygon *polygon) {
    int i, j;
    double area = 0.0;
    Point *p1, *p2, *p3;

    for (i = 0; i < polygon->size; i++) {
        p1 = &polygon->points[i];
        p2 = &polygon->points[(i + 1) % polygon->size];

        for (j = 0; j < polygon->size; j++) {
            p3 = &polygon->points[(j + 1) % polygon->size];

            area += (p1->x * p3->y + p3->x * p2->y + p2->x * p1->y) / 2.0;
        }
    }

    printf("Polygon Area: %.2f\n", area);
}

int main() {
    int i, n;
    Point *points;
    Polygon polygon;

    printf("Enter the number of vertices (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    points = (Point *) malloc(n * sizeof(Point));

    printf("Enter the coordinates of the vertices:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    polygon.points = points;
    polygon.size = n;

    polygon_area(&polygon);

    free(points);

    return 0;
}