//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int *arr, int size);
void printArray(int *arr, int size);
void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

// Main function
int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate random numbers and store them in the array
    generateRandomArray(array, size);
    
    // Print the original array
    printf("Original array:\n");
    printArray(array, size);

    // Sort the array using Quick Sort
    quickSort(array, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(array, size);

    // Free the allocated memory
    free(array);

    return 0;
}

// Function to generate an array of random integers
void generateRandomArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print the elements of an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function implementing the Quick Sort algorithm
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);       // Recursively sort elements before partition
        quickSort(arr, pi + 1, high);      // Recursively sort elements after partition
    }
}

// Function to partition the array
int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
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

    return (i + 1); // Return the partitioning index
}