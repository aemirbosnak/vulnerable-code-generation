//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
} Vector;

void initVector(Vector *v) {
    v->data = NULL;
    v->size = 0;
}

void pushBack(Vector *v, int data) {
    if (v->size == 0) {
        v->data = malloc(sizeof(int));
        v->data[0] = data;
        v->size = 1;
    } else {
        v->data = realloc(v->data, sizeof(int) * (v->size + 1));
        v->data[v->size] = data;
        v->size++;
    }
}

void printVector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Vector v1, v2;
    initVector(&v1);
    initVector(&v2);

    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        pushBack(&v1, num);
        pushBack(&v2, num);
    }

    printf("Vector 1: ");
    printVector(&v1);

    printf("Vector 2: ");
    printVector(&v2);

    return 0;
}