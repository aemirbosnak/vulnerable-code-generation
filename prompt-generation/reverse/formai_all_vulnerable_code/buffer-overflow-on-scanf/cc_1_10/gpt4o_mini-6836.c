//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void displayInstructions() {
    printf("Welcome to the Visionary Math Program!\n");
    printf("This program will allow you to perform various mathematical transformations on a dataset.\n");
    printf("Follow the instructions carefully to create your data set and see the results!\n");
    printf("Let's get started...\n\n");
}

void inputData(double data[], int *n) {
    printf("Enter the number of data points (max %d): ", MAX_SIZE);
    scanf("%d", n);
    if (*n > MAX_SIZE || *n < 1) {
        printf("Invalid number of data points. Please restart the program.\n");
        exit(1);
    }

    printf("Enter the data points:\n");
    for (int i = 0; i < *n; i++) {
        printf("Data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }
}

void calculateStatistics(double data[], int n, double *mean, double *stdDev) {
    double sum = 0.0;
    double sumSquared = 0.0;

    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    
    *mean = sum / n;

    for (int i = 0; i < n; i++) {
        sumSquared += pow(data[i] - *mean, 2);
    }
    
    *stdDev = sqrt(sumSquared / n);
}

void transformData(double data[], int n, double mean, double stdDev, double transformedData[]) {
    for (int i = 0; i < n; i++) {
        transformedData[i] = (data[i] - mean) / stdDev;
    }
}

void displayResults(double data[], double transformedData[], int n, double mean, double stdDev) {
    printf("\nResults Summary:\n");
    printf("Original Data Points:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }
    printf("\n\nMean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", stdDev);
    
    printf("\nTransformed Data Points (Z-scores):\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", transformedData[i]);
    }
    printf("\n");
}

int main() {
    double data[MAX_SIZE];
    double transformedData[MAX_SIZE];
    double mean, stdDev;
    int n;

    displayInstructions();
    inputData(data, &n);
    calculateStatistics(data, n, &mean, &stdDev);
    transformData(data, n, mean, stdDev, transformedData);
    displayResults(data, transformedData, n, mean, stdDev);
    
    return 0;
}