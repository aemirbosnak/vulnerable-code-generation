//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(int argc, char **argv) {

    int i, j, k, n, sum = 0;
    int *arr1, *arr2;
    clock_t start, end;
    double cpu_time_used;

    printf("Welcome to the Kingdom of Benchmarking!\n");
    printf("We shall test the might of thy code by calculating the sum of two arrays.\n");
    printf("Fear not, for we have prepared two arrays of size %d each.\n", MAX_SIZE);

    // Allocate memory for the arrays
    arr1 = (int *) malloc(MAX_SIZE * sizeof(int));
    arr2 = (int *) malloc(MAX_SIZE * sizeof(int));

    // Initialize the arrays with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Calculate the sum of the arrays
    for (i = 0; i < MAX_SIZE; i++) {
        sum += arr1[i] + arr2[i];
    }

    // Stop the timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the result
    printf("The sum of the two arrays is: %d\n", sum);
    printf("The time taken to calculate the sum is: %.6f seconds\n", cpu_time_used);

    // Free the memory
    free(arr1);
    free(arr2);

    return 0;
}