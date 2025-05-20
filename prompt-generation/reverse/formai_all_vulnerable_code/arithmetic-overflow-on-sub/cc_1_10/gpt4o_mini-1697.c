//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sortArray(int *array, int size);
void swap(int *xp, int *yp);
void bubbleSort(int *array, int size);
int binarySearch(int *array, int left, int right, int target);
void printArray(int *array, int size);

int main() {
    int n, target, result;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if(array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements of the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Sort the array
    sortArray(array, n);
    
    // Display the sorted array
    printf("Sorted array: ");
    printArray(array, n);

    // Input the target to search
    printf("Enter the integer to search for: ");
    scanf("%d", &target);

    // Execute binary search
    result = binarySearch(array, 0, n - 1, target);
    
    // Display result
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    // Free allocated memory
    free(array);
    return 0;
}

// Function to perform a recursive binary search
int binarySearch(int *array, int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the element is present at mid
        if (array[mid] == target) {
            return mid;
        }

        // If target is smaller than mid, search in the left sub-array
        if (array[mid] > target) {
            return binarySearch(array, left, mid - 1, target);
        }

        // If target is larger than mid, search in the right sub-array
        return binarySearch(array, mid + 1, right, target);
    }

    // Element was not present
    return -1;
}

// Function to sort the array using Bubble Sort
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Function to swap two integers
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Wrapper function for sorting
void sortArray(int *array, int size) {
    bubbleSort(array, size);
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}