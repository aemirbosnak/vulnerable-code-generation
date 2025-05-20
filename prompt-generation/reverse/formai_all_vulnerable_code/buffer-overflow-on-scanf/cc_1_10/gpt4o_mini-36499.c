//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print an array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
        printf("Step %d: ", i + 1);
        printArray(arr, n);
    }
}

// Function to create an array from user input
void createArray(int arr[], int n) {
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Main function to drive the program
int main() {
    int n;

    // Welcome Message
    printf("*********************************\n");
    printf("*       Welcome to Sorting      *\n");
    printf("*       a Creative Program      *\n");
    printf("*********************************\n\n");

    // Ask user for the number of elements
    printf("How many numbers would you like to sort? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements. Please enter a positive integer.\n");
        return 1;
    }

    // Dynamic memory allocation for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Create the array
    createArray(arr, n);
    printf("\nInitial Array: ");
    printArray(arr, n);

    // Perform selection sort
    printf("\nSorting Process:\n");
    selectionSort(arr, n);
    
    // Sorted array
    printf("\nSorted Array: ");
    printArray(arr, n);

    // Freeing allocated memory
    free(arr);

    printf("\nThank you for using the sorting program! Goodbye!\n");
    return 0;
}