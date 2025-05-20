//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMPLES 100
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    int label;
} Sample;

typedef struct {
    Sample samples[MAX_SAMPLES];
    int count;
} Dataset;

void load_dataset(const char *filename, Dataset *dataset) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    dataset->count = 0;
    while (fscanf(file, "%lf,%lf,%d", 
                  &dataset->samples[dataset->count].features[0], 
                  &dataset->samples[dataset->count].features[1], 
                  &dataset->samples[dataset->count].label) == 3) {
        dataset->count++;
        if (dataset->count >= MAX_SAMPLES) {
            break;
        }
    }
    fclose(file);
}

void print_dataset(const Dataset *dataset) {
    for (int i = 0; i < dataset->count; i++) {
        printf("Sample %d: Feature1 = %.2f, Feature2 = %.2f, Label = %d\n", 
                i + 1, dataset->samples[i].features[0], 
                dataset->samples[i].features[1], 
                dataset->samples[i].label);
    }
}

double calculate_average(const Dataset *dataset, int feature_index) {
    double sum = 0.0;
    for (int i = 0; i < dataset->count; i++) {
        sum += dataset->samples[i].features[feature_index];
    }
    return sum / dataset->count;
}

void normalize_features(Dataset *dataset) {
    for (int i = 0; i < MAX_FEATURES; i++) {
        double average = calculate_average(dataset, i);
        for (int j = 0; j < dataset->count; j++) {
            dataset->samples[j].features[i] -= average;
        }
    }
}

int classify_sample(const Sample *sample, const Dataset *training_set) {
    double min_distance = __DBL_MAX__;
    int predicted_label = -1;

    for (int i = 0; i < training_set->count; i++) {
        double distance = 0.0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            distance += (sample->features[j] - training_set->samples[i].features[j]) * 
                        (sample->features[j] - training_set->samples[i].features[j]);
        }
        distance = sqrt(distance);
        
        if (distance < min_distance) {
            min_distance = distance;
            predicted_label = training_set->samples[i].label;
        }
    }
    return predicted_label;
}

void test_classifier(const Dataset *test_set, const Dataset *training_set) {
    int correct = 0;

    for (int i = 0; i < test_set->count; i++) {
        int predicted_label = classify_sample(&test_set->samples[i], training_set);
        printf("Test Sample %d: Predicted = %d, Actual = %d\n", 
               i + 1, predicted_label, test_set->samples[i].label);
        if (predicted_label == test_set->samples[i].label) {
            correct++;
        }
    }
    printf("Accuracy: %.2f%%\n", (correct / (double)test_set->count) * 100);
}

int main() {
    Dataset training_set, test_set;

    load_dataset("train_data.txt", &training_set);
    printf("Training Dataset:\n");
    print_dataset(&training_set);
    
    normalize_features(&training_set);

    load_dataset("test_data.txt", &test_set);
    printf("\nTesting Dataset:\n");
    print_dataset(&test_set);

    test_classifier(&test_set, &training_set);

    return 0;
}