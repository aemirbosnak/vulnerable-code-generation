//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *data;
    int size;
} IntArray;

void createArray(IntArray *array, int size) {
    array->data = malloc(sizeof(int) * size);
    array->size = size;
}

void destroyArray(IntArray *array) {
    free(array->data);
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
    IntArray array1, array2, result;
    int size1, size2, i;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    createArray(&array1, size1);

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    createArray(&array2, size2);

    printf("Enter the elements of the first array: ");
    fillArray(&array1, 0);

    printf("Enter the elements of the second array: ");
    fillArray(&array2, 0);

    printf("The first array is: ");
    printArray(&array1);

    printf("The second array is: ");
    printArray(&array2);

    if (array1.size!= array2.size) {
        printf("Error: Arrays must be of the same size\n");
        destroyArray(&array1);
        destroyArray(&array2);
        return 1;
    }

    result.size = array1.size;
    createArray(&result, result.size);

    int carry = 0;
    for (i = array1.size - 1; i >= 0; i--) {
        int sum = array1.data[i] + array2.data[i] + carry;
        result.data[i] = sum % 10;
        carry = sum / 10;
    }

    printf("The sum of the two arrays is: ");
    printArray(&result);

    destroyArray(&array1);
    destroyArray(&array2);
    destroyArray(&result);

    return 0;
}