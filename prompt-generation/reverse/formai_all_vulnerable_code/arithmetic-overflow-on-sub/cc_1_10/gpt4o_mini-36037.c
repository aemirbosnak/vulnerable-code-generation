//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array (used in quicksort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now in the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to initialize the array with random numbers
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to check if the array is sorted
int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i])
            return 0; // Not sorted
    }
    return 1; // Sorted
}

// Main function
int main() {
    int size;
    
    // Prompt user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation for the array
    int *arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Initialize the array with random numbers
    initializeArray(arr, size);
    
    // Display the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort the array using quicksort
    quickSort(arr, 0, size - 1);
    
    // Display the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // Check if the array is sorted
    if (isSorted(arr, size)) {
        printf("The array is sorted correctly.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}