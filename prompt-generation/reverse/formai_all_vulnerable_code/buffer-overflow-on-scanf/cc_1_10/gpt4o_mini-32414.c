//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found!
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        } else { // If target is smaller, ignore right half
            right = mid - 1;
        }
    }
    return -1; // Target not found!
}

// Function to sort the array using Bubble Sort (just for this adventure)
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

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Amazing Binary Search Adventure!\n");

    int arr[] = {34, 7, 23, 32, 5, 62, 53, 4, 100, 20}; // A chaotic array of numbers
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array before searching
    bubbleSort(arr, size);
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // User input for target element
    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    // Perform binary search and capture the result
    int result = binarySearch(arr, size, target);

    // Output result
    if (result != -1) {
        printf("Hooray! The number %d was found at index %d!\n", target, result);
    } else {
        printf("Oh no! The number %d was not found in the array!\n", target);
    }

    // Thank you message
    printf("Thank you for participating in this exciting search adventure!\n");
    
    return 0;
}