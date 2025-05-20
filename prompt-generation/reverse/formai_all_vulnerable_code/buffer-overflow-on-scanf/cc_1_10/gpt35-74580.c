//FormAI DATASET v1.0 Category: Data mining ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the maximum limit for the dataset
#define MAX_LIMIT 200

// calculate the mean value of a dataset
float calculate_mean(float dataset[], int n) {
    float mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += dataset[i];
    }
    mean /= n;
    return mean;
}

// calculate the standard deviation of a dataset
float calculate_standard_deviation(float dataset[], int n, float mean) {
    float standard_deviation = 0.0;
    for (int i = 0; i < n; i++) {
        standard_deviation += pow(dataset[i] - mean, 2);
    }
    standard_deviation /= n;
    standard_deviation = sqrt(standard_deviation);
    return standard_deviation;
}

// main function to demonstrate data mining techniques
int main() {
    float dataset[MAX_LIMIT];
    int n;

    // read the dataset from input
    printf("Enter the number of elements in the dataset: ");
    scanf("%d", &n);
    printf("Enter the dataset: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &dataset[i]);
    }

    // calculate the mean and standard deviation of the dataset
    float mean = calculate_mean(dataset, n);
    float standard_deviation = calculate_standard_deviation(dataset, n, mean);

    // output the results
    printf("\nMean = %f", mean);
    printf("\nStandard Deviation = %f", standard_deviation);

    return 0;
}