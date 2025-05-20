//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

int main() {
    int size;
    double *array;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = (double*) malloc(size * sizeof(double));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }

    // Perform some calculations on the array
    double sum = 0.0;
    double mean = 0.0;
    double variance = 0.0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    mean = sum / size;

    for (int i = 0; i < size; i++) {
        variance += pow(array[i] - mean, 2);
    }

    variance /= size;

    // Print the results
    printf("Mean: %.2lf\n", mean);
    printf("Variance: %.2lf\n", variance);

    // Free the memory allocated for the array
    free(array);

    return 0;
}