//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100
#define ARRAY_SIZE 10

int main() {

    int array[ARRAY_SIZE];
    int sum = 0, product = 1;
    double mean, variance, standard_deviation;

    // Seed the random number generator
    srand(time(0));

    // Generate 10 random integers between 1 and 100 and store them in the array
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % (MAX - MIN + 1) + MIN;
        printf("%d ", array[i]);
    }

    // Calculate the sum and product of the array
    for(int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
        product *= array[i];
    }

    // Calculate the mean of the array
    mean = (double)sum / ARRAY_SIZE;

    // Calculate the variance of the array
    variance = 0;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        variance += ((double)array[i] - mean) * ((double)array[i] - mean);
    }
    variance /= ARRAY_SIZE;

    // Calculate the standard deviation of the array
    standard_deviation = sqrt(variance);

    printf("\n\nSum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", standard_deviation);

    return 0;
}