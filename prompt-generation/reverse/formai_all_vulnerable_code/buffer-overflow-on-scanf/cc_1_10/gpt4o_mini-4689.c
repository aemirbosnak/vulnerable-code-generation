//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50

// Function to calculate the mean of an array
double calculateMean(double numbers[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

// Function to calculate the variance of an array
double calculateVariance(double numbers[], int count, double mean) {
    double variance = 0.0;
    for (int i = 0; i < count; i++) {
        variance += pow(numbers[i] - mean, 2);
    }
    return variance / count;
}

// Function to calculate the standard deviation of an array
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

// Function to add two matrices
void addMatrices(int rows, int cols, double matrixA[][MAX_SIZE], double matrixB[][MAX_SIZE], double result[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, double matrix[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double numbers[MAX_SIZE];
    int count;

    // Input number of elements
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &count);
    if (count > MAX_SIZE || count <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    // Input elements
    printf("Enter the elements:\n");
    for (int i = 0; i < count; i++) {
        scanf("%lf", &numbers[i]);
    }

    // Calculate mean, variance, and standard deviation
    double mean = calculateMean(numbers, count);
    double variance = calculateVariance(numbers, count, mean);
    double stddev = calculateStandardDeviation(variance);

    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);

    // Matrix addition
    int rows, cols;
    printf("Enter number of rows and columns for matrices: ");
    scanf("%d %d", &rows, &cols);
    if (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    double matrixA[MAX_SIZE][MAX_SIZE];
    double matrixB[MAX_SIZE][MAX_SIZE];
    double resultMatrix[MAX_SIZE][MAX_SIZE];

    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrixB[i][j]);
        }
    }

    // Add matrices
    addMatrices(rows, cols, matrixA, matrixB, resultMatrix);

    printf("Resultant Matrix after Addition:\n");
    printMatrix(rows, cols, resultMatrix);

    return 0;
}