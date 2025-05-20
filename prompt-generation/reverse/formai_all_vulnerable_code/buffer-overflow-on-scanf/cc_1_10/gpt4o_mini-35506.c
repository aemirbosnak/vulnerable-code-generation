//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1); // Index of smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search algorithm
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }
        if (arr[mid] < target) {
            low = mid + 1; // Target is in right half
        } else {
            high = mid - 1; // Target is in left half
        }
    }
    return -1; // Element not found
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Entry point of the program
int main() {
    int *arr;
    int size, target, index;
    int choice;

    printf("Welcome to the Custom Search Program!\n");
    printf("Please enter the number of elements you want to sort: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input the array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    quickSort(arr, 0, size - 1);
    printf("Sorted array: ");
    printArray(arr, size);

    while (1) {
        printf("Menu:\n");
        printf("1. Search for an element\n");
        printf("2. Display the sorted array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                index = binarySearch(arr, size, target);

                if (index != -1) {
                    printf("Element %d found at index %d.\n", target, index);
                } else {
                    printf("Element %d not found in the array.\n", target);
                }
                break;

            case 2:
                printf("Sorted array: ");
                printArray(arr, size);
                break;

            case 3:
                free(arr);
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(arr);
    return 0;
}