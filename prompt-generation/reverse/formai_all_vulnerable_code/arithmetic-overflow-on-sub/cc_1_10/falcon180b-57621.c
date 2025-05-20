//Falcon-180B DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a random array of integers
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to perform bubble sort on an array
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
    int size;

    // Get size of array from user
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Generate random array
    generateRandomArray(arr, size);

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort array using bubble sort
    bubbleSort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}