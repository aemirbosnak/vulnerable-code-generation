//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define NUM_ITERATIONS 100
#define DATA_SIZE 1024 * 1024 // 1MB

// Forward declarations
double calculate_average(double *values, int num_values);
double calculate_standard_deviation(double *values, int num_values);
double calculate_confidence_interval(double avg, double std_dev, int num_iterations);

int main(void) {
    // Initialize variables
    int i;
    double *download_times = (double *)malloc(NUM_ITERATIONS * sizeof(double));
    double *upload_times = (double *)malloc(NUM_ITERATIONS * sizeof(double));
    double avg_download_time, avg_upload_time;
    double std_dev_download_time, std_dev_upload_time;
    double confidence_interval_download_time, confidence_interval_upload_time;
    clock_t start_time, end_time;

    // Conduct download and upload speed tests
    for (i = 0; i < NUM_ITERATIONS; i++) {
        // Download test
        start_time = clock();
        // Simulate downloading a file of DATA_SIZE bytes
        end_time = clock();
        download_times[i] = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Upload test
        start_time = clock();
        // Simulate uploading a file of DATA_SIZE bytes
        end_time = clock();
        upload_times[i] = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    // Calculate statistics for download times
    avg_download_time = calculate_average(download_times, NUM_ITERATIONS);
    std_dev_download_time = calculate_standard_deviation(download_times, NUM_ITERATIONS);
    confidence_interval_download_time = calculate_confidence_interval(avg_download_time, std_dev_download_time, NUM_ITERATIONS);

    // Calculate statistics for upload times
    avg_upload_time = calculate_average(upload_times, NUM_ITERATIONS);
    std_dev_upload_time = calculate_standard_deviation(upload_times, NUM_ITERATIONS);
    confidence_interval_upload_time = calculate_confidence_interval(avg_upload_time, std_dev_upload_time, NUM_ITERATIONS);

    // Print results
    printf("Download Speed: %.2f Mbps (avg) ± %.2f Mbps (95%% confidence interval)\n",
           8 * DATA_SIZE / avg_download_time / 1000000,
           1.96 * std_dev_download_time * sqrt(NUM_ITERATIONS) / avg_download_time / 1000000);

    printf("Upload Speed: %.2f Mbps (avg) ± %.2f Mbps (95%% confidence interval)\n",
           8 * DATA_SIZE / avg_upload_time / 1000000,
           1.96 * std_dev_upload_time * sqrt(NUM_ITERATIONS) / avg_upload_time / 1000000);

    // Free allocated memory
    free(download_times);
    free(upload_times);

    return 0;
}

// Calculate the average of a set of values
double calculate_average(double *values, int num_values) {
    double sum = 0.0;
    for (int i = 0; i < num_values; i++) {
        sum += values[i];
    }
    return sum / num_values;
}

// Calculate the standard deviation of a set of values
double calculate_standard_deviation(double *values, int num_values) {
    double avg = calculate_average(values, num_values);
    double sum_of_squares = 0.0;
    for (int i = 0; i < num_values; i++) {
        sum_of_squares += pow(values[i] - avg, 2);
    }
    return sqrt(sum_of_squares / (num_values - 1));
}

// Calculate the 95% confidence interval for a mean value
double calculate_confidence_interval(double avg, double std_dev, int num_iterations) {
    return 1.96 * std_dev / sqrt(num_iterations);
}