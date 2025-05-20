//Falcon-180B DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 1000
#define NUM_COLS 10

// Function to generate random data
void generateData(int rows, int cols, double data[][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = rand() % 100;
        }
    }
}

// Function to print data
void printData(int rows, int cols, double data[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate mean
double calculateMean(int rows, int cols, double data[][cols]) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += data[i][j];
        }
    }
    return sum / (rows * cols);
}

// Function to calculate standard deviation
double calculateStdDev(int rows, int cols, double data[][cols], double mean) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += pow((data[i][j] - mean), 2);
        }
    }
    return sqrt(sum / (rows * cols));
}

int main() {
    int rows = NUM_ROWS;
    int cols = NUM_COLS;
    double data[rows][cols];

    // Generate random data
    generateData(rows, cols, data);

    // Print original data
    printf("Original Data:\n");
    printData(rows, cols, data);

    // Calculate mean and standard deviation
    double mean = calculateMean(rows, cols, data);
    double stdDev = calculateStdDev(rows, cols, data, mean);

    // Print mean and standard deviation
    printf("\nMean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", stdDev);

    return 0;
}