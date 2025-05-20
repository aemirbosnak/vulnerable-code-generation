//FormAI DATASET v1.0 Category: Image Classification system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 5 // the number of classes
#define NUM_FEATURES 10 // the number of features

// define the struct for the feature vector
typedef struct {
    double features[NUM_FEATURES];
    int label;
} FeatureVector;

// define a function to load the dataset from a file
FeatureVector* load_dataset(char* filename, int num_samples) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    FeatureVector* dataset = malloc(sizeof(FeatureVector) * num_samples);

    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(f, "%lf", &dataset[i].features[j]);
        }
        fscanf(f, "%d", &dataset[i].label);
    }

    fclose(f);
    return dataset;
}

// define a function to classify a feature vector using the given weights
int classify(FeatureVector* vec, double* weights) {
    double score[NUM_CLASSES] = {0};
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            score[i] += vec->features[j] * weights[i * NUM_FEATURES + j];
        }
    }
    int max_index = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (score[i] > score[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    // load the training data
    FeatureVector* training_data = load_dataset("training_data.txt", 500);

    // initialize the weights
    double* weights = malloc(sizeof(double) * NUM_CLASSES * NUM_FEATURES);
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            weights[i * NUM_FEATURES + j] = 0.0;
        }
    }

    // train the model
    int num_iterations = 1000;
    double learning_rate = 0.01;
    for (int iter = 0; iter < num_iterations; iter++) {
        for (int i = 0; i < 500; i++) {
            FeatureVector* vec = &training_data[i];
            int prediction = classify(vec, weights);
            int label = vec->label;
            if (prediction != label) {
                for (int j = 0; j < NUM_FEATURES; j++) {
                    weights[label * NUM_FEATURES + j] += learning_rate * vec->features[j];
                    weights[prediction * NUM_FEATURES + j] -= learning_rate * vec->features[j];
                }
            }
        }
    }

    // load the test data
    FeatureVector* test_data = load_dataset("test_data.txt", 100);

    // evaluate the model
    int num_correct = 0;
    for (int i = 0; i < 100; i++) {
        FeatureVector* vec = &test_data[i];
        int prediction = classify(vec, weights);
        if (prediction == vec->label) {
            num_correct++;
        }
    }
    printf("Accuracy: %lf\n", (double)num_correct / 100.0);

    // free memory
    free(training_data);
    free(test_data);
    free(weights);

    return 0;
}