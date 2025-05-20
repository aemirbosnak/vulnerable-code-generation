//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(int argc, char *argv[]) {
    int i, j;
    int *array;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for the array
    array = (int *) malloc(MAX_SIZE * sizeof(int));

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Sort the array using bubble sort
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure the time taken to sort the array
    start = clock();
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken to sort the array: %.6f seconds\n", cpu_time_used);

    free(array);
    return 0;
}