//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void swap(int *xp, int *yp);
int *initializeArray(int n);
void freeArray(int *arr);

int main() {
    int n, *arr;

    // Asking the user for the number of elements
    printf("Enter the number of elements you want to sort: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Dynamically create an array
    arr = initializeArray(n);
    if (!arr) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Getting the elements from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers only.\n");
            freeArray(arr);
            return 1;
        }
    }

    printf("Original array: \n");
    printArray(arr, n);

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);

    // Freeing allocated memory
    freeArray(arr);
    
    return 0;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to initialize the array dynamically
int *initializeArray(int n) {
    return (int *)malloc(n * sizeof(int));
}

// Function to free allocated memory for the array
void freeArray(int *arr) {
    if (arr != NULL) {
        free(arr);
    }
}