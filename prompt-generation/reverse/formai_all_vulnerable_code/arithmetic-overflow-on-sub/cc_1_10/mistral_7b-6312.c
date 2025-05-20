//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI M_PI

typedef struct {
    double x, y;
} point;

void print_shape(int sides, point *vertices, int num_vertices);
point shift_vertex(point p, double angle);

int main() {
    int sides, i, num_vertices;

    printf("Enter the number of sides for the shape: ");
    scanf("%d", &sides);

    num_vertices = 3 + (sides - 2) * 2;
    point *vertices = malloc(num_vertices * sizeof(point));

    vertices[0].x = 0.0;
    vertices[0].y = 0.0;

    for (i = 1; i < num_vertices; i++) {
        vertices[i] = (i % 2 == 0) ?
                      shift_vertex(vertices[i - 1], 2 * PI / sides) :
                      shift_vertex(vertices[i - 1], -2 * PI / sides);
    }

    print_shape(sides, vertices, num_vertices);

    free(vertices);

    return 0;
}

void print_shape(int sides, point *vertices, int num_vertices) {
    int i;

    printf("\nVertices:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("(%lf, %lf)\n", vertices[i].x, vertices[i].y);
    }

    printf("\nEdges:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("(%d, %d) - (%d, %d)\n", i, i + 1 < num_vertices ? i + 1 : 0, i, i + 1);
    }

    if (sides > 3) {
        print_shape(sides - 1, vertices, num_vertices);
    }
}

point shift_vertex(point p, double angle) {
    double x = p.x * cos(angle) - p.y * sin(angle);
    double y = p.x * sin(angle) + p.y * cos(angle);

    p.x = x;
    p.y = y;

    return p;
}