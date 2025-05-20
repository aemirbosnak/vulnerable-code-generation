//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int *arr, n;

    printf("Enter the size of the array: \n");
    scanf("%d", &n);

    // allocate memory for the array
    arr = (int*) malloc(n * sizeof(int));

    if (!arr) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // initialize the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    printArray(arr, n);

    // resize the array to be double the original size
    int *temp = (int*) realloc(arr, n * 2 * sizeof(int));

    if (!temp) {
        printf("Memory reallocation error.\n");
        exit(1);
    }

    arr = temp;

    // append more random values to the resized array
    for (int i = n; i < n*2; i++) {
        arr[i] = rand() % 100;
    }

    printf("Resized array:\n");
    printArray(arr, n*2);

    free(arr);

    return 0;
}