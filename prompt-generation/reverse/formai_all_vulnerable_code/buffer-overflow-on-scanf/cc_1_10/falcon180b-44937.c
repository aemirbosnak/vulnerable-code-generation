//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 100
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int num_points;
    Point points[MAX_POINTS];
} Polygon;

void read_points(Polygon *polygon) {
    char input[50];
    printf("Enter the number of points in the polygon:\n");
    scanf("%d", &polygon->num_points);

    for (int i = 0; i < polygon->num_points; i++) {
        printf("Enter the coordinates of point %d:\n", i+1);
        scanf("%lf %lf", &polygon->points[i].x, &polygon->points[i].y);
    }
}

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double area(Polygon *polygon) {
    double area = 0;
    int num_points = polygon->num_points;

    for (int i = 0; i < num_points; i++) {
        int j = (i+1) % num_points;
        area += distance(polygon->points[i], polygon->points[j]) * sin(PI / num_points);
    }

    return area / 2;
}

int main() {
    Polygon polygon;
    read_points(&polygon);

    printf("The area of the polygon is %.2lf\n", area(&polygon));

    return 0;
}