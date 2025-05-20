//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    
    return -1;  // Target not found
}

// Function to initialize and populate the array
void populate_array(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < size; i++) {
        (*arr)[i] = rand() % 100;  // Random numbers between 0 and 99
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

int main() {
    int *arr = NULL;
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    populate_array(&arr, size);
    display_array(arr, size);
    
    // Sort the array before searching
    qsort(arr, size, sizeof(int), compare);
    
    printf("Sorted array: ");
    display_array(arr, size);
    
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    
    int result = binary_search(arr, size, target);
    
    if (result != -1) {
        printf("Number %d found at index: %d\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    
    free(arr);  // Free the allocated memory
    return 0;
}