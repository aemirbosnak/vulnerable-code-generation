//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choosing the last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quicksort(arr, low, pi - 1); // Before pi
        quicksort(arr, pi + 1, high); // After pi
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to read integers from user
int* readArray(int *size) {
    printf("Enter the number of elements: ");
    if (scanf("%d", size) != 1 || *size <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    int *arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integer(s):\n", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input! Please enter integers only.\n");
            free(arr);
            exit(EXIT_FAILURE);
        }
    }

    return arr;
}

// Main function
int main() {
    int size;
    int *arr = readArray(&size);

    printf("Original array: ");
    printArray(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    free(arr); // Free the allocated memory
    return 0;
}