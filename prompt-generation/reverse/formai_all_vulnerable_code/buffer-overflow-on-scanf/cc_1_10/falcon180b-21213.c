//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int size;
    int *array;
    int i;
    double mean, variance;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Get the elements of the array from the user
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Calculate the mean and variance of the array
    mean = 0.0;
    for (i = 0; i < size; i++) {
        mean += array[i];
    }
    mean /= size;

    variance = 0.0;
    for (i = 0; i < size; i++) {
        variance += pow(array[i] - mean, 2);
    }
    variance /= size;

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);

    // Free the memory allocated for the array
    free(array);

    return 0;
}