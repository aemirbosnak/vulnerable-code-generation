//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void calculateMean(const double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    printf("Mean: %.2f\n", sum / n);
}

void calculateMedian(double data[], int n) {
    // Sort the data for median calculation
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    double median;
    if (n % 2 == 0) {
        median = (data[n/2 - 1] + data[n/2]) / 2.0;
    } else {
        median = data[n/2];
    }
    printf("Median: %.2f\n", median);
}

void calculateMode(const double data[], int n) {
    int count[MAX_SIZE] = {0};
    int modeCount = 0;
    double modeValue = data[0];

    for (int i = 0; i < n; i++) {
        count[(int)data[i]]++;
        if (count[(int)data[i]] > modeCount) {
            modeCount = count[(int)data[i]];
            modeValue = data[i];
        }
    }
    printf("Mode: %.2f\n", modeValue);
}

void detectAnomalies(const double data[], int n) {
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;

    double threshold = mean * 2; // Simple threshold for anomalies
    printf("Anomalies detected (values exceeding %.2f): ", threshold);
    for (int i = 0; i < n; i++) {
        if (data[i] > threshold) {
            printf("%.2f ", data[i]);
        }
    }
    printf("\n");
}

int main() {
    double data[MAX_SIZE];
    int n = 0;

    // Input: Read data from a text file named 'data.txt'
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%lf", &data[n]) != EOF && n < MAX_SIZE) {
        n++;
    }
    fclose(file);

    // Compute and display statistics
    printf("Data values read: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n\n");

    calculateMean(data, n);
    calculateMedian(data, n);
    calculateMode(data, n);
    detectAnomalies(data, n);
    
    return 0;
}