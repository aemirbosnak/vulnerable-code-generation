//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to perform a linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

// Function to perform a binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index where the target is found
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if the target is not found
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to display an array
void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 0;
    int choice;
    int target;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Input elements into the array
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original Array: ");
    display_array(arr, size);

    // Sort the array for binary search
    qsort(arr, size, sizeof(int), compare);
    printf("Sorted Array: ");
    display_array(arr, size);

    // User menu for searching
    printf("Choose search method:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    // Get target value
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    int result;
    if (choice == 1) {
        result = linear_search(arr, size, target);
        if (result != -1) {
            printf("Linear Search: %d found at index %d\n", target, result);
        } else {
            printf("Linear Search: %d not found\n", target);
        }
    } else if (choice == 2) {
        result = binary_search(arr, size, target);
        if (result != -1) {
            printf("Binary Search: %d found at index %d\n", target, result);
        } else {
            printf("Binary Search: %d not found\n", target);
        }
    } else {
        printf("Invalid choice.\n");
    }

    // Free allocated memory
    free(arr);
    return 0;
}