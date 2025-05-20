//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void inputNumbers(int **arr, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    
    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void sortArray(int *arr, int size) {
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
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            return middle; // Found the target
        }
        if (arr[middle] < target) {
            left = middle + 1; // Search in right half
        } else {
            right = middle - 1; // Search in left half
        }
    }
    return -1; // Target not found
}

void freeMemory(int **arr) {
    free(*arr);
    *arr = NULL; // Avoid dangling pointer
}

int main() {
    int *arr = NULL;
    int size = 0;

    inputNumbers(&arr, &size);

    sortArray(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the integer to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    freeMemory(&arr);
    return 0;
}