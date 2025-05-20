//Falcon-180B DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define CAPACITY_INCREMENT 10

typedef struct {
    void **data;
    size_t capacity;
    size_t size;
} Vector;

Vector *vector_create() {
    Vector *vector = malloc(sizeof(Vector));
    vector->data = malloc(INITIAL_CAPACITY * sizeof(void *));
    vector->capacity = INITIAL_CAPACITY;
    vector->size = 0;
    return vector;
}

void vector_destroy(Vector *vector) {
    free(vector->data);
    free(vector);
}

void vector_push(Vector *vector, void *element) {
    if (vector->size >= vector->capacity) {
        vector->capacity += CAPACITY_INCREMENT;
        vector->data = realloc(vector->data, vector->capacity * sizeof(void *));
    }
    vector->data[vector->size++] = element;
}

void *vector_pop(Vector *vector) {
    if (vector->size == 0) {
        return NULL;
    }
    void *element = vector->data[--vector->size];
    return element;
}

void vector_clear(Vector *vector) {
    vector->size = 0;
}

size_t vector_size(Vector *vector) {
    return vector->size;
}

int main() {
    Vector *vector = vector_create();

    vector_push(vector, "Hello");
    vector_push(vector, "World");
    vector_push(vector, 42);

    printf("Vector size: %zu\n", vector_size(vector));

    void *element = vector_pop(vector);
    printf("Popped element: %s\n", (char *) element);

    vector_clear(vector);
    printf("Vector size after clear: %zu\n", vector_size(vector));

    vector_destroy(vector);
    return 0;
}