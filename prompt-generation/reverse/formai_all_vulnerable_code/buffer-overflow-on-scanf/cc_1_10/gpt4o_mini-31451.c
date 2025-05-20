//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);

int main() {
    int size;
    
    // Seed random number generator
    srand(time(NULL));

    // Prompt user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check for valid size
    if (size <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for the array
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate a random array
    generateRandomArray(arr, size);

    // Print the original array
    printf("Original array:\n");
    printArray(arr, size);

    // Sort the array
    bubbleSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // Free allocated memory
    free(arr);
    
    return 0;
}

// Function to generate an array with random integers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort algorithm implementation
void bubbleSort(int arr[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Flag to check if a swap occurred
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // A swap happened
            }
        }
        // If no two elements were swapped in the inner loop, then break
        if (swapped == 0) {
            break;
        }
    }
}