//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    // Initializing the left and right pointers for the search
    int left = 0;
    int right = size - 1;

    // Start the introspective journey through the array
    while (left <= right) {
        // Calculate the mid-point to divide the search space
        int mid = left + (right - left) / 2;

        // Output the current state of the search
        printf("Current search space: [%d, %d], Checking middle index: %d\n", left, right, mid);

        // Check if the target is found
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        }
        // If the target is greater than the mid value, ignore left half
        else if (arr[mid] < target) {
            printf("Target %d is greater than %d, ignoring left half.\n", target, arr[mid]);
            left = mid + 1; // Move left pointer up
        }
        // If the target is less than the mid value, ignore right half
        else {
            printf("Target %d is less than %d, ignoring right half.\n", target, arr[mid]);
            right = mid - 1; // Move right pointer down
        }
    }

    // If we reach here, the target was not present in the array
    printf("Target %d not found in the array.\n", target);
    return -1; // Indicating failure to find the target
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the binary search
int main() {
    // Creating a sorted array for demonstration purposes
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int size = sizeof(arr) / sizeof(arr[0]); // Calculating number of elements
    int target; // Variable to store the target value

    // Print the array
    printArray(arr, size);

    // Ask user for the target value
    printf("Enter the number to search for: ");
    scanf("%d", &target); 

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output the final result of the search
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0; // Indicate successful completion of the program
}