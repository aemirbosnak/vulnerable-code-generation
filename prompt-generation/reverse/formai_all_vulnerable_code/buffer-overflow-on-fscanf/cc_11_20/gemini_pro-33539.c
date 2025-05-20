//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define NUM_FEATURES 784

typedef struct {
    double features[NUM_FEATURES];
    int label;
} Image;

int main() {
    // Load the training data
    Image* training_data = malloc(sizeof(Image) * 60000);
    FILE* training_file = fopen("train.csv", "r");
    for (int i = 0; i < 60000; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(training_file, "%lf,", &training_data[i].features[j]);
        }
        fscanf(training_file, "%d\n", &training_data[i].label);
    }
    fclose(training_file);

    // Load the test data
    Image* test_data = malloc(sizeof(Image) * 10000);
    FILE* test_file = fopen("test.csv", "r");
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(test_file, "%lf,", &test_data[i].features[j]);
        }
        fscanf(test_file, "%d\n", &test_data[i].label);
    }
    fclose(test_file);

    // Train the classifier
    double weights[NUM_FEATURES];
    for (int i = 0; i < NUM_FEATURES; i++) {
        weights[i] = 0.0;
    }
    for (int i = 0; i < 60000; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            weights[j] += training_data[i].features[j] * training_data[i].label;
        }
    }

    // Test the classifier
    int correct = 0;
    for (int i = 0; i < 10000; i++) {
        double score = 0.0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            score += weights[j] * test_data[i].features[j];
        }
        int predicted_label = score > 0.0 ? 1 : -1;
        if (predicted_label == test_data[i].label) {
            correct++;
        }
    }

    // Print the accuracy
    printf("Accuracy: %f%%\n", (double)correct / 10000 * 100.0);

    // Free the memory
    free(training_data);
    free(test_data);

    return 0;
}