//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = malloc(sizeof(IntArray));
    array->data = malloc(size * sizeof(int));
    array->size = size;
    return array;
}

void destroyIntArray(IntArray *array) {
    free(array->data);
    free(array);
}

void fillIntArray(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void addIntArrays(IntArray *array1, IntArray *array2, IntArray *result) {
    int i;
    for (i = 0; i < array1->size; i++) {
        result->data[i] = array1->data[i] + array2->data[i];
    }
}

void multiplyIntArrays(IntArray *array1, IntArray *array2, IntArray *result) {
    int i;
    for (i = 0; i < array1->size; i++) {
        result->data[i] = array1->data[i] * array2->data[i];
    }
}

void printIntArray(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray *array1, *array2, *result;
    int size, i;

    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    array1 = createIntArray(size);
    array2 = createIntArray(size);
    result = createIntArray(size);

    printf("Enter the elements of array 1: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &array1->data[i]);
    }

    printf("Enter the elements of array 2: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &array2->data[i]);
    }

    addIntArrays(array1, array2, result);
    printf("Sum of arrays:\n");
    printIntArray(result);

    multiplyIntArrays(array1, array2, result);
    printf("Product of arrays:\n");
    printIntArray(result);

    destroyIntArray(array1);
    destroyIntArray(array2);
    destroyIntArray(result);

    return 0;
}