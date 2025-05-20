//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Point {
    double x;
    double y;
};

struct Shape {
    int type;
    struct Point *points;
    int num_points;
};

void draw_shape(struct Shape *shape, int color) {
    switch (shape->type) {
        case 0: // Circle
            printf("Drawing Circle with color %d\n", color);
            break;
        case 1: // Square
            printf("Drawing Square with color %d\n", color);
            break;
        case 2: // Triangle
            printf("Drawing Triangle with color %d\n", color);
            break;
        default:
            printf("Invalid Shape Type\n");
            break;
    }
}

int main() {
    struct Shape circle = {0, NULL, 0};
    struct Shape square = {1, NULL, 0};
    struct Shape triangle = {2, NULL, 0};

    circle.points = (struct Point *)malloc(3 * sizeof(struct Point));
    circle.num_points = 3;
    circle.points[0].x = 0;
    circle.points[0].y = 0;
    circle.points[1].x = cos(PI / 3);
    circle.points[1].y = sin(PI / 3);
    circle.points[2].x = cos(2 * PI / 3);
    circle.points[2].y = sin(2 * PI / 3);

    square.points = (struct Point *)malloc(4 * sizeof(struct Point));
    square.num_points = 4;
    square.points[0].x = 0;
    square.points[0].y = 0;
    square.points[1].x = 10;
    square.points[1].y = 0;
    square.points[2].x = 10;
    square.points[2].y = 10;
    square.points[3].x = 0;
    square.points[3].y = 10;

    triangle.points = (struct Point *)malloc(3 * sizeof(struct Point));
    triangle.num_points = 3;
    triangle.points[0].x = 0;
    triangle.points[0].y = 10;
    triangle.points[1].x = 10;
    triangle.points[1].y = 0;
    triangle.points[2].x = 20;
    triangle.points[2].y = 10;

    draw_shape(&circle, 1);
    draw_shape(&square, 2);
    draw_shape(&triangle, 3);

    return 0;
}