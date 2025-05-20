//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *vector) {
    vector->data = (int *) malloc(MAX_SIZE * sizeof(int));
    vector->size = 0;
    vector->capacity = MAX_SIZE;
}

void vector_free(Vector *vector) {
    free(vector->data);
}

void vector_push(Vector *vector, int value) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = (int *) realloc(vector->data, vector->capacity * sizeof(int));
    }
    vector->data[vector->size++] = value;
}

void vector_pop(Vector *vector) {
    if (vector->size > 0) {
        vector->size--;
    }
}

void vector_print(Vector *vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}

int main() {
    Vector vector;
    vector_init(&vector);

    vector_push(&vector, 1);
    vector_push(&vector, 2);
    vector_push(&vector, 3);
    vector_push(&vector, 4);
    vector_push(&vector, 5);

    vector_print(&vector);

    vector_pop(&vector);
    vector_pop(&vector);

    vector_print(&vector);

    vector_free(&vector);

    return 0;
}