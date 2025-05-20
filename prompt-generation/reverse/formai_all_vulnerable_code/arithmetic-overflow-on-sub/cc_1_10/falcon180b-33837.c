//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n, i, j, sum;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Initialize the arrays
    int *array1 = (int *) malloc(n * sizeof(int));
    int *array2 = (int *) malloc(n * sizeof(int));
    int *array3 = (int *) malloc(n * sizeof(int));

    // Fill the arrays with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Perform the addition
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += array1[i] + array2[j];
        }
        array3[i] = sum;
    }

    // Stop the timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("The sum of two arrays is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array3[i]);
    }
    printf("\n");
    printf("Time taken: %lf seconds\n", cpu_time_used);

    // Free the memory
    free(array1);
    free(array2);
    free(array3);

    return 0;
}