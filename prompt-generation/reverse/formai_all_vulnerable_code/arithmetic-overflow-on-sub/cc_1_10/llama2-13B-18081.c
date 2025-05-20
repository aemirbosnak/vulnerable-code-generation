//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using selection sort
void sort(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

// Main function
int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Start the clock
    clock_t start = clock();

    // Sort the array using selection sort
    sort(arr, n);

    // End the clock
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}