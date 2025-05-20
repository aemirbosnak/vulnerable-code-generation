//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int *arr;
    int capacity;
    int size;
} Vector;

void vector_init(Vector *vec, int capacity) {
    vec->arr = (int *) malloc(capacity * sizeof(int));
    vec->capacity = capacity;
    vec->size = 0;
}

void vector_push_back(Vector *vec, int value) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->arr = (int *) realloc(vec->arr, vec->capacity * sizeof(int));
    }
    vec->arr[vec->size++] = value;
}

int vector_pop_back(Vector *vec) {
    if (vec->size == 0) {
        return -1;
    }
    return vec->arr[--vec->size];
}

int vector_size(Vector *vec) {
    return vec->size;
}

void vector_destroy(Vector *vec) {
    free(vec->arr);
}

int main() {
    srand(time(NULL));

    Vector vec;
    vector_init(&vec, 10);

    for (int i = 0; i < 100; i++) {
        int choice = rand() % 3;
        switch (choice) {
            case 0:
                vector_push_back(&vec, rand() % 100);
                break;
            case 1:
                printf("Popped: %d\n", vector_pop_back(&vec));
                break;
            case 2:
                printf("Size: %d\n", vector_size(&vec));
                break;
            default:
                break;
        }
    }

    vector_destroy(&vec);

    return 0;
}