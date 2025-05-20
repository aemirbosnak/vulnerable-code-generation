//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *array) {
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size] = element;
    array->size++;
}

void removeElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    if (array->size < array->capacity / 4) {
        array->capacity /= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
}

void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray array;
    initArray(&array);
    addElement(&array, 10);
    addElement(&array, 20);
    addElement(&array, 30);
    printArray(&array);
    removeElement(&array, 1);
    printArray(&array);
    return 0;
}