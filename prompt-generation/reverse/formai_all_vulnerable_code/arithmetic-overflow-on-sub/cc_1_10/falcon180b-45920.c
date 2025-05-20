//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 1000000 // Maximum size of the array
#define MIN_VALUE 1 // Minimum value in the array
#define MAX_VALUE 1000000 // Maximum value in the array

int main() {
    int size, i;
    int *array;
    double start_time, end_time;

    // Prompt user for array size
    printf("Enter array size (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &size);

    // Allocate memory for array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    // Sort the array
    start_time = clock();
    for (i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    end_time = clock();

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print execution time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", elapsed_time);

    // Free memory for array
    free(array);

    return 0;
}