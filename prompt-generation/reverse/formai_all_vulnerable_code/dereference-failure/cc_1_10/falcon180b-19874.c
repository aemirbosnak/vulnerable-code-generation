//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Vector;

Vector *vector_create(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push(Vector *v, int x) {
    if (v->size == v->data[0]) {
        v->size *= 2;
        v->data = (int *)realloc(v->data, v->size * sizeof(int));
    }
    v->data[v->size++] = x;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        printf("Error: Vector is empty\n");
        exit(1);
    }
    return v->data[--v->size];
}

int vector_peek(Vector *v) {
    if (v->size == 0) {
        printf("Error: Vector is empty\n");
        exit(1);
    }
    return v->data[v->size - 1];
}

int vector_size(Vector *v) {
    return v->size;
}

int main() {
    Vector *v = vector_create(10);
    vector_push(v, 1);
    vector_push(v, 2);
    vector_push(v, 3);
    printf("Size of vector: %d\n", vector_size(v));
    printf("Peek: %d\n", vector_peek(v));
    printf("Pop: %d\n", vector_pop(v));
    printf("Size of vector: %d\n", vector_size(v));
    vector_destroy(v);
    return 0;
}