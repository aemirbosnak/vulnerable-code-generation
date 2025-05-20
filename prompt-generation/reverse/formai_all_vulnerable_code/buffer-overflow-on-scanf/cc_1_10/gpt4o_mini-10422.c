//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>      // For standard input and output functions
#include <stdlib.h>     // For dynamic memory allocation and random number generation
#include <time.h>       // For seeding the random number generator with the current time

void swap(int *xp, int *yp) {
    int temp = *xp;   // Temporary variable to store the value at first pointer
    *xp = *yp;        // Assign the value at second pointer to first pointer
    *yp = temp;       // Assign the temporary value to second pointer
}

void bubbleSort(int arr[], int n) {
    int i, j;         // Loop counters
    int swapped;      // Flag to check if a swap occurred
    for (i = 0; i < n-1; i++) {
        swapped = 0;  // Reset the swapped flag for this pass
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {  // Compare adjacent elements
                swap(&arr[j], &arr[j+1]); // Swap if they are in the wrong order
                swapped = 1; // A swap occurred
            }
        }
        if (swapped == 0) // If no swaps occurred, the array is sorted
            break;
    }
}

void printArray(int arr[], int size) {
    int i;           // Loop counter
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print each element followed by a space
    }
    printf("\n");   // Move to the next line after printing the array
}

int main() {
    int n;           // Number of elements in the array
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);  // Read the number of elements from user input

    int *arr = (int *)malloc(n * sizeof(int)); // Dynamic memory allocation for the array
    if (arr == NULL) {   // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;        // Return with an error code
    }

    srand(time(0));     // Seed the random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Fill the array with random integers from 0 to 99
    }

    printf("Unsorted array:\n");
    printArray(arr, n);  // Print the unsorted array

    bubbleSort(arr, n);  // Sort the array using bubble sort algorithm

    printf("Sorted array:\n");
    printArray(arr, n);  // Print the sorted array

    free(arr);           // Release the dynamically allocated memory
    return 0;            // Return success code
}