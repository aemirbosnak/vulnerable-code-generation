//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read data from file
void readData(FILE* file, double* xValues, double* yValues, int n) {
    int i;
    for (i = 0; i < n; i++) {
        fscanf(file, "%lf %lf\n", xValues + i, yValues + i);
    }
}

// Function to build linear regression model
void buildModel(double* xValues, double* yValues, int n, double* slope, double* intercept) {
    int i;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (i = 0; i < n; i++) {
        sumX += xValues[i];
        sumY += yValues[i];
        sumXY += xValues[i] * yValues[i];
        sumX2 += pow(xValues[i], 2);
    }

    *slope = (sumXY - (sumX * sumY) / n) / (sumX2 - pow(sumX, 2) / n);
    *intercept = sumY - *slope * sumX;
}

// Function to make predictions using model
void makePredictions(double* xValues, double* yValues, int n, double* slope, double* intercept, double* predictions) {
    int i;
    for (i = 0; i < n; i++) {
        predictions[i] = slope[0] * xValues[i] + intercept[0];
    }
}

// Main function
int main() {
    FILE* file = fopen("data.txt", "r");
    double xValues[100];
    double yValues[100];
    int n = 0;

    readData(file, xValues, yValues, &n);
    fclose(file);

    double slope[1];
    double intercept[1];
    buildModel(xValues, yValues, n, slope, intercept);

    double predictions[100];
    makePredictions(xValues, yValues, n, slope, intercept, predictions);

    printf("Original data:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f\n", xValues[i], yValues[i]);
    }

    printf("Predictions:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f\n", xValues[i], predictions[i]);
    }

    return 0;
}