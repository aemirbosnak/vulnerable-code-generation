//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

// A paranoid C benchmarking program that may overthink every detail.

// Function to execute benchmarking on the sorting algorithm
void benchmark_sort(int *arr, int size, int *elapsed_time) {
    clock_t start, end;

    // A paranoid check for null array
    if (arr == NULL || size <= 0) {
        fprintf(stderr, "Error: Invalid array or size.\n");
        return;
    }

    start = clock(); // Start timing

    // Implementing Bubble Sort (not the most efficient, but illustrative)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Check for a moment if comparing elements is worthwhile
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are not in order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Get the end time
    end = clock();
    *elapsed_time = (int)((end - start) * 1000 / CLOCKS_PER_SEC); // in milliseconds

    // Log the paranoid success
    printf("Sorting complete. Elapsed time: %d ms\n", *elapsed_time);
}

// Function to generate an array filled with random integers
int *generate_random_array(int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Invalid size for array generation.\n");
        return NULL;
    }

    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Seed the random number generator more paranoidly
    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % INT_MAX; // Fill with random integers
    }

    return arr;
}

// Function to validate array's order
int validate_array_order(int *arr, int size) {
    // Check for a sensible size
    if (arr == NULL || size <= 0) {
        fprintf(stderr, "Error: Invalid array or size during validation.\n");
        return 0; // Consider invalid
    }

    for (int i = 0; i < size - 1; i++) {
        // Overly paranoid: Ensure every comparison is logged
        if (arr[i] > arr[i + 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main() {
    int size;
    
    // Paranoid input: Ensure the user knows what size they should pick
    printf("Enter the size of the array (positive integer): ");
    scanf("%d", &size);

    if (size <= 0) {
        fprintf(stderr, "Error: Size must be a positive integer. Exiting program...\n");
        return EXIT_FAILURE;
    }

    // Generate a random array to benchmark
    int *arr = generate_random_array(size);
    if (arr == NULL) {
        // Memory allocation failure handled in the function
        return EXIT_FAILURE;
    }

    int elapsed_time;
    benchmark_sort(arr, size, &elapsed_time);

    // Validate the sorted order
    if (validate_array_order(arr, size)) {
        printf("Array is sorted correctly!\n");
    } else {
        fprintf(stderr, "Error: Sorting failed or array is not sorted!\n");
    }

    // Memory cleanup
    free(arr);
    arr = NULL; // Overly cautious; set pointer to NULL after free

    return EXIT_SUCCESS;
}