//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void initArray(Array *arr) {
    arr->data = malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

void addElement(Array *arr, int element) {
    if (arr->size >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    arr->data[arr->size++] = element;
}

int removeElement(Array *arr) {
    if (arr->size == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    return arr->data[--arr->size];
}

void printArray(Array *arr) {
    printf("Array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    Array arr;
    initArray(&arr);

    for (int i = 0; i < 10; i++) {
        addElement(&arr, i * 2);
    }

    printArray(&arr);

    for (int i = 0; i < 5; i++) {
        int removed = removeElement(&arr);
        printf("Removed element: %d\n", removed);
    }

    printArray(&arr);

    free(arr.data);
    return 0;
}