//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int *arr;
    int n, i;

    // Ask the user for the number of elements to sort
    printf("Enter the number of elements you want to sort: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Read the elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return EXIT_FAILURE;
        }
    }

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free allocated memory
    free(arr);
    return EXIT_SUCCESS;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}