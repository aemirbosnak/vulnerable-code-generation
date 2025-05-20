//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_SIZE 1

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Check if array size is valid
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid array size\n");
        return 1;
    }

    // Dynamically allocate memory for array
    int* arr = (int*) malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate random array
    generateRandomArray(arr, size);

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort array using quicksort
    quicksort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}