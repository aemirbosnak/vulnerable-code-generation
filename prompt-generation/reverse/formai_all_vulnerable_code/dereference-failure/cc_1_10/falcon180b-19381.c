//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v, int capacity) {
    v->data = malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_pop(Vector *v) {
    return v->data[--v->size];
}

int vector_size(Vector *v) {
    return v->size;
}

int vector_capacity(Vector *v) {
    return v->capacity;
}

void vector_destroy(Vector *v) {
    free(v->data);
}

int main() {
    Vector v;
    vector_init(&v, 10);

    for (int i = 0; i < 20; i++) {
        vector_push(&v, i);
        printf("Size: %d, Capacity: %d\n", vector_size(&v), vector_capacity(&v));
    }

    for (int i = 0; i < 20; i++) {
        printf("Popped: %d\n", vector_pop(&v));
    }

    vector_destroy(&v);

    return 0;
}