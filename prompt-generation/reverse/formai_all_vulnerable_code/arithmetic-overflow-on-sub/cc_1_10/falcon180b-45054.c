//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Function to fill an array with random numbers
void fill_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to sort an array using quicksort
void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    // Partition
    while (i <= j) {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Recursion
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    int size;

    // Get array size from user input
    printf("Enter array size: ");
    scanf("%d", &size);

    // Allocate memory for array
    int *arr = (int *)malloc(size * sizeof(int));

    // Fill array with random numbers
    fill_array(arr, size);

    // Sort array using quicksort
    quicksort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}