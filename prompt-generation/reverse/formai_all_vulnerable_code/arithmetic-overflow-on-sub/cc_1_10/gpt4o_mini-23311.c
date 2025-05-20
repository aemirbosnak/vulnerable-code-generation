//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void calculateStatistics(double* data, int size);
double calculateMean(double* data, int size);
double calculateMedian(double* data, int size);
double calculateMode(double* data, int size);
double calculateStandardDeviation(double* data, int size, double mean);
void sortArray(double* data, int size);

int main() {
    int dataSize;

    // User input for the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &dataSize);

    // Memory allocation for data points
    double* data = (double*)malloc(dataSize * sizeof(double));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Input data points
    printf("Enter the data points:\n");
    for (int i = 0; i < dataSize; ++i) {
        printf("Data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }

    // Calculate and display statistics
    calculateStatistics(data, dataSize);

    // Free allocated memory
    free(data);
    return 0;
}

void calculateStatistics(double* data, int size) {
    double mean = calculateMean(data, size);
    double median = calculateMedian(data, size);
    double mode = calculateMode(data, size);
    double stdDev = calculateStandardDeviation(data, size, mean);

    printf("\nStatistics:\n");
    printf("Mean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Mode: %.2lf\n", mode);
    printf("Standard Deviation: %.2lf\n", stdDev);
}

double calculateMean(double* data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

double calculateMedian(double* data, int size) {
    sortArray(data, size);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

double calculateMode(double* data, int size) {
    int maxCount = 0, count = 0;
    double mode = data[0];

    for (int i = 0; i < size; ++i) {
        count = 0;
        for (int j = 0; j < size; ++j) {
            if (data[j] == data[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }
    return mode;
}

double calculateStandardDeviation(double* data, int size, double mean) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / size);
}

void sortArray(double* data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}