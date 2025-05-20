//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000
#define TRUE 1
#define FALSE 0

typedef struct {
    int *data;
    int size;
} IntArray;

void createIntArray(IntArray *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
}

void destroyIntArray(IntArray *array) {
    free(array->data);
}

void fillIntArray(IntArray *array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void printIntArray(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray arr1, arr2;
    int size, i, j;

    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    createIntArray(&arr1, size);
    createIntArray(&arr2, size);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr1.data[i]);
    }

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr2.data[i]);
    }

    for (i = 0; i < size; i++) {
        arr1.data[i] += arr2.data[i];
    }

    printf("Sum of the arrays:\n");
    printIntArray(&arr1);

    destroyIntArray(&arr1);
    destroyIntArray(&arr2);

    return 0;
}