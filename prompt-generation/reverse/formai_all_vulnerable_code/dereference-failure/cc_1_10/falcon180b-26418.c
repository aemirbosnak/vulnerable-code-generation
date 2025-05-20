//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function prototypes
void createArray(int*, int);
void printArray(int*, int);
int binarySearch(int*, int, int);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    createArray(arr, size);
    printArray(arr, size);

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    free(arr);
    return 0;
}

// Creates an array of given size with random elements
void createArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Prints the elements of an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Performs binary search on a sorted array
int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}