//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Vector;

Vector* createVector(int size) {
    Vector *v = malloc(sizeof(Vector));
    v->data = malloc(sizeof(int) * size);
    v->size = size;
    return v;
}

void destroyVector(Vector *v) {
    free(v->data);
    free(v);
}

void printVector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void fillVectorWithRandomValues(Vector *v) {
    srand(time(NULL));
    for (int i = 0; i < v->size; i++) {
        v->data[i] = rand() % 100;
    }
}

void shiftLeft(Vector *v) {
    for (int i = 0; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->data[v->size - 1] = 0;
}

void shiftRight(Vector *v) {
    for (int i = v->size - 1; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[0] = 0;
}

int main() {
    int size = MAX_SIZE;
    Vector *v = createVector(size);
    fillVectorWithRandomValues(v);
    printf("Original vector:\n");
    printVector(v);

    shiftLeft(v);
    printf("Shifted left by one position:\n");
    printVector(v);

    shiftRight(v);
    printf("Shifted right by one position:\n");
    printVector(v);

    destroyVector(v);
    return 0;
}