//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SHAPES 10
#define MAX_VERTICES 100

typedef struct {
    char name[20];
    int num_vertices;
    float *vertices;
} Shape;

void read_shape(Shape *shape, FILE *file) {
    fscanf(file, "%s", shape->name);
    shape->num_vertices = 0;
    shape->vertices = malloc(MAX_VERTICES * sizeof(float) * 2);

    while (shape->num_vertices < MAX_VERTICES && !feof(file)) {
        fscanf(file, "%d", &shape->num_vertices);
        if (shape->num_vertices > 0) {
            for (int i = 0; i < 2 * shape->num_vertices; i += 2) {
                fscanf(file, "%f %f", &shape->vertices[i], &shape->vertices[i + 1]);
            }
        }
    }
}

void print_shape(Shape shape) {
    printf("%s:\n", shape.name);
    for (int i = 0; i < shape.num_vertices; i++) {
        printf("(%f, %f)\n", shape.vertices[i * 2], shape.vertices[i * 2 + 1]);
    }
}

int main() {
    Shape shapes[MAX_SHAPES];
    FILE *file = fopen("shape.txt", "r");
    int num_shapes = 0;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (num_shapes < MAX_SHAPES && !feof(file)) {
        Shape shape;
        read_shape(&shape, file);
        shapes[num_shapes++] = shape;
    }

    fclose(file);

    for (int i = 0; i < num_shapes; i++) {
        print_shape(shapes[i]);
    }

    for (int i = 0; i < num_shapes; i++) {
        free(shapes[i].vertices);
    }

    return 0;
}