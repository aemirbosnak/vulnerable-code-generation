//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

typedef struct {
    int size;
    int *array;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *) malloc(sizeof(IntArray));
    array->size = size;
    array->array = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array->array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    return array;
}

void deleteIntArray(IntArray *array) {
    free(array->array);
    free(array);
}

void printIntArray(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

void sortIntArray(IntArray *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = i + 1; j < array->size; j++) {
            if (array->array[i] > array->array[j]) {
                int temp = array->array[i];
                array->array[i] = array->array[j];
                array->array[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    IntArray *array = createIntArray(MAX_SIZE);
    printf("Before sorting:\n");
    printIntArray(array);
    sortIntArray(array);
    printf("After sorting:\n");
    printIntArray(array);
    deleteIntArray(array);
    return 0;
}