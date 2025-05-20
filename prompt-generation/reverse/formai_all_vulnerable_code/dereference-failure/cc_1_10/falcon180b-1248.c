//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray(int initialCapacity) {
    DynamicArray *array = (DynamicArray*) malloc(sizeof(DynamicArray));
    array->data = (int*) malloc(sizeof(int) * initialCapacity);
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    int *newData = (int*) malloc(sizeof(int) * newCapacity);
    int i;
    for (i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
}

void removeElementFromDynamicArray(DynamicArray *array, int index) {
    int i;
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void printDynamicArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray(5);
    addElementToDynamicArray(array, 1);
    addElementToDynamicArray(array, 2);
    addElementToDynamicArray(array, 3);
    addElementToDynamicArray(array, 4);
    addElementToDynamicArray(array, 5);
    printDynamicArray(array);
    removeElementFromDynamicArray(array, 2);
    printDynamicArray(array);
    addElementToDynamicArray(array, 6);
    printDynamicArray(array);
    destroyDynamicArray(array);
    return 0;
}