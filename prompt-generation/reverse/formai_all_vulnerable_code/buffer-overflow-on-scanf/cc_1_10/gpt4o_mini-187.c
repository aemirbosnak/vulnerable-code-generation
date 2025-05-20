//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition function for Quick Sort */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Quick Sort function */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

/* Function to print the array */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Function to generate an array of random numbers */
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random number between 0 and 999
    }
}

/* Main function */
int main() {
    int size;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Number of elements should be a positive integer.\n");
        return 1;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateRandomArray(arr, size);

    printf("Unsorted array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}