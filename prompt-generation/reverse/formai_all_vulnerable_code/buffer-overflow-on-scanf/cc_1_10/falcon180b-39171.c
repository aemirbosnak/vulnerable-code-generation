//Falcon-180B DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to swap elements in an array
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

// Function to generate a random array
void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Ask user for array size
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Generate random array
    generateArray(arr, size);

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Perform selection sort
    selectionSort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}