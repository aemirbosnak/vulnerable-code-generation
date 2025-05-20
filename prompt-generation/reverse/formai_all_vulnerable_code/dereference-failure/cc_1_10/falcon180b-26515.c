//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    array->data = malloc(capacity * sizeof(int));
    array->capacity = capacity;
    array->size = 0;
    return array;
}

void freeDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    array->capacity = newCapacity;
    array->data = realloc(array->data, newCapacity * sizeof(int));
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray(4);
    addElementToDynamicArray(array, 1);
    addElementToDynamicArray(array, 2);
    addElementToDynamicArray(array, 3);
    addElementToDynamicArray(array, 4);
    addElementToDynamicArray(array, 5);
    printDynamicArray(array);
    freeDynamicArray(array);
    return 0;
}