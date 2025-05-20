//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;            // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to take input from user
int* inputArray(int* size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integer elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

// Main function
int main() {
    int size;
    // Input the array from the user
    int* arr = inputArray(&size);

    // Calling Quick Sort
    quickSort(arr, 0, size - 1);

    // Display the sorted array
    displayArray(arr, size);

    // Free the allocated memory
    free(arr);
    
    return 0;
}