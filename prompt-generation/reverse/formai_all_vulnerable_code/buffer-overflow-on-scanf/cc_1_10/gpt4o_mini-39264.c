//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculate_mean(double* results, int size);
double calculate_standard_deviation(double* results, int size, double mean);
void run_experiment(int num_experiments);
void free_memory(double* data);

int main() {
    int num_experiments;

    // Input the number of experiments
    printf("Enter the number of experiments to run: ");
    scanf("%d", &num_experiments);

    if (num_experiments <= 0) {
        printf("Number of experiments must be a positive integer.\n");
        return 1;
    }

    run_experiment(num_experiments);

    return 0;
}

void run_experiment(int num_experiments) {
    double* results = (double*)malloc(num_experiments * sizeof(double));
    
    // Check if memory allocation was successful
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Simulate experiment results with random numbers
    for (int i = 0; i < num_experiments; i++) {
        results[i] = (double)(rand() % 100) / 10.0; // Random results between 0.0 and 9.9
    }

    // Calculate mean
    double mean = calculate_mean(results, num_experiments);
    printf("Mean of the results: %.2lf\n", mean);

    // Calculate standard deviation
    double stddev = calculate_standard_deviation(results, num_experiments, mean);
    printf("Standard Deviation of the results: %.2lf\n", stddev);

    // Free allocated memory
    free_memory(results);
}

double calculate_mean(double* results, int size) {
    double sum = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum += results[i];
    }
    
    return sum / size;
}

double calculate_standard_deviation(double* results, int size, double mean) {
    double sum_squared_diff = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum_squared_diff += (results[i] - mean) * (results[i] - mean);
    }
    
    return sqrt(sum_squared_diff / size);
}

void free_memory(double* data) {
    free(data);
    printf("Memory freed successfully.\n");
}