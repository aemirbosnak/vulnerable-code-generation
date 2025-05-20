//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int *array;
    int size;
    int i;
    int sum = 0;
    clock_t start_time, end_time;

    // Allocate memory for the array
    array = (int *) malloc(MAX_SIZE * sizeof(int));

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the size is within the bounds of the array
    if (size > MAX_SIZE) {
        printf("Size is too large for the array.\n");
        exit(1);
    }

    // Calculate the sum of the array
    start_time = clock();
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    end_time = clock();

    // Calculate the time taken to calculate the sum
    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Print the sum and time taken
    printf("Sum of the array: %d\n", sum);
    printf("Time taken: %.6f seconds\n", time_taken);

    // Free the memory allocated for the array
    free(array);

    return 0;
}