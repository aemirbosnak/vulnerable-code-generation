//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void getUserInput(int arr[], int size);
void displayArray(int arr[], int size);
int binarySearch(int arr[], int left, int right, int target);

int main() {
    // Prompt user for the size of the array
    int size;
    printf("Enter the number of elements you want in your sorted array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be a positive integer!\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get user input for the array elements
    getUserInput(arr, size);
    // Display the sorted array
    printf("The sorted array is:\n");
    displayArray(arr, size);

    // Prompt user for the target element to search
    int target;
    printf("Enter the element you wish to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, 0, size - 1, target);
    
    // Display the result of the search
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Free dynamically allocated memory
    free(arr);
    return 0;
}

// Function to fill the array with user input
void getUserInput(int arr[], int size) {
    printf("Please enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display the contents of the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;
        // Target is smaller than mid - search left
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        // Target is larger than mid - search right
        return binarySearch(arr, mid + 1, right, target);
    }
    // Target was not found
    return -1;
}