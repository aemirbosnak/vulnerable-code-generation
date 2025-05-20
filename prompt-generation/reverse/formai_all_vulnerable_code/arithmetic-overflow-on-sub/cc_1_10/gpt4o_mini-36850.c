//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // Target was not found
    return -1;
}

// Function to print an array
void print_array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort array using bubble sort (for simplicity)
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to get user input
void get_user_input(int *arr, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    
    printf("Enter %d sorted elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int size;
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(100 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Get user input for the array
    get_user_input(arr, &size);
    
    // Sort the array (in case it's not sorted)
    bubble_sort(arr, size);

    // Print the array
    print_array(arr, size);
    
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    // Perform binary search
    int result = binary_search(arr, size, target);

    // Display results
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Free allocated memory
    free(arr);

    return 0;
}