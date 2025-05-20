//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2; // Calculate the mid index

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index of the key
        }

        // If key is smaller than mid, search in the left sub-array
        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }

        // If key is larger than mid, search in the right sub-array
        return binarySearch(arr, mid + 1, high, key);
    }

    // Key was not found
    return -1;
}

// Function to create and fill an array with sorted numbers
void createSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; // Filling array with even numbers for simplicity
    }
}

// Main function
int main() {
    int n, key, result;

    printf("Welcome to the Binary Search Program!\n");
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    int arr[n]; // Declare an array of size n
    createSortedArray(arr, n); // Fill the array with sorted numbers

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the number you want to search for: ");
    scanf("%d", &key);

    // Perform binary search
    result = binarySearch(arr, 0, n - 1, key);

    // Display result
    if (result != -1) {
        printf("Number %d found at index %d.\n", key, result);
    } else {
        printf("Number %d not found in the array.\n", key);
    }

    return 0;
}