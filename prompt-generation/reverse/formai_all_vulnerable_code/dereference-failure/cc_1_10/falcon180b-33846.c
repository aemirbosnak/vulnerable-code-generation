//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

Point create_point(int x, int y) {
    Point p = {.x = x,.y = y};
    return p;
}

Polygon create_polygon(int num_points) {
    Polygon p = {.points = (Point *)malloc(num_points * sizeof(Point)),.num_points = num_points};
    return p;
}

void add_point_to_polygon(Polygon *polygon, int x, int y) {
    Point point = create_point(x, y);
    polygon->points[polygon->num_points - 1] = point;
}

int is_convex(Polygon *polygon) {
    int num_points = polygon->num_points;
    int sum_angles = 0;
    for (int i = 0; i < num_points; i++) {
        int angle = 0;
        Point a = polygon->points[i];
        Point b = polygon->points[(i + 1) % num_points];
        Point c = polygon->points[(i + 2) % num_points];
        angle = (int)(atan2(b.y - a.y, b.x - a.x) * 180 / M_PI);
        sum_angles += angle;
    }
    if (sum_angles == 360) {
        return true;
    } else {
        return false;
    }
}

int main() {
    srand(time(NULL));
    int num_points = rand() % 10 + 3;
    Polygon polygon = create_polygon(num_points);
    for (int i = 0; i < num_points; i++) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        add_point_to_polygon(&polygon, x, y);
    }
    if (is_convex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is not convex.\n");
    }
    return 0;
}