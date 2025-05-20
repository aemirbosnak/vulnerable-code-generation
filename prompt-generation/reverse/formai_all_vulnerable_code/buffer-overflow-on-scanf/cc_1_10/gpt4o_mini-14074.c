//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 100

// Function prototypes
void collect_data(int *samples, int count);
double calculate_mean(int *samples, int count);
double calculate_variance(int *samples, int count, double mean);
void handle_error(const char *message, int error_code);

// Main function
int main() {
    int samples[MAX_SAMPLES];
    int sample_count;

    printf("Welcome to the Statistical Data Collector!\n");
    printf("Enter the number of samples you want to collect (max %d): ", MAX_SAMPLES);
    
    // User input for number of samples
    if (scanf("%d", &sample_count) != 1) {
        handle_error("Invalid input for the number of samples.", 1);
    }
    
    // Check if sample count is valid
    if (sample_count <= 0 || sample_count > MAX_SAMPLES) {
        handle_error("Sample count must be between 1 and 100.", 2);
    }
    
    // Collect samples
    collect_data(samples, sample_count);
    
    // Calculate mean
    double mean = calculate_mean(samples, sample_count);
    printf("Mean of samples: %.2f\n", mean);
    
    // Calculate variance
    double variance = calculate_variance(samples, sample_count, mean);
    printf("Variance of samples: %.2f\n", variance);
    
    return 0;
}

// Function to collect data from user
void collect_data(int *samples, int count) {
    printf("Please enter %d sample values:\n", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &samples[i]) != 1) {
            handle_error("Invalid input for sample value.", 3);
        }
    }
}

// Function to calculate mean
double calculate_mean(int *samples, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += samples[i];
    }
    return sum / count;
}

// Function to calculate variance
double calculate_variance(int *samples, int count, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < count; i++) {
        sum_squared_diff += pow(samples[i] - mean, 2);
    }
    return sum_squared_diff / count;
}

// Function to handle errors
void handle_error(const char *message, int error_code) {
    fprintf(stderr, "Error %d: %s\n", error_code, message);
    exit(error_code);
}