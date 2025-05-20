//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow

        if (arr[mid] == target) {
            return mid; // Return the index of the found element
        } else if (arr[mid] < target) {
            left = mid + 1; // Search on the right side
        } else {
            right = mid - 1; // Search on the left side
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to fill the array with random integers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random integers between 0 and 999
    }
}

// Function to sort the array using bubble sort (not the most efficient but simple)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the contents of the array
void displayArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    fillArray(arr, size);
    printf("Unsorted ");
    displayArray(arr, size);

    bubbleSort(arr, size);
    printf("Sorted ");
    displayArray(arr, size);

    int target;
    printf("Enter a number to search: ");
    scanf("%d", &target);

    // Linear search
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        printf("Linear Search: Element %d found at index %d.\n", target, linearResult);
    } else {
        printf("Linear Search: Element %d not found.\n", target);
    }

    // Binary search
    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target, binaryResult);
    } else {
        printf("Binary Search: Element %d not found.\n", target);
    }

    return 0;
}