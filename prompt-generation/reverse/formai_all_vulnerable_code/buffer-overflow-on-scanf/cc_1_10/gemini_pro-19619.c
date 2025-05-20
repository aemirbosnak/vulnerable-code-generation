//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure to store a data point
typedef struct {
    double features[10];  // 10 features
    int label;            // Label of the data point
} DataPoint;

// Function to read data points from a file
DataPoint *readDataPoints(char *filename, int *numDataPoints) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the number of data points
    fscanf(file, "%d", numDataPoints);

    // Allocate memory for the data points
    DataPoint *dataPoints = malloc(*numDataPoints * sizeof(DataPoint));
    if (dataPoints == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the data points
    for (int i = 0; i < *numDataPoints; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(file, "%lf", &dataPoints[i].features[j]);
        }
        fscanf(file, "%d", &dataPoints[i].label);
    }

    // Close the file
    fclose(file);

    // Return the data points
    return dataPoints;
}

// Function to calculate the Euclidean distance between two data points
double euclideanDistance(DataPoint *dataPoint1, DataPoint *dataPoint2) {
    double distance = 0.0;
    for (int i = 0; i < 10; i++) {
        distance += pow(dataPoint1->features[i] - dataPoint2->features[i], 2);
    }
    return sqrt(distance);
}

// Function to find the nearest neighbor of a data point
DataPoint *findNearestNeighbor(DataPoint *dataPoint, DataPoint *dataPoints, int numDataPoints) {
    // Initialize the nearest neighbor to the first data point
    DataPoint *nearestNeighbor = &dataPoints[0];

    // Calculate the distance between the data point and each of the other data points
    for (int i = 1; i < numDataPoints; i++) {
        double distance = euclideanDistance(dataPoint, &dataPoints[i]);
        if (distance < euclideanDistance(dataPoint, nearestNeighbor)) {
            nearestNeighbor = &dataPoints[i];
        }
    }

    // Return the nearest neighbor
    return nearestNeighbor;
}

// Function to predict the label of a data point using k-nearest neighbors
int predictLabel(DataPoint *dataPoint, DataPoint *dataPoints, int numDataPoints, int k) {
    // Find the k nearest neighbors of the data point
    DataPoint *nearestNeighbors[k];
    for (int i = 0; i < k; i++) {
        nearestNeighbors[i] = findNearestNeighbor(dataPoint, dataPoints, numDataPoints);
    }

    // Count the number of nearest neighbors with each label
    int labelCounts[3] = {0, 0, 0};  // 3 possible labels
    for (int i = 0; i < k; i++) {
        labelCounts[nearestNeighbors[i]->label]++;
    }

    // Predict the label with the most votes
    int predictedLabel = 0;
    for (int i = 1; i < 3; i++) {
        if (labelCounts[i] > labelCounts[predictedLabel]) {
            predictedLabel = i;
        }
    }

    // Return the predicted label
    return predictedLabel;
}

// Main function
int main() {
    // Read the data points from a file
    char *filename = "data.txt";
    int numDataPoints;
    DataPoint *dataPoints = readDataPoints(filename, &numDataPoints);
    if (dataPoints == NULL) {
        return 1;
    }

    // Get the query point from the user
    DataPoint queryPoint;
    printf("Enter the query point:\n");
    for (int i = 0; i < 10; i++) {
        printf("Feature %d: ", i + 1);
        scanf("%lf", &queryPoint.features[i]);
    }

    // Predict the label of the query point using 3-nearest neighbors
    int predictedLabel = predictLabel(&queryPoint, dataPoints, numDataPoints, 3);

    // Print the predicted label
    printf("Predicted label: %d\n", predictedLabel);

    // Free the memory allocated for the data points
    free(dataPoints);

    return 0;
}