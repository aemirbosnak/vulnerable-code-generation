//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the error codes
#define ERR_INVALID_INPUT 1
#define ERR_DIVIDE_BY_ZERO 2
#define ERR_OUT_OF_RANGE 3

// Define the function to calculate the mean
double calculate_mean(int *data, int n) {
    if (data == NULL || n <= 0) {
        return ERR_INVALID_INPUT;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum / n;
}

// Define the function to calculate the standard deviation
double calculate_standard_deviation(int *data, int n) {
    if (data == NULL || n <= 0) {
        return ERR_INVALID_INPUT;
    }

    double mean = calculate_mean(data, n);
    if (mean == ERR_INVALID_INPUT) {
        return ERR_INVALID_INPUT;
    }

    double sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += pow(data[i] - mean, 2);
    }

    return sqrt(sum_of_squares / (n - 1));
}

// Define the main function
int main() {
    // Get the data from the user
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    int *data = (int *)malloc(n * sizeof(int));
    if (data == NULL) {
        printf("Error: Could not allocate memory for data.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the mean and standard deviation
    double mean = calculate_mean(data, n);
    if (mean == ERR_INVALID_INPUT) {
        printf("Error: Invalid input data.\n");
        free(data);
        return EXIT_FAILURE;
    }

    double standard_deviation = calculate_standard_deviation(data, n);
    if (standard_deviation == ERR_INVALID_INPUT) {
        printf("Error: Invalid input data.\n");
        free(data);
        return EXIT_FAILURE;
    }

    // Print the mean and standard deviation
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", standard_deviation);

    // Free the allocated memory
    free(data);

    return EXIT_SUCCESS;
}