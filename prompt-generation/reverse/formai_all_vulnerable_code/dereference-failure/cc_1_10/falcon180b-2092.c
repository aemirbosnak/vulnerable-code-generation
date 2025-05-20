//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int *data;
    int capacity;
    int size;
} DynamicArray;

DynamicArray *createArray(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(capacity * sizeof(int));
    array->capacity = capacity;
    array->size = 0;
    return array;
}

void resizeArray(DynamicArray *array, int newCapacity) {
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    int i;
    for (i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->size] = element;
    array->size++;
}

void removeElement(DynamicArray *array, int index) {
    int i;
    if (index >= array->size) {
        return;
    }
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    if (array->size < array->capacity / 4) {
        resizeArray(array, array->capacity / 2);
    }
}

void printArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createArray(SIZE);
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
    printArray(array);
    removeElement(array, 3);
    removeElement(array, 5);
    removeElement(array, 7);
    printArray(array);
    return 0;
}