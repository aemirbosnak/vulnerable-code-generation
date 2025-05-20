//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define PI 3.14159265358979323846

int main() {
    int size;
    double *array;
    int *permutation;
    double sum = 0, mean, variance, std_dev;
    int i, j, k, index;
    clock_t start, end;

    // Get array size from user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Allocate memory for array and permutation
    array = (double *) malloc(size * sizeof(double));
    permutation = (int *) malloc(size * sizeof(int));

    // Generate random array and permutation
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    for (i = 0; i < size; i++) {
        permutation[i] = i;
    }

    // Calculate mean, variance, and standard deviation
    start = clock();
    for (k = 0; k < 10; k++) {
        for (i = 0; i < size; i++) {
            index = permutation[i];
            permutation[i] = permutation[rand() % size];
            permutation[index] = i;
        }
        for (i = 0; i < size; i++) {
            sum += array[permutation[i]];
        }
    }
    end = clock();
    mean = sum / size;
    variance = 0;
    for (i = 0; i < size; i++) {
        variance += pow(array[i] - mean, 2);
    }
    variance /= size;
    std_dev = sqrt(variance);

    // Print results
    printf("Random array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard deviation: %.2f\n", std_dev);
    printf("Time taken: %.2fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free memory
    free(array);
    free(permutation);

    return 0;
}