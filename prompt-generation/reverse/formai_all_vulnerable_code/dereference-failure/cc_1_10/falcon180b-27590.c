//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000
#define NUM_ITERATIONS 100

int main() {
    int *array = (int *) malloc(SIZE * sizeof(int));
    int sum = 0;
    double start_time, end_time;
    int i, j;

    srand(time(NULL));

    // Fill the array with random numbers between 0 and 999
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Sort the array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Calculate the sum of the sorted array
    for (i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // Measure the time taken to sort the array
    start_time = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end_time = clock();

    // Calculate the average time taken to sort the array
    double avg_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Print the results
    printf("Sum of sorted array: %d\n", sum);
    printf("Average time taken to sort the array: %.6f seconds\n", avg_time);

    free(array);
    return 0;
}