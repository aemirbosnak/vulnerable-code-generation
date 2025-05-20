//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data structure to hold statistical data
typedef struct {
    double *data;
    int size;
    int capacity;
} Statistics;

// Function to initialize the Statistics structure
void initStatistics(Statistics *stats, int capacity) {
    stats->data = (double*)malloc(capacity * sizeof(double));
    stats->size = 0;
    stats->capacity = capacity;
}

// Function to add a new value to the Statistics structure
void addValue(Statistics *stats, double value) {
    if (stats->size == stats->capacity) {
        stats->capacity *= 2;
        stats->data = (double*)realloc(stats->data, stats->capacity * sizeof(double));
    }
    stats->data[stats->size] = value;
    stats->size++;
}

// Function to calculate the mean of the data
double calculateMean(Statistics *stats) {
    double sum = 0.0;
    for (int i = 0; i < stats->size; i++) {
        sum += stats->data[i];
    }
    return sum / stats->size;
}

// Function to calculate the variance of the data
double calculateVariance(Statistics *stats, double mean) {
    double varianceSum = 0.0;
    for (int i = 0; i < stats->size; i++) {
        varianceSum += (stats->data[i] - mean) * (stats->data[i] - mean);
    }
    return varianceSum / stats->size;
}

// Function to find the maximum value in the data
double findMaximum(Statistics *stats) {
    double max = stats->data[0];
    for (int i = 1; i < stats->size; i++) {
        if (stats->data[i] > max) {
            max = stats->data[i];
        }
    }
    return max;
}

// Function to find the minimum value in the data
double findMinimum(Statistics *stats) {
    double min = stats->data[0];
    for (int i = 1; i < stats->size; i++) {
        if (stats->data[i] < min) {
            min = stats->data[i];
        }
    }
    return min;
}

// Function to free the memory allocated for the statistics
void freeStatistics(Statistics *stats) {
    free(stats->data);
}

// Main function
int main() {
    Statistics stats;
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    initStatistics(&stats, n);
    
    printf("Enter %d data points:\n", n);
    for (int i = 0; i < n; i++) {
        double value;
        scanf("%lf", &value);
        addValue(&stats, value);
    }

    double mean = calculateMean(&stats);
    double variance = calculateVariance(&stats, mean);
    double max = findMaximum(&stats);
    double min = findMinimum(&stats);
    
    printf("Statistics Results:\n");
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Maximum: %.2f\n", max);
    printf("Minimum: %.2f\n", min);

    freeStatistics(&stats);
    return 0;
}