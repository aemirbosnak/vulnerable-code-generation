//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to partition the array into two halves
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Recursively sort elements before partition
        quickSort(arr, pivotIndex + 1, high); // Recursively sort elements after partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read integers from stdin
void readArray(int arr[], int* size) {
    printf("Enter number of elements: ");
    scanf("%d", size);
    
    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size;

    readArray(arr, &size);

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}