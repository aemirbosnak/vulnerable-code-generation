//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int* data;
    int size;
    int capacity;
} Array;

void initArray(Array* array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void resizeArray(Array* array, int newCapacity) {
    int* newData = malloc(newCapacity * sizeof(int));
    if (array->data!= NULL) {
        memcpy(newData, array->data, array->size * sizeof(int));
        free(array->data);
    }
    array->data = newData;
    array->capacity = newCapacity;
}

void pushArray(Array* array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int popArray(Array* array) {
    if (array->size == 0) {
        return -1;
    }
    int value = array->data[--array->size];
    if (array->size <= array->capacity / 4) {
        resizeArray(array, array->capacity / 2);
    }
    return value;
}

int main() {
    int limit;
    printf("Enter the limit for the Fibonacci sequence: ");
    scanf("%d", &limit);

    Array fibonacci;
    initArray(&fibonacci);

    int first = 0;
    int second = 1;
    int next = 0;

    pushArray(&fibonacci, first);
    pushArray(&fibonacci, second);

    for (int i = 2; i < limit; i++) {
        next = first + second;
        pushArray(&fibonacci, next);
        first = second;
        second = next;
    }

    printf("Fibonacci sequence up to %d:\n", limit);
    for (int i = 0; i < fibonacci.size; i++) {
        printf("%d ", popArray(&fibonacci));
    }

    return 0;
}