//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
void printArray(int arr[], int size);
void quickSort(int arr[], int left, int right);

int main() {
    int size;

    // Ask user for array size
    printf("Enter array size: ");
    scanf("%d", &size);

    // Initialize array with random numbers
    int arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort array using quicksort
    quickSort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}

// Generates a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Prints an integer array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sorts an integer array using quicksort
void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(arr, left, right);

    // Recursively sort left and right partitions
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

// Partitions an integer array and returns the pivot index
int partition(int arr[], int left, int right) {
    int pivotIndex = generateRandomNumber(left, right);

    // Swap pivot element with last element in partition
    int pivotValue = arr[pivotIndex];
    arr[pivotIndex] = arr[right];
    arr[right] = pivotValue;

    int storeIndex = left;

    // Partition array around pivot element
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            int temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex++;
        }
    }

    // Move pivot element to its correct position
    int temp = arr[storeIndex];
    arr[storeIndex] = arr[right];
    arr[right] = temp;

    return storeIndex;
}