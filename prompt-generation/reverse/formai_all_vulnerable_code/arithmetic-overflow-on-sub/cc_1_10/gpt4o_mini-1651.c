//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void fillArray(int *arr, int size);
void printArray(const int *arr, int size);
void sortArray(int *arr, int size);
void swap(int *a, int *b);

int main() {
    int size;

    // Seed random number generator
    srand(time(NULL));

    // Prompt user for size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Fill the array with random integers
    fillArray(array, size);
    
    // Print original array
    printf("Original Array:\n");
    printArray(array, size);

    // Sort the array
    sortArray(array, size);

    // Print sorted array
    printf("Sorted Array:\n");
    printArray(array, size);

    // Free allocated memory
    free(array);
    return EXIT_SUCCESS;
}

// Function to fill an array with random integers
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print an array
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using Bubble Sort
void sortArray(int *arr, int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
    } while (swapped);
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}