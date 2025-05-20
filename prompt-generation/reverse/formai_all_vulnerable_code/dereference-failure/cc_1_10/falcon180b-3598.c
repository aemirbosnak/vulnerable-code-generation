//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vector_destroy(Vector *vec) {
    free(vec->data);
}

void vector_push(Vector *vec, int val) {
    if (vec->capacity == 0) {
        vec->capacity = 1;
        vec->data = malloc(vec->capacity * sizeof(int));
    } else if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = val;
}

int vector_pop(Vector *vec) {
    if (vec->size == 0) {
        return -1;
    }
    int val = vec->data[--vec->size];
    if (vec->size <= vec->capacity / 4) {
        vec->capacity /= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    return val;
}

int vector_get(Vector *vec, int index) {
    if (index >= vec->size || index < 0) {
        return -1;
    }
    return vec->data[index];
}

int vector_size(Vector *vec) {
    return vec->size;
}

int main() {
    Vector v;
    vector_init(&v);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        vector_push(&v, rand() % 100);
        printf("%d ", vector_get(&v, i));
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", vector_pop(&v));
    }
    printf("\n");

    printf("Size: %d\n", vector_size(&v));

    vector_destroy(&v);
    return 0;
}