//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *ptr;
    int size;
} DynamicArray;

DynamicArray *createDynamicArray(int size) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    arr->ptr = (int *)malloc(size * sizeof(int));
    if (arr->ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    arr->size = size;
    return arr;
}

void destroyDynamicArray(DynamicArray *arr) {
    free(arr->ptr);
    free(arr);
}

void pushBack(DynamicArray *arr, int value) {
    if (arr->size == 0) {
        printf("Error: Array is empty\n");
        exit(1);
    }
    if (arr->size == arr->ptr[arr->size - 1]) {
        printf("Error: Array is full\n");
        exit(1);
    }
    arr->ptr[arr->size++] = value;
}

void popBack(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Error: Array is empty\n");
        exit(1);
    }
    arr->size--;
}

void printArray(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
    } else {
        for (int i = 0; i < arr->size; i++) {
            printf("%d ", arr->ptr[i]);
        }
        printf("\n");
    }
}

int main() {
    DynamicArray *arr = createDynamicArray(5);
    pushBack(arr, 10);
    pushBack(arr, 20);
    pushBack(arr, 30);
    pushBack(arr, 40);
    pushBack(arr, 50);
    printArray(arr);
    popBack(arr);
    printArray(arr);
    destroyDynamicArray(arr);
    return 0;
}