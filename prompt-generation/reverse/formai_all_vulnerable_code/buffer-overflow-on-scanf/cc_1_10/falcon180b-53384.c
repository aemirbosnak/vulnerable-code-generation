//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray *createArray(int size) {
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    return array;
}

void destroyArray(IntArray *array) {
    free(array->data);
    free(array);
}

void fillArray(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void printArray(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray *array1, *array2, *result;
    int i, j, k, n;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    array1 = createArray(n);

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array1->data[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);
    array2 = createArray(n);

    printf("Enter the elements of the second array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array2->data[i]);
    }

    result = createArray(n);

    for (i = 0; i < n; i++) {
        result->data[i] = array1->data[i] + array2->data[i];
    }

    printf("The sum of the two arrays is: ");
    printArray(result);

    destroyArray(array1);
    destroyArray(array2);
    destroyArray(result);

    return 0;
}