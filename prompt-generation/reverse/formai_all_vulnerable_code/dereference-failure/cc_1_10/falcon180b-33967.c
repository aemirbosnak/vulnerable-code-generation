//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} IntArray;

void initArray(IntArray *array) {
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void addElement(IntArray *array, int element) {
    if (array->size >= MAX_SIZE) {
        printf("Array is full. Cannot add element.\n");
        return;
    }
    array->data[array->size++] = element;
}

void removeElement(IntArray *array, int index) {
    if (index < 0 || index >= array->size) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void printArray(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray array;
    initArray(&array);
    addElement(&array, 1);
    addElement(&array, 2);
    addElement(&array, 3);
    addElement(&array, 4);
    addElement(&array, 5);
    printArray(&array);
    removeElement(&array, 2);
    printArray(&array);
    return 0;
}