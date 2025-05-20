//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
void fillArray(int arr[], int size);

int main() {
    int n;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    // Dynamic memory allocation for array
    int *arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with failure
    }

    // Fill the array with random values
    fillArray(arr, n);

    printf("Original array:\n");
    printArray(arr, n);

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    // Free allocated memory
    free(arr);
    return 0;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate an array of random integers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // random numbers between 0 and 99
    }
}