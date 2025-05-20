//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to calculate mean
double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum/n;
}

// Function to calculate variance
double variance(int arr[], int n) {
    double mean_val = mean(arr, n);
    double var_sum = 0.0;
    for (int i = 0; i < n; i++) {
        var_sum += (arr[i] - mean_val)*(arr[i] - mean_val);
    }
    return var_sum/n;
}

// Function to calculate standard deviation
double std_deviation(int arr[], int n) {
    double var = variance(arr, n);
    return sqrt(var);
}

int main() {
    char filename[] = "log_file.txt"; // Replace with your log file path
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    int log_arr[MAX_SIZE]; // Array to store logs
    int n = 0; // Number of logs

    // Read logs from file
    while(!feof(fptr)) {
        int val;
        fscanf(fptr, "%d", &val);
        log_arr[n++] = val;
    }

    fclose(fptr); // Close file

    // Calculate statistics
    double mean_val = mean(log_arr, n);
    double var_val = variance(log_arr, n);
    double std_dev_val = std_deviation(log_arr, n);

    // Display statistics
    printf("Log Analysis Report:\n\n");
    printf("Total number of logs: %d\n", n);
    printf("Mean: %.2f\n", mean_val);
    printf("Variance: %.2f\n", var_val);
    printf("Standard Deviation: %.2f\n", std_dev_val);

    return 0;
}