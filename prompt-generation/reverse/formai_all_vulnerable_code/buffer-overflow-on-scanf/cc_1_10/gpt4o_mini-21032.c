//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search in an array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Search the right half
        }
        else {
            right = mid - 1; // Search the left half
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to fill the array with random numbers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to sort the array using bubble sort
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

int main() {
    int size;
    printf("Enter the size of the array (max 100): ");
    scanf("%d", &size);

    if (size > 100 || size <= 0) {
        printf("Invalid size! Must be between 1 and 100.\n");
        return 1;
    }

    int arr[size]; // Declare an array of the specified size

    fillArray(arr, size);
    printf("Original array: ");
    displayArray(arr, size);

    bubbleSort(arr, size);
    printf("Sorted array: ");
    displayArray(arr, size);

    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    printf("Performing linear search...\n");
    int linearResult = linearSearch(arr, size, target);
    
    if (linearResult != -1) {
        printf("Linear Search: Number %d found at index %d.\n", target, linearResult);
    } else {
        printf("Linear Search: Number %d not found.\n", target);
    }

    printf("Performing binary search...\n");
    int binaryResult = binarySearch(arr, 0, size - 1, target);
    
    if (binaryResult != -1) {
        printf("Binary Search: Number %d found at index %d.\n", target, binaryResult);
    } else {
        printf("Binary Search: Number %d not found.\n", target);
    }

    return 0;
}