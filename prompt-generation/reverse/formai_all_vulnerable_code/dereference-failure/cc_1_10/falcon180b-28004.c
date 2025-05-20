//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector *vec_create(size_t capacity) {
    Vector *vec = malloc(sizeof(Vector));
    vec->data = malloc(capacity * sizeof(int));
    vec->size = 0;
    vec->capacity = capacity;
    return vec;
}

void vec_destroy(Vector *vec) {
    free(vec->data);
    free(vec);
}

void vec_push(Vector *vec, int value) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}

int vec_pop(Vector *vec) {
    if (vec->size == 0) {
        return -1;
    }
    return vec->data[--vec->size];
}

void vec_print(Vector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Vector *vec = vec_create(10);

    for (int i = 0; i < 100; i++) {
        int action = rand() % 3;
        switch (action) {
            case 0:
                vec_push(vec, rand() % 100);
                break;
            case 1:
                printf("Popped: %d\n", vec_pop(vec));
                break;
            case 2:
                vec_print(vec);
                break;
        }
    }

    vec_destroy(vec);
    return 0;
}