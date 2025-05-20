//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 100

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort the array using selection sort
void sort(int arr[]) {
    int i, j, min_idx;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr, min_idx, i);
    }
}

// Function to print the sorted array
void print_array(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE] = {34, 21, 67, 43, 19, 92, 76, 40, 27, 12};
    clock_t start, end;
    double elapsed_time;

    // Start the clock
    start = clock();

    // Sort the array using selection sort
    sort(arr);

    // End the clock
    end = clock();

    // Calculate the elapsed time
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the sorted array
    print_array(arr);

    printf("Sorting took %f seconds\n", elapsed_time);

    return 0;
}