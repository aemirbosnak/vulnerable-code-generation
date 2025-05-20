//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a segment of the array
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // Element found
        }
        if (arr[mid] < x) {
            left = mid + 1; // Ignore left half
        } else {
            right = mid - 1; // Ignore right half
        }
    }
    return -1; // Element not found
}

// Function to perform exponential search
int exponentialSearch(int arr[], int size, int x) {
    // If the element is present at the first location
    if (arr[0] == x) {
        return 0; // Element found at index 0
    }

    // Find range for binary search
    int i = 1;
    while (i < size && arr[i] <= x) {
        i *= 2; // Exponentially increase 'i'
    }

    // Call binary search for the found range
    return binarySearch(arr, i / 2, (i < size ? i : size - 1), x);
}

// Function to display the array elements
void displayArray(int arr[], int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, searchElement;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size); 

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if not enough memory
    }

    // Input the array elements from the user
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Display the array elements
    displayArray(array, size);

    // Ask user for the element to search
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    // Perform exponential search
    int result = exponentialSearch(array, size, searchElement);

    // Display search result
    if (result == -1) {
        printf("Element %d is not found in the array.\n", searchElement);
    } else {
        printf("Element %d is found at index %d.\n", searchElement, result);
    }

    // Free allocated memory
    free(array);
    return 0;
}