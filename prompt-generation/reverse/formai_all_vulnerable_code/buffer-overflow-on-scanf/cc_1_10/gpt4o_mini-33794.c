//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("Current Array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int binarySearch(int arr[], int left, int right, int target) {
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        printf("Searching at index %d: Current middle element is %d\n", mid, arr[mid]);

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        printArray(arr, right - left + 1);
    }
    
    return -1; // Element not found
}

void divideArray(int arr[], int size) {
    if (size < 1) return;

    printf("\nDividing array for interleaved searching...\n");
    int mid = size / 2;

    printf("Left part: [ ");
    for (int i = 0; i < mid; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    printf("Right part: [ ");
    for (int i = mid; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int interleavedSearch(int arr[], int size, int target) {
    int foundIndex = -1;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        printf("Interleaved searching...\n");
        printArray(arr, size);
        int mid = left + (right - left) / 2;

        if (arr[left] == target || arr[right] == target || arr[mid] == target) {
            return (arr[left] == target) ? left : (arr[right] == target) ? right : mid;
        }

        if (left + 1 < right) {
            // Checking neighbors as well
            if (arr[left + 1] == target) return left + 1;
            if (arr[right - 1] == target) return right - 1;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return foundIndex;
}

int main() {
    int arrSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrSize);
    if (arrSize <= 0) {
        printf("Invalid Array Size\n");
        return -1;
    }

    int *arr = (int *)malloc(arrSize * sizeof(int));
    
    printf("Enter the elements (sorted): \n");
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    printf("\nStarting Binary Search...\n");
    int binaryIndex = binarySearch(arr, 0, arrSize - 1, target);
    if (binaryIndex != -1) {
        printf("Element %d found at index %d using Binary Search.\n", target, binaryIndex);
    } else {
        printf("Element %d not found using Binary Search.\n", target);
    }

    divideArray(arr, arrSize);

    printf("\nStarting Interleaved Search...\n");
    int interleavedIndex = interleavedSearch(arr, arrSize, target);
    if (interleavedIndex != -1) {
        printf("Element %d found at index %d using Interleaved Search.\n", target, interleavedIndex);
    } else {
        printf("Element %d not found using Interleaved Search.\n", target);
    }

    free(arr);
    return 0;
}