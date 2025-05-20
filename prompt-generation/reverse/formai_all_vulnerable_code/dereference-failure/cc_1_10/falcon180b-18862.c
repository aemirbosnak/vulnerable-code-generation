//Falcon-180B DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

typedef struct {
    Polygon *polygons;
    int size;
} Shape;

void create_polygon(Polygon *polygon, int size) {
    Point *points = malloc(size * sizeof(Point));
    for (int i = 0; i < size; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    polygon->points = points;
    polygon->size = size;
}

void create_shape(Shape *shape, int size) {
    Polygon *polygons = malloc(size * sizeof(Polygon));
    for (int i = 0; i < size; i++) {
        create_polygon(&polygons[i], rand() % 10 + 3);
    }
    shape->polygons = polygons;
    shape->size = size;
}

void draw_shape(Shape *shape) {
    for (int i = 0; i < shape->size; i++) {
        for (int j = 0; j < shape->polygons[i].size; j++) {
            printf("(%d,%d) ", shape->polygons[i].points[j].x, shape->polygons[i].points[j].y);
        }
        printf("\n");
    }
}

void main() {
    Shape shape;
    create_shape(&shape, 5);
    draw_shape(&shape);
}