//Falcon-180B DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate random numbers
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &arr[0]);

    // Check if the size of the array is within the limit
    if (arr[0] <= 0 || arr[0] > MAX_SIZE) {
        printf("Invalid size of the array.\n");
        return 0;
    }

    // Generate random numbers and fill the array
    generateRandomArray(arr, arr[0]);

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, arr[0]);

    // Sort the array using bubble sort
    bubbleSort(arr, arr[0]);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, arr[0]);

    return 0;
}