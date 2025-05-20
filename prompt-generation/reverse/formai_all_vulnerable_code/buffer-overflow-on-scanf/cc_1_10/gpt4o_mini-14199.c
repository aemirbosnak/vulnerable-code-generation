//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Target found
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
    
    // Target not found
    return -1;
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

// Function to get user input for the array
void inputArray(int arr[], int size) {
    printf("Please enter %d elements: \n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int size;

    printf("Welcome to the Binary Search Program!\n");
    
    // Get the number of elements in the array
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &size);
    
    // Check for valid size
    if (size <= 0) {
        printf("Size must be a positive integer. Exiting...\n");
        return 1;
    }

    int arr[size];  // Create an array of the specified size

    // Input array elements
    inputArray(arr, size);
    
    // Display the original array
    displayArray(arr, size);
    
    // Sort the array
    bubbleSort(arr, size);
    
    // Display the sorted array
    printf("Sorted ");
    displayArray(arr, size);
    
    // Get the target element to search for
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Check the result and display appropriate message
    if (result != -1) {
        printf("Element %d is present at index %d.\n", target, result);
    } else {
        printf("Element %d is not present in the array.\n", target);
    }

    return 0;
}