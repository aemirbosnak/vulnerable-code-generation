//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Shape;

void generate_random_shape(Shape *shape) {
    srand(time(NULL));
    shape->num_points = rand() % 10 + 3;
    shape->points = malloc(shape->num_points * sizeof(Point));
    for (int i = 0; i < shape->num_points; i++) {
        shape->points[i].x = rand() % 100;
        shape->points[i].y = rand() % 100;
    }
}

void print_shape(Shape *shape) {
    printf("Shape with %d points:\n", shape->num_points);
    for (int i = 0; i < shape->num_points; i++) {
        printf("(%d, %d)\n", shape->points[i].x, shape->points[i].y);
    }
}

void free_shape(Shape *shape) {
    free(shape->points);
}

int main() {
    Shape shape1, shape2;
    generate_random_shape(&shape1);
    generate_random_shape(&shape2);

    printf("Shape 1:\n");
    print_shape(&shape1);

    printf("Shape 2:\n");
    print_shape(&shape2);

    if (shape1.num_points == shape2.num_points) {
        int match_count = 0;
        for (int i = 0; i < shape1.num_points; i++) {
            for (int j = 0; j < shape2.num_points; j++) {
                if (shape1.points[i].x == shape2.points[j].x && shape1.points[i].y == shape2.points[j].y) {
                    match_count++;
                    break;
                }
            }
        }
        if (match_count == shape1.num_points) {
            printf("Shapes match!\n");
        } else {
            printf("Shapes do not match.\n");
        }
    } else {
        printf("Shapes have different number of points.\n");
    }

    free_shape(&shape1);
    free_shape(&shape2);

    return 0;
}