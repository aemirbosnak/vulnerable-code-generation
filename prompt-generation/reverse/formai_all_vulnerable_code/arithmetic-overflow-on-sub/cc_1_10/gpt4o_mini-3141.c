//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform binary search on a sorted array
int binary_search(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // target found
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

    return -1; // target not found
}

// Function to fill array with random numbers
void fill_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill with random numbers between 0 and 99
    }
}

// Function to print the array
void print_array(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Fill array with random numbers and print it
    fill_array(arr, size);
    print_array(arr, size);

    // Sort the array using quicksort
    qsort(arr, size, sizeof(int), compare);
    printf("Sorted ");
    print_array(arr, size);

    // Ask user for target number to search
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binary_search(arr, size, target);
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}