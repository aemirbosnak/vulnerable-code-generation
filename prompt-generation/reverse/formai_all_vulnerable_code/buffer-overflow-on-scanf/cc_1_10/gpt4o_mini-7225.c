//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read the array from input
void readArray(int arr[], int n) {
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to demonstrate the sorting process
void sortingProcessDemo() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements must be positive.\n");
        return;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    readArray(arr, n);

    printf("Unsorted array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    free(arr);
}

// The main function to drive the program
int main() {
    printf("Welcome to the Ada Lovelace Sorting Program!\n");
    sortingProcessDemo();
    printf("Thank you for using the sorting program. Goodbye!\n");
    return 0;
}