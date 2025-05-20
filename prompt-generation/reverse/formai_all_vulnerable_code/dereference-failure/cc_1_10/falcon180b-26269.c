//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

typedef struct {
    int size;
    int* data;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->size = size;
    array->data = (int*)malloc(sizeof(int) * size);
    return array;
}

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

void fillIntArray(IntArray* array, int minValue, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < array->size; i++) {
        array->data[i] = rand() % (maxValue - minValue + 1) + minValue;
    }
}

void printIntArray(IntArray* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray* array1 = createIntArray(MAX_SIZE);
    IntArray* array2 = createIntArray(MAX_SIZE);

    fillIntArray(array1, MIN_VALUE, MAX_VALUE);
    fillIntArray(array2, MIN_VALUE, MAX_VALUE);

    printf("Array 1:\n");
    printIntArray(array1);

    printf("Array 2:\n");
    printIntArray(array2);

    int sum = 0;
    for (int i = 0; i < array1->size; i++) {
        sum += array1->data[i] + array2->data[i];
    }

    printf("Sum of arrays: %d\n", sum);

    destroyIntArray(array1);
    destroyIntArray(array2);

    return 0;
}