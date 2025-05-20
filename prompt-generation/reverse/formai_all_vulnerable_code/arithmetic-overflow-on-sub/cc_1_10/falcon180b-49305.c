//Falcon-180B DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createArray(int*, int);
void printArray(int*, int);
void sortArray(int*, int);
void searchElement(int*, int, int);

int main() {
    int size;

    // Get array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Create array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill array with random numbers
    createArray(arr, size);

    // Print unsorted array
    printf("\nUnsorted array:\n");
    printArray(arr, size);

    // Sort array
    sortArray(arr, size);

    // Print sorted array
    printf("\nSorted array:\n");
    printArray(arr, size);

    // Search for an element in the sorted array
    int element;
    printf("\nEnter the element to search: ");
    scanf("%d", &element);
    searchElement(arr, size, element);

    // Free memory
    free(arr);

    return 0;
}

// Function to create an array with random numbers
void createArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array
void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to search for an element in a sorted array
void searchElement(int* arr, int size, int element) {
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }
}