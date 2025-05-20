//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *create_vector(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * size);
    v->size = 0;
    v->capacity = size;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = value;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        printf("Error: vector is empty\n");
        exit(1);
    }
    return v->data[--v->size];
}

int vector_size(Vector *v) {
    return v->size;
}

int main() {
    Vector *v = create_vector(MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        vector_push(v, i);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", vector_pop(v));
    }

    destroy_vector(v);
    return 0;
}