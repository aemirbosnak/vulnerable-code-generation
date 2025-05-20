//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    // Declare variables
    int size = 0;
    int *array = NULL;
    clock_t start, end;
    double time_taken = 0.0;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error allocating memory for the array\n");
        return 1;
    }

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }

    // Start the clock
    start = clock();

    // Sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Stop the clock
    end = clock();

    // Calculate the time taken to sort the array
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the time taken to sort the array
    printf("Time taken to sort the array: %f seconds\n", time_taken);

    // Free the memory allocated for the array
    free(array);

    return 0;
}