//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomSortedArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Generate numbers between 0 and 99
    }
    // Sorting array using bubble sort
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

int binarySearch(int *arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Target not found
}

void displayArray(int *arr, int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Size must be a positive integer.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateRandomSortedArray(arr, size);
    displayArray(arr, size);
    
    int target;
    printf("Enter the number you wish to search for: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    
    free(arr); // Release allocated memory
    return 0;
}