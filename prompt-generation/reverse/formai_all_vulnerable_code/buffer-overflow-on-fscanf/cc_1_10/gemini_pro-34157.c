//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a data point
typedef struct {
    float x1;
    float x2;
    float x3;
    float y;
} DataPoint;

// Function to read data from a file
DataPoint* readData(char* filename, int* numDataPoints) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of data points
    fscanf(file, "%d", numDataPoints);

    // Allocate memory for the data points
    DataPoint* dataPoints = malloc(*numDataPoints * sizeof(DataPoint));

    // Read the data points
    for (int i = 0; i < *numDataPoints; i++) {
        fscanf(file, "%f %f %f %f", &dataPoints[i].x1, &dataPoints[i].x2, &dataPoints[i].x3, &dataPoints[i].y);
    }

    // Close the file
    fclose(file);

    // Return the data points
    return dataPoints;
}

// Function to train a linear regression model
void trainModel(DataPoint* dataPoints, int numDataPoints, float* weights) {
    // Initialize the weights
    weights[0] = 0.0;
    weights[1] = 0.0;
    weights[2] = 0.0;
    weights[3] = 0.0;

    // Iterate over the data points
    for (int i = 0; i < numDataPoints; i++) {
        // Calculate the predicted value
        float predictedValue = weights[0] + weights[1] * dataPoints[i].x1 + weights[2] * dataPoints[i].x2 + weights[3] * dataPoints[i].x3;

        // Calculate the error
        float error = dataPoints[i].y - predictedValue;

        // Update the weights
        weights[0] += error;
        weights[1] += error * dataPoints[i].x1;
        weights[2] += error * dataPoints[i].x2;
        weights[3] += error * dataPoints[i].x3;
    }
}

// Function to make predictions using a linear regression model
float predict(DataPoint* dataPoint, float* weights) {
    // Calculate the predicted value
    float predictedValue = weights[0] + weights[1] * dataPoint->x1 + weights[2] * dataPoint->x2 + weights[3] * dataPoint->x3;

    // Return the predicted value
    return predictedValue;
}

// Function to evaluate a linear regression model
float evaluateModel(DataPoint* dataPoints, int numDataPoints, float* weights) {
    // Initialize the total error
    float totalError = 0.0;

    // Iterate over the data points
    for (int i = 0; i < numDataPoints; i++) {
        // Calculate the predicted value
        float predictedValue = predict(&dataPoints[i], weights);

        // Calculate the error
        float error = dataPoints[i].y - predictedValue;

        // Update the total error
        totalError += error * error;
    }

    // Calculate the mean squared error
    float meanSquaredError = totalError / numDataPoints;

    // Return the mean squared error
    return meanSquaredError;
}

// Main function
int main() {
    // Read the data from a file
    char* filename = "data.txt";
    int numDataPoints;
    DataPoint* dataPoints = readData(filename, &numDataPoints);

    // Train the model
    float weights[4];
    trainModel(dataPoints, numDataPoints, weights);

    // Evaluate the model
    float meanSquaredError = evaluateModel(dataPoints, numDataPoints, weights);
    printf("Mean squared error: %f\n", meanSquaredError);

    // Free the memory
    free(dataPoints);

    return 0;
}