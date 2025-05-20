//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 100000

// Function prototypes
double calculate_mean(double *samples, int num_samples);
double calculate_variance(double *samples, int num_samples, double mean);
double calculate_probability_of_invasion(double mean, double variance);

// Main Function
int main() {
    int num_samples;
    double *samples, mean, variance, invasion_probability;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of invasion samples to evaluate (up to %d): ", MAX_SAMPLES);
    scanf("%d", &num_samples);

    // Validate user input
    if(num_samples <= 0 || num_samples > MAX_SAMPLES) {
        printf("Invalid number of samples. Please enter a value between 1 and %d.\n", MAX_SAMPLES);
        return 1;
    }

    // Allocate memory for samples
    samples = (double *)malloc(num_samples * sizeof(double));
    if(samples == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }
    
    // Generate random invasion data (hypothetical for our model)
    for(int i = 0; i < num_samples; i++) {
        samples[i] = (double)(rand() % 100 + 1); // Generate random probability between 1 and 100
    }
    
    // Calculate mean and variance
    mean = calculate_mean(samples, num_samples);
    variance = calculate_variance(samples, num_samples, mean);

    // Calculate the probability of invasion
    invasion_probability = calculate_probability_of_invasion(mean, variance);

    // Output results
    printf("Mean of invasion samples: %.2f\n", mean);
    printf("Variance of invasion samples: %.2f\n", variance);
    printf("Estimated probability of alien invasion: %.2f%%\n", invasion_probability * 100);

    // Free allocated memory
    free(samples);
    
    return 0;
}

// Calculate mean of the samples
double calculate_mean(double *samples, int num_samples) {
    double sum = 0.0;
    for(int i = 0; i < num_samples; i++) {
        sum += samples[i];
    }
    return sum / num_samples;
}

// Calculate variance of the samples
double calculate_variance(double *samples, int num_samples, double mean) {
    double sum_squared_diff = 0.0;
    for(int i = 0; i < num_samples; i++) {
        sum_squared_diff += (samples[i] - mean) * (samples[i] - mean);
    }
    return sum_squared_diff / (num_samples - 1); // sample variance
}

// Calculate probability of invasion based on mean and variance
double calculate_probability_of_invasion(double mean, double variance) {
    // Using a hypothetical model to determine probability
    double probability = 1 / (1 + exp(-(mean - 50) / (sqrt(variance) + 1))); // Logistic function for scaling
    return probability;
}