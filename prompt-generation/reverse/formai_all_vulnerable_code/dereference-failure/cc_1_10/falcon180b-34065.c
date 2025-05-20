//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int size;
    int *data;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *) malloc(sizeof(IntArray));
    array->size = size;
    array->data = (int *) malloc(sizeof(int) * size);
    return array;
}

void deleteIntArray(IntArray *array) {
    free(array->data);
    free(array);
}

void fillIntArray(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
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
    IntArray *array1 = createIntArray(MAX_SIZE);
    IntArray *array2 = createIntArray(MAX_SIZE);
    fillIntArray(array1, 1);
    fillIntArray(array2, 2);
    int sum = 0;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        sum += array1->data[i] + array2->data[i];
    }
    printf("The sum of the two arrays is: %d\n", sum);
    deleteIntArray(array1);
    deleteIntArray(array2);
    return 0;
}