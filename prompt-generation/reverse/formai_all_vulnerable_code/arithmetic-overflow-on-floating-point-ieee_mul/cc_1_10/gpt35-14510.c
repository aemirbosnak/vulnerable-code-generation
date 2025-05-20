//FormAI DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of classes and features
#define NUM_CLASSES 3
#define NUM_FEATURES 4

// Define the size of the dataset
#define DATASET_SIZE 10

// Define the training data
float training_data[DATASET_SIZE][NUM_FEATURES + 1] = {
    {2.0, 5.2, 1.3, 0.4, 0},
    {3.0, 4.5, 1.2, 0.3, 0},
    {4.0, 3.1, 1.5, 0.2, 0},
    {5.0, 2.0, 4.1, 1.0, 1},
    {6.0, 1.7, 3.9, 1.2, 1},
    {7.0, 1.2, 4.3, 1.3, 1},
    {8.0, 0.9, 5.1, 2.1, 2},
    {9.0, 0.5, 4.8, 2.2, 2},
    {10.0, 0.1, 5.0, 2.3, 2},
    {11.0, -0.3, 4.7, 2.4, 2}
};

// Define the test data
float test_data[NUM_FEATURES] = {3.5, 3.2, 1.7, 0.5};

int main()
{
    // Initialize the variables
    float sum;
    float min_distance, distance;
    int i, j, class_prediction;

    // Create an array to store the distances between test data and each training data
    float distances[DATASET_SIZE];

    // Loop through the training data
    for(i = 0; i < DATASET_SIZE; i++)
    {
        // Calculate the Euclidean distance between test data and each training data
        sum = 0.0;
        for(j = 0; j < NUM_FEATURES; j++)
        {
            sum += pow((training_data[i][j] - test_data[j]), 2);
        }

        distance = sqrt(sum);
        distances[i] = distance;
    }

    // Find the minimum distance and class prediction
    min_distance = distances[0];
    class_prediction = training_data[0][NUM_FEATURES];
    for(i = 1; i < DATASET_SIZE; i++)
    {
        if(distances[i] < min_distance)
        {
            min_distance = distances[i];
            class_prediction = training_data[i][NUM_FEATURES];
        }
    }

    // Print out the results
    printf("Test data: {%f, %f, %f, %f}\n", test_data[0], test_data[1], test_data[2], test_data[3]);
    printf("Predicted class: %d\n", class_prediction);

    return 0;
}