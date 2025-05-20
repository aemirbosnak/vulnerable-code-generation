//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    int type; // 0 = Triangle, 1 = Square
    Point points[4]; // Max 4 points for square
    int point_count; // Number of defined points
} Shape;

void initialize_shape(Shape* shape, int type) {
    shape->type = type;
    shape->point_count = (type == 0) ? 3 : 4; // Triangle has 3 points, Square has 4
}

void input_shape(Shape* shape) {
    printf("Enter the coordinates for the shape:\n");
    for (int i = 0; i < shape->point_count; i++) {
        printf("Point %d (x y): ", i + 1);
        scanf("%f %f", &shape->points[i].x, &shape->points[i].y);
    }
}

void print_shape(const Shape* shape) {
    printf("Shape Points:\n");
    for (int i = 0; i < shape->point_count; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, shape->points[i].x, shape->points[i].y);
    }
}

void translate_shape(Shape* shape, float tx, float ty) {
    for (int i = 0; i < shape->point_count; i++) {
        shape->points[i].x += tx;
        shape->points[i].y += ty;
    }
}

void scale_shape(Shape* shape, float sx, float sy) {
    for (int i = 0; i < shape->point_count; i++) {
        shape->points[i].x *= sx;
        shape->points[i].y *= sy;
    }
}

void rotate_shape(Shape* shape, float angle) {
    float rad = angle * (PI / 180); // Convert to radians
    float cos_angle = cos(rad);
    float sin_angle = sin(rad);

    for (int i = 0; i < shape->point_count; i++) {
        float x_new = shape->points[i].x * cos_angle - shape->points[i].y * sin_angle;
        float y_new = shape->points[i].x * sin_angle + shape->points[i].y * cos_angle;
        shape->points[i].x = x_new;
        shape->points[i].y = y_new;
    }
}

int main() {
    Shape shape;
    int choice;

    printf("Choose a shape:\n1. Triangle\n2. Square\nChoice: ");
    scanf("%d", &choice);
    initialize_shape(&shape, choice - 1);

    input_shape(&shape);
    print_shape(&shape);

    float tx, ty, sx, sy, angle;

    printf("Enter translation values (tx ty): ");
    scanf("%f %f", &tx, &ty);
    translate_shape(&shape, tx, ty);
    printf("After translation:\n");
    print_shape(&shape);

    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);
    scale_shape(&shape, sx, sy);
    printf("After scaling:\n");
    print_shape(&shape);

    printf("Enter rotation angle (degrees): ");
    scanf("%f", &angle);
    rotate_shape(&shape, angle);
    printf("After rotation:\n");
    print_shape(&shape);

    return 0;
}