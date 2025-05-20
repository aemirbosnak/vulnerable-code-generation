//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

// Function to perform binary search (requires sorted array)
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return index
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in right half
        } else {
            right = mid - 1; // Search in left half
        }
    }
    return -1; // Target not found
}

// Function to sort an array using bubble sort (to prepare for binary search)
void bubble_sort(int arr[], int size) {
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

// Function to display the array
void display_array(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size, choice, target, result;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Exiting...\n");
        return 1; // Error, return non-zero
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    display_array(arr, size);

    printf("Select Search Method:\n1. Linear Search\n2. Binary Search (Input must be sorted)\n");
    scanf("%d", &choice);

    printf("Enter target value to search: ");
    scanf("%d", &target);

    switch (choice) {
        case 1:
            result = linear_search(arr, size, target);
            if (result != -1) {
                printf("Linear Search: Element %d found at index %d\n", target, result);
            } else {
                printf("Linear Search: Element %d not found\n", target);
            }
            break;

        case 2:
            bubble_sort(arr, size); // Sort the array before binary search
            printf("Array sorted for Binary Search.\n");
            display_array(arr, size);
            result = binary_search(arr, size, target);
            if (result != -1) {
                printf("Binary Search: Element %d found at index %d\n", target, result);
            } else {
                printf("Binary Search: Element %d not found\n", target);
            }
            break;

        default:
            printf("Invalid choice! Exiting...\n");
            return 1; // Error, return non-zero
    }

    return 0; // Successful execution
}