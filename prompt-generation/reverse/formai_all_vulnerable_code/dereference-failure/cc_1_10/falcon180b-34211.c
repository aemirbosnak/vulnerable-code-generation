//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHAPE_WIDTH 10
#define SHAPE_HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Shape;

void init_shape(Shape *shape, int num_points) {
    shape->points = (Point *)malloc(num_points * sizeof(Point));
    shape->num_points = num_points;
}

void set_point(Shape *shape, int index, int x, int y) {
    shape->points[index].x = x;
    shape->points[index].y = y;
}

void draw_shape(Shape *shape) {
    for (int i = 0; i < shape->num_points; i++) {
        printf("(%d,%d) ", shape->points[i].x, shape->points[i].y);
    }
    printf("\n");
}

void rotate_shape(Shape *shape, int num_rotations) {
    for (int i = 0; i < num_rotations; i++) {
        Point *temp = shape->points;
        shape->points = (Point *)malloc(shape->num_points * sizeof(Point));
        for (int j = 0; j < shape->num_points; j++) {
            set_point(shape, j, temp[j].y, -temp[j].x);
        }
        free(temp);
    }
}

void shift_shape(Shape *shape, int x_offset, int y_offset) {
    for (int i = 0; i < shape->num_points; i++) {
        shape->points[i].x += x_offset;
        shape->points[i].y += y_offset;
    }
}

int main() {
    srand(time(NULL));
    Shape shape;
    init_shape(&shape, SHAPE_WIDTH * SHAPE_HEIGHT);
    for (int i = 0; i < SHAPE_WIDTH * SHAPE_HEIGHT; i++) {
        int x = rand() % SHAPE_WIDTH;
        int y = rand() % SHAPE_HEIGHT;
        set_point(&shape, i, x, y);
    }
    draw_shape(&shape);
    printf("Rotating shape...\n");
    rotate_shape(&shape, 90);
    draw_shape(&shape);
    printf("Shifting shape...\n");
    shift_shape(&shape, 50, 50);
    draw_shape(&shape);
    return 0;
}