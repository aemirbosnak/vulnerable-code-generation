//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

void initialize_polygon(Polygon *polygon, int size) {
    polygon->points = (Point *)malloc(size * sizeof(Point));
    polygon->size = size;
}

void generate_random_polygon(Polygon *polygon) {
    srand(time(NULL));
    for (int i = 0; i < polygon->size; i++) {
        polygon->points[i].x = rand() % 100;
        polygon->points[i].y = rand() % 100;
    }
}

int is_inside_polygon(Point point, Polygon polygon) {
    int inside = 0;
    for (int i = 0; i < polygon.size; i++) {
        Point p1 = polygon.points[i];
        Point p2 = polygon.points[(i + 1) % polygon.size];
        if ((p1.y > point.y)!= (p2.y > point.y) &&
            (point.x < (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x))
            inside =!inside;
    }
    return inside;
}

int main() {
    Polygon polygon;
    initialize_polygon(&polygon, 10);
    generate_random_polygon(&polygon);

    Point point;
    point.x = 50;
    point.y = 50;

    if (is_inside_polygon(point, polygon)) {
        printf("Point is inside polygon\n");
    } else {
        printf("Point is outside polygon\n");
    }

    return 0;
}