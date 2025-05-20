//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void polygon_area(Polygon *polygon) {
    int i, j;
    double area = 0.0;
    Point *p1, *p2;

    for (i = 0, p1 = polygon->points; i < polygon->num_points; i++, p1++) {
        for (j = i + 1, p2 = polygon->points; j < polygon->num_points; j++, p2++) {
            area += ((p2->x - p1->x) * (p1->y - p2->y)) / 2.0;
        }
    }

    printf("Polygon area: %.2lf\n", area);
}

int main() {
    int i, j, num_points;
    Point points[MAX_SIZE];
    Polygon polygon;

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    for (i = 0; i < num_points; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    polygon.points = points;
    polygon.num_points = num_points;

    polygon_area(&polygon);

    return 0;
}