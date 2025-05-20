//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 1000

// Function to generate a random integer within the given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element in the array
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

    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size;
    int target;

    // Get the size of the array from the user
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Initialize the array with random integers
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(MIN_VALUE, MAX_VALUE);
    }

    // Print the original array
    printf("Original array:\n");
    printArray(arr, size);

    // Get the target element from the user
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Search for the target element using binary search
    int result = binarySearch(arr, size, target);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}