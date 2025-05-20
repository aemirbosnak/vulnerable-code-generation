//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to generate random numbers with a normal distribution
double generateRandomNumber(double mean, double standardDeviation) {
    double u1 = rand() / (double) RAND_MAX;
    double u2 = rand() / (double) RAND_MAX;
    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mean + z * standardDeviation;
}

// Function to calculate the mean of an array of numbers
double calculateMean(double* numbers, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array of numbers
double calculateStandardDeviation(double* numbers, int size) {
    double mean = calculateMean(numbers, size);
    double sumSquaredDifferences = 0.0;
    for (int i = 0; i < size; i++) {
        sumSquaredDifferences += pow(numbers[i] - mean, 2.0);
    }
    return sqrt(sumSquaredDifferences / size);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    double* numbers = malloc(sizeof(double) * size);

    // Fill the array with random numbers
    for (int i = 0; i < size; i++) {
        numbers[i] = generateRandomNumber(0.0, 1.0);
    }

    // Calculate mean and standard deviation
    double mean = calculateMean(numbers, size);
    double standardDeviation = calculateStandardDeviation(numbers, size);

    // Print results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", standardDeviation);

    free(numbers);
    return 0;
}