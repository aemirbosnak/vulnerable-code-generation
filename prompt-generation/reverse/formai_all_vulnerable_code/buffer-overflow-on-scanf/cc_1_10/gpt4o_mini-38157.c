//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_LENGTH 100

// Function to display the menu
void displayMenu() {
    printf("=== Search Algorithm Menu ===\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function for linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

// Function for binary search (requires a sorted array)
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int arr[MAX_ELEMENTS];
    int size;

    printf("Enter the number of elements in the array (max %d): ", MAX_ELEMENTS);
    scanf("%d", &size);

    // Input validation
    if (size <= 0 || size > MAX_ELEMENTS) {
        printf("Invalid size. Please try again.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        int target;
        printf("Enter the number to search: ");
        scanf("%d", &target);

        switch (choice) {
            case 1:
                // Linear Search
                {
                    int result = linearSearch(arr, size, target);
                    if (result != -1) {
                        printf("Linear Search: %d found at index %d\n", target, result);
                    } else {
                        printf("Linear Search: %d not found in the array\n", target);
                    }
                }
                break;
            case 2:
                // Binary Search (requires sorting first)
                bubbleSort(arr, size);
                printf("Array sorted for Binary Search.\n");
                {
                    int result = binarySearch(arr, size, target);
                    if (result != -1) {
                        printf("Binary Search: %d found at index %d\n", target, result);
                    } else {
                        printf("Binary Search: %d not found in the array\n", target);
                    }
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}