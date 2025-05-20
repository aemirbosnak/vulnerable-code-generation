//Falcon-180B DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the size of the array
#define SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[SIZE];
    int i;

    // Prompt the user to enter the array elements
    printf("Enter %d integers:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, SIZE);

    // Sort the array
    bubbleSort(arr, SIZE);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, SIZE);

    return 0;
}