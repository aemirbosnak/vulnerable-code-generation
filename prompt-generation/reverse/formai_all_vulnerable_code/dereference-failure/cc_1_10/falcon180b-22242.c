//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct shape {
    int x, y;
    int width, height;
    int color;
} Shape;

void createShape(Shape* shape, int x, int y, int width, int height, int color) {
    shape->x = x;
    shape->y = y;
    shape->width = width;
    shape->height = height;
    shape->color = color;
}

void drawShape(Shape* shape) {
    for (int i = shape->x; i < shape->x + shape->width; i++) {
        for (int j = shape->y; j < shape->y + shape->height; j++) {
            printf("%c", shape->color);
        }
    }
}

void deleteShape(Shape* shape) {
    free(shape);
}

void transformShape(Shape* shape, int x, int y) {
    shape->x += x;
    shape->y += y;
}

int main() {
    Shape* circle = malloc(sizeof(Shape));
    createShape(circle, 0, 0, 10, 10, 'O');
    drawShape(circle);

    Shape* square = malloc(sizeof(Shape));
    createShape(square, 10, 0, 10, 10, '#');
    drawShape(square);

    Shape* triangle = malloc(sizeof(Shape));
    createShape(triangle, 20, 0, 10, 10, '*');
    drawShape(triangle);

    transformShape(circle, 5, 5);
    transformShape(square, 5, 5);
    transformShape(triangle, 5, 5);

    deleteShape(circle);
    deleteShape(square);
    deleteShape(triangle);

    return 0;
}