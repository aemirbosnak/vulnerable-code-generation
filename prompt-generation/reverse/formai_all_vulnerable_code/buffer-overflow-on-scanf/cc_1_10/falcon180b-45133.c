//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

// Function to generate random numbers
double generateRandomNumber() {
    return rand() / (double)RAND_MAX;
}

// Function to calculate sum of squares
double calculateSumOfSquares(double* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i], 2.0);
    }
    return sum;
}

// Function to calculate mean
double calculateMean(double* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate standard deviation
double calculateStandardDeviation(double* arr, int size) {
    double mean = calculateMean(arr, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2.0);
    }
    return sqrt(sum / size);
}

int main() {
    double* arr;
    int size;

    // Allocate memory for array
    arr = (double*)malloc(MAX_SIZE * sizeof(double));

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Generate random numbers and fill array
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber();
    }

    // Calculate sum of squares, mean, and standard deviation
    double sumOfSquares = calculateSumOfSquares(arr, size);
    double mean = calculateMean(arr, size);
    double standardDeviation = calculateStandardDeviation(arr, size);

    // Print results
    printf("Sum of squares: %.2f\n", sumOfSquares);
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", standardDeviation);

    // Free memory
    free(arr);

    return 0;
}