//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void inputArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    // Array declaration
    int arr[MAX_SIZE];
    int n;

    // Prompt the user for the number of elements
    printf("************************************\n");
    printf("* Welcome to the Bubble Sort Game! *\n");
    printf("************************************\n");
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements! Exiting...\n");
        return 1;
    }

    // Inputting array elements
    inputArray(arr, n);

    // Display the unsorted array
    printf("\nUnsorted array:\n");
    printArray(arr, n);

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Display the sorted array
    printf("\nSorted array:\n");
    printArray(arr, n);
    printf("\nThank you for playing!\n");

    return 0;
}

// Function to input array elements
void inputArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}