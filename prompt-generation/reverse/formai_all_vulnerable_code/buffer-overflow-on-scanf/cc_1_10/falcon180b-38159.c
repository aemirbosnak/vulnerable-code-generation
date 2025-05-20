//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform the binary search
int binary_search(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = partition(arr, low, high);

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            return binary_search(arr, low, mid - 1, target);
        } else {
            return binary_search(arr, mid + 1, high, target);
        }
    }
    return -1;
}

// Function to perform the linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX];
    int size, target;

    // Read the array from user input
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }

    // Ask user to choose between binary search and linear search
    printf("Choose the type of search:\n1. Binary Search\n2. Linear Search\n");
    scanf("%d", &target);

    if (target == 1) {
        // Perform binary search
        int result = binary_search(arr, 0, size - 1, target);

        if (result == -1) {
            printf("Element not found in the array.\n");
        } else {
            printf("Element found at index %d.\n", result);
        }
    } else if (target == 2) {
        // Perform linear search
        int result = linear_search(arr, size, target);

        if (result == -1) {
            printf("Element not found in the array.\n");
        } else {
            printf("Element found at index %d.\n", result);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}