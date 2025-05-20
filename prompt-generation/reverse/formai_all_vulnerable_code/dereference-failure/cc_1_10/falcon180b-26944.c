//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createArray() {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    array->data = (int *) malloc(sizeof(int) * SIZE);
    array->size = 0;
    array->capacity = SIZE;
    return array;
}

void destroyArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *) realloc(array->data, sizeof(int) * array->capacity);
    }
    array->data[array->size++] = element;
}

int main() {
    DynamicArray *array = createArray();
    addElement(array, 1);
    addElement(array, 2);
    addElement(array, 3);
    addElement(array, 4);
    addElement(array, 5);
    addElement(array, 6);
    addElement(array, 7);
    addElement(array, 8);
    addElement(array, 9);
    addElement(array, 10);

    printf("Array size: %d\n", array->size);

    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");

    destroyArray(array);
    return 0;
}