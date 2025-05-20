//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void displayArray(int* arr, int size) {
    printf("Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* arr, int size, int target) {
    int left = 0, right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid; // Target found at index mid
        }
        if(arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

void freeMemory(int* arr) {
    free(arr);
}

int main() {
    int size, target, result;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if(size <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1; // Exit if invalid size
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit on memory allocation failure
    }

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);
    displayArray(arr, size);

    printf("Enter a number to search for: ");
    scanf("%d", &target);

    result = binarySearch(arr, size, target);
    
    if(result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    freeMemory(arr); // Free up allocated memory
    return 0; // Indicate successful program termination
}