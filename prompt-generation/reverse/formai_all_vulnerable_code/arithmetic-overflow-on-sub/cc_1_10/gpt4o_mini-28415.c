//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Function to print array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Asking user for the size of the array
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);

    // Array allocation
    int *arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the sorted array elements from the user
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call function to print the array
    printArray(arr, size);

    // Searching for the target number
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    // Performing binary search
    int result = binarySearch(arr, size, target);

    // Checking the search result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Freeing allocated memory
    free(arr);
    return 0;
}