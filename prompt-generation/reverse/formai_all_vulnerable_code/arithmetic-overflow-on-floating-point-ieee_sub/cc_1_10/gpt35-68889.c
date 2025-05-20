//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define the number of classes and features
#define NUM_CLASSES 3
#define NUM_FEATURES 4

// Define the number of training samples per class
#define NUM_SAMPLES 5

// Define the input training data
float training_data[NUM_CLASSES*NUM_SAMPLES][NUM_FEATURES] = {
    // Class 1
    {1.1, 1.2, 1.3, 1.4},
    {1.2, 1.3, 1.4, 1.5},
    {1.3, 1.4, 1.5, 1.6},
    {1.4, 1.5, 1.6, 1.7},
    {1.5, 1.6, 1.7, 1.8},

    // Class 2
    {2.1, 2.2, 2.3, 2.4},
    {2.2, 2.3, 2.4, 2.5},
    {2.3, 2.4, 2.5, 2.6},
    {2.4, 2.5, 2.6, 2.7},
    {2.5, 2.6, 2.7, 2.8},

    // Class 3
    {3.1, 3.2, 3.3, 3.4},
    {3.2, 3.3, 3.4, 3.5},
    {3.3, 3.4, 3.5, 3.6},
    {3.4, 3.5, 3.6, 3.7},
    {3.5, 3.6, 3.7, 3.8},
};

// Define the input test data
float test_data[NUM_FEATURES] = {2.0, 2.1, 2.2, 2.3};

// Define the classification function
int classify(float *input, float **training, int num_classes, int num_samples, int num_features)
{
    // Calculate the distance from the input to each training sample
    float distances[num_classes][num_samples];
    for (int i = 0; i < num_classes; i++) {
        for (int j = 0; j < num_samples; j++) {
            distances[i][j] = 0.0;
            for (int k = 0; k < num_features; k++) {
                distances[i][j] += (training[i*NUM_SAMPLES+j][k] - input[k]) * (training[i*NUM_SAMPLES+j][k] - input[k]);
            }
            distances[i][j] = sqrt(distances[i][j]);
        }
    }

    // Find the closest training sample to the input for each class
    float min_distances[num_classes];
    int min_indices[num_classes];
    for (int i = 0; i < num_classes; i++) {
        min_distances[i] = distances[i][0];
        min_indices[i] = 0;
        for (int j = 1; j < num_samples; j++) {
            if (distances[i][j] < min_distances[i]) {
                min_distances[i] = distances[i][j];
                min_indices[i] = j;
            }
        }
    }

    // Determine the class with the smallest distance
    int min_class = 0;
    for (int i = 1; i < num_classes; i++) {
        if (min_distances[i] < min_distances[min_class]) {
            min_class = i;
        }
    }

    return min_class;
}

// Main function
int main()
{
    // Print welcome message
    printf("Welcome to the Image Classification System.\n\n");

    // Print test data
    printf("Test Data:\n");
    for (int i = 0; i < NUM_FEATURES; i++) {
        printf("%.1f ", test_data[i]);
    }
    printf("\n\n");

    // Classify test data
    int class_label = classify(test_data, training_data, NUM_CLASSES, NUM_SAMPLES, NUM_FEATURES);

    // Print classification result
    printf("The closest class label for the test data is: %d\n", class_label+1);

    // Terminate program
    printf("\nThank you for using the Image Classification System.\n");
    return 0;
}