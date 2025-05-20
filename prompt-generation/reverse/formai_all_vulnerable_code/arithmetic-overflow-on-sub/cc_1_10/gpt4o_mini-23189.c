//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform binary search
int binarySearch(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid to avoid overflow

        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int size;

    // Prompt user for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Input elements of the array
    printf("Enter %d sorted elements (in ascending order):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, size);

    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Free the dynamically allocated memory
    free(arr);
    return EXIT_SUCCESS;
}