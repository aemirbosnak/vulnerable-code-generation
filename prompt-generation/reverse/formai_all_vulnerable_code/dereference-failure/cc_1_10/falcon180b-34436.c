//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    double *data;
    int size;
} Vector;

Vector *vector_create() {
    Vector *v = malloc(sizeof(Vector));
    v->data = malloc(MAX_SIZE * sizeof(double));
    v->size = 0;
    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push(Vector *v, double value) {
    if (v->size >= MAX_SIZE) {
        printf("Error: Vector is full.\n");
        return;
    }
    v->data[v->size++] = value;
}

double vector_pop(Vector *v) {
    if (v->size == 0) {
        printf("Error: Vector is empty.\n");
        return 0;
    }
    return v->data[--v->size];
}

double vector_peek(Vector *v) {
    if (v->size == 0) {
        printf("Error: Vector is empty.\n");
        return 0;
    }
    return v->data[v->size - 1];
}

int main() {
    Vector *v = vector_create();
    for (int i = 0; i < 10000; i++) {
        vector_push(v, i);
    }
    for (int i = 0; i < 10000; i++) {
        double value = vector_pop(v);
        printf("%d ", value);
    }
    printf("\n");
    vector_destroy(v);
    return 0;
}