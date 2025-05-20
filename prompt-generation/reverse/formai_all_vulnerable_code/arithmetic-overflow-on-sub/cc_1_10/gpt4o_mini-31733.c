//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>

// Function to perform the search in a rotated sorted array
int rotatedBinarySearch(int arr[], int low, int high, int target) {
    // Base case
    if (low > high) {
        return -1;  // Target not found
    }

    int mid = (low + high) / 2;

    // If the middle element is the target
    if (arr[mid] == target) {
        return mid;
    }

    // If the left half is sorted
    if (arr[low] <= arr[mid]) {
        // Check if the target is in the left half
        if (arr[low] <= target && target < arr[mid]) {
            return rotatedBinarySearch(arr, low, mid - 1, target);
        }
        // If the target is not in the left half, search in the right half
        else {
            return rotatedBinarySearch(arr, mid + 1, high, target);
        }
    } 
    // If the right half is sorted
    else {
        // Check if the target is in the right half
        if (arr[mid] < target && target <= arr[high]) {
            return rotatedBinarySearch(arr, mid + 1, high, target);
        }
        // If the target is not in the right half, search in the left half
        else {
            return rotatedBinarySearch(arr, low, mid - 1, target);
        }
    }
}

// Function to print the result of the search
void printResult(int index) {
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }
}

// Function to interact with the user
void interactWithUser() {
    int n, target;
    
    // Ask user for the size of the array
    printf("Enter the number of elements in the rotated sorted array: ");
    scanf("%d", &n);
    
    // Create an array of size n
    int arr[n];

    // Input elements into the array
    printf("Enter the elements of the rotated sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask for the target element to search
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    // Search for the target
    int index = rotatedBinarySearch(arr, 0, n - 1, target);
    
    // Print the result
    printResult(index);
}

// Main function
int main() {
    printf("Welcome to the Rotated Sorted Array Search Program!\n");
    interactWithUser();
    return 0;
}