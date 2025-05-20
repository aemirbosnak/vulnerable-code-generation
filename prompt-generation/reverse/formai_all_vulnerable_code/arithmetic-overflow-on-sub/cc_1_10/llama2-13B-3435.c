//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// A function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// A function to sort the array using selection sort
void sort(int arr[]) {
    int i, j, min_idx;

    // Loop until the end of the array
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        // Find the smallest element in the unsorted portion of the array
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the smallest element with the first element of the unsorted portion
        swap(arr, min_idx, i);
    }
}

// Main function
int main() {
    int arr[ARRAY_SIZE] = {8, 3, 2, 1, 4, 6, 5, 7, 0};
    clock_t start, end;

    // Start the clock
    start = clock();

    // Sort the array using selection sort
    sort(arr);

    // End the clock
    end = clock();

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken to sort: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}