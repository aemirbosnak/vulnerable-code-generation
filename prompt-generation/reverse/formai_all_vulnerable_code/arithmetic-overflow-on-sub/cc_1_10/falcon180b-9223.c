//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of the array

// Function prototypes
int binarySearch(int arr[], int size, int target);
void selectionSort(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    selectionSort(arr, size);

    // Prompt user to enter the target element
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Perform binary search on the sorted array
    int result = binarySearch(arr, size, target);

    // Print the result of the binary search
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}

// Binary search function
int binarySearch(int arr[], int size, int target) {
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

// Selection sort function
void selectionSort(int arr[], int size) {
    int minIndex;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}