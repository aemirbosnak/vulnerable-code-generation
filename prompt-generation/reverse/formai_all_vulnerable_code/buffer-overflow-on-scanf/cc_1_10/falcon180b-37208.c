//Falcon-180B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
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
    int arr[MAX_SIZE];
    int size;

    // Get array size from user
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get array elements from user
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort array using bubble sort
    bubbleSort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}