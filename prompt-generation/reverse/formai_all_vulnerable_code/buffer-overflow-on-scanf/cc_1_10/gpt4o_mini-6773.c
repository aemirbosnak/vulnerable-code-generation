//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target not found in array
    return -1;
}

// Function to fill an array with random integers for demonstration
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
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

// Function to check if an array is sorted
int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main() {
    int size = 10;
    int arr[size];

    // Seed the random number generator
    srand(time(NULL));

    // Fill array with random integers
    fillArray(arr, size);
    
    printf("Original Array:\n");
    printArray(arr, size);
    
    // Sort the array
    bubbleSort(arr, size);
    
    printf("Sorted Array:\n");
    printArray(arr, size);
    
    // Check if the array is sorted
    if (isSorted(arr, size)) {
        printf("Array is sorted.\n");
    } else {
        printf("Array is not sorted.\n");
    }

    // Prompt user for a number to search
    int target;
    printf("Enter an integer to search for: ");
    scanf("%d", &target);
    
    // Call binary search
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}