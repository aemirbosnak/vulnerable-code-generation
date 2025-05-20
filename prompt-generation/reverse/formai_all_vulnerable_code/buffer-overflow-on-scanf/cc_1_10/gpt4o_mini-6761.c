//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void displayMenu();
void inputArray(int arr[], int *size);
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int size, int key);
void sortArray(int arr[], int size);
void displayArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, key, index;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;

            case 2:
                if (size > 0) {
                    printf("Array: ");
                    displayArray(arr, size);
                } else {
                    printf("Array is empty!\n");
                }
                break;

            case 3:
                if (size > 0) {
                    printf("Enter the key to search: ");
                    scanf("%d", &key);
                    index = linearSearch(arr, size, key);
                    if (index != -1) {
                        printf("Element found at index: %d\n", index);
                    } else {
                        printf("Element not found in the array.\n");
                    }
                } else {
                    printf("Array is empty!\n");
                }
                break;

            case 4:
                if (size > 0) {
                    sortArray(arr, size);
                    printf("Array sorted!\n");
                    displayArray(arr, size);
                } else {
                    printf("Array is empty!\n");
                }
                break;

            case 5:
                if (size > 0) {
                    printf("Enter the key to search: ");
                    scanf("%d", &key);
                    sortArray(arr, size); // Ensure the array is sorted
                    index = binarySearch(arr, size, key);
                    if (index != -1) {
                        printf("Element found at index: %d\n", index);
                    } else {
                        printf("Element not found in the array.\n");
                    }
                } else {
                    printf("Array is empty!\n");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Array Search Program ---\n");
    printf("1. Input Array\n");
    printf("2. Display Array\n");
    printf("3. Linear Search\n");
    printf("4. Sort Array\n");
    printf("5. Binary Search\n");
    printf("6. Exit\n");
}

void inputArray(int arr[], int *size) {
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size > MAX_SIZE) {
        printf("Exceeded maximum size! Reducing size to %d.\n", MAX_SIZE);
        *size = MAX_SIZE;
    }

    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Not found
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}