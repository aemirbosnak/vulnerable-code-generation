//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // return index if target is found
        }
    }
    return -1; // return -1 if target is not found
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // return index if target is found
        } else if (arr[mid] < target) {
            left = mid + 1; // target is in the right half
        } else {
            right = mid - 1; // target is in the left half
        }
    }
    return -1; // return -1 if target is not found
}

// Function to sort the array (Bubble Sort)
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
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size, target, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the array before sorting
    display_array(arr, size);
    
    // Perform Bubble sort
    bubble_sort(arr, size);

    // Display the array after sorting
    printf("Array after sorting:\n");
    display_array(arr, size);

    // Input the target to search
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Ask user for the search algorithm
    printf("Choose search algorithm:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    int result;
    if (choice == 1) {
        result = linear_search(arr, size, target);
    } else if (choice == 2) {
        result = binary_search(arr, size, target);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    // Display the result of the search
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}