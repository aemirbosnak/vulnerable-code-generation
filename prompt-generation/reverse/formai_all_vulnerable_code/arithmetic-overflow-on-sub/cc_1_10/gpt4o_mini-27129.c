//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if the target is not found
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the target
        }
        if (arr[mid] < target) {
            left = mid + 1; // Target is on right side
        } else {
            right = mid - 1; // Target is on left side
        }
    }
    return -1; // Target not found
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size, target, choice;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Size exceeds maximum limit of %d.\n", MAX_SIZE);
        return 1;
    }

    // Populate the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display array elements
    displayArray(arr, size);

    printf("Choose a search method:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    if (choice == 2) {
        // Sort the array before binary search
        sortArray(arr, size);
        printf("Sorted ");
        displayArray(arr, size);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = (choice == 1) ? linearSearch(arr, size, target) : binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}