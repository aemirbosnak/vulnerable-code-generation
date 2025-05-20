//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Not found
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Return the index where the element is found
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
    return -1; // Not found
}

// Function to sort the array (Bubble Sort)
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void display_array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit on memory allocation failure
    }

    // Get elements of the array from user
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    display_array(arr, size);

    // Perform linear search
    int target_linear;
    printf("Enter a number to search using Linear Search: ");
    scanf("%d", &target_linear);
    int linear_result = linear_search(arr, size, target_linear);
    if (linear_result != -1) {
        printf("Linear Search: Element %d found at index %d\n", target_linear, linear_result);
    } else {
        printf("Linear Search: Element %d not found in the array\n", target_linear);
    }

    // Perform binary search
    bubble_sort(arr, size); // Sort the array before binary search
    printf("Sorted ");
    display_array(arr, size); // Display the sorted array

    int target_binary;
    printf("Enter a number to search using Binary Search: ");
    scanf("%d", &target_binary);
    int binary_result = binary_search(arr, size, target_binary);
    if (binary_result != -1) {
        printf("Binary Search: Element %d found at index %d\n", target_binary, binary_result);
    } else {
        printf("Binary Search: Element %d not found in the array\n", target_binary);
    }

    // Free allocated memory
    free(arr);

    return 0; // Successful completion
}