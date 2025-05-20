//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for an array
int* allocateMemory(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}

// Function to free memory for an array
void freeMemory(int* arr, int size) {
    free(arr);
}

// Function to print array elements
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort array in ascending order
void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = allocateMemory(size);
    if (arr == NULL) {
        return 1;
    }

    printf("Original array: \n");
    printArray(arr, size);

    sortArray(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    freeMemory(arr, size);

    return 0;
}