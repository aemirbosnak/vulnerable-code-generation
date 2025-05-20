//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void printArray(int *arr, int size);
void inputArray(int **arr, int *size);
void freeMemory(int *arr);

int main() {
    int *arr = NULL;
    int size = 0;

    // Input array from user
    inputArray(&arr, &size);
    if (arr == NULL || size <= 0) {
        fprintf(stderr, "Error: No valid input.\n");
        return EXIT_FAILURE;
    }

    printf("Original array:\n");
    printArray(arr, size);

    // Sort the array
    quicksort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    printArray(arr, size);

    // Free allocated memory
    freeMemory(arr);
    return EXIT_SUCCESS;
}

// Function to perform quicksort
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to input array from the user
void inputArray(int **arr, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    if (*size <= 0) {
        return; // Invalid size
    }

    // Allocate memory for the array
    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Input elements
    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

// Function to free allocated memory
void freeMemory(int *arr) {
    free(arr);
}