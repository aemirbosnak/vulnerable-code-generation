//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void inputArray(int arr[], int size);
void printArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size, choice, target, result;

    printf("Enter the number of elements in the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    if(size > MAX_SIZE || size <= 0) {
        fprintf(stderr, "Error: Size must be between 1 and %d.\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    inputArray(arr, size);

    printf("Choose Search Method:\n1. Linear Search\n2. Binary Search (sorted array required)\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the target number to search (Linear Search): ");
            scanf("%d", &target);
            result = linearSearch(arr, size, target);
            if (result != -1) {
                printf("Element %d found at index %d (Linear Search).\n", target, result);
            } else {
                printf("Element %d not found (Linear Search).\n", target);
            }
            break;
        
        case 2:
            sortArray(arr, size);
            printf("Sorted Array:\n");
            printArray(arr, size);
            printf("Enter the target number to search (Binary Search): ");
            scanf("%d", &target);
            result = binarySearch(arr, size, target);
            if (result != -1) {
                printf("Element %d found at index %d (Binary Search).\n", target, result);
            } else {
                printf("Element %d not found (Binary Search).\n", target);
            }
            break;

        default:
            fprintf(stderr, "Error: Invalid choice.\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void inputArray(int arr[], int size) {
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}