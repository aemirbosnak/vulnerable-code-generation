//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of iterations to perform
#define NUM_ITERATIONS 1000000

// Define the size of the array to sort
#define ARRAY_SIZE 1000000

// Function to sort an array using bubble sort
void bubble_sort(int *array, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to measure the execution time of a function
double measure_execution_time(void (*function)()) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    function();
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main() {
    // Initialize the array with random values
    int *array = malloc(ARRAY_SIZE * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Sort the array using bubble sort
    bubble_sort(array, ARRAY_SIZE);

    // Measure the execution time of bubble sort
    double execution_time = measure_execution_time(bubble_sort);

    // Print the sorted array and execution time
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Execution time: %.6f seconds\n", execution_time);

    free(array);
    return 0;
}