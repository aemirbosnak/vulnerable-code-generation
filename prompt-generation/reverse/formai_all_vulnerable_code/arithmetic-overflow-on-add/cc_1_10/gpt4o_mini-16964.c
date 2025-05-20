//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_POINTS 1000
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    int label;
} DataPoint;

typedef struct {
    DataPoint data[MAX_DATA_POINTS];
    int size;
} Dataset;

// Function to load dataset from a CSV file
Dataset load_dataset(const char *filename) {
    FILE *file = fopen(filename, "r");
    Dataset dataset;
    dataset.size = 0;

    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%lf,%lf,%d\n", 
                  &dataset.data[dataset.size].features[0],
                  &dataset.data[dataset.size].features[1],
                  &dataset.data[dataset.size].label) == 3) {
        dataset.size++;
        if (dataset.size >= MAX_DATA_POINTS) {
            break;
        }
    }
    
    fclose(file);
    return dataset;
}

// Function to normalize the dataset
void normalize_dataset(Dataset *dataset) {
    double min[MAX_FEATURES] = {__DBL_MAX__, __DBL_MAX__};
    double max[MAX_FEATURES] = {-__DBL_MAX__, -__DBL_MAX__};

    // Finding min and max for each feature
    for (int i = 0; i < dataset->size; i++) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            if (dataset->data[i].features[j] < min[j]) {
                min[j] = dataset->data[i].features[j];
            }
            if (dataset->data[i].features[j] > max[j]) {
                max[j] = dataset->data[i].features[j];
            }
        }
    }

    // Normalizing features
    for (int i = 0; i < dataset->size; i++) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            if (max[j] - min[j] != 0) {
                dataset->data[i].features[j] = 
                    (dataset->data[i].features[j] - min[j]) / (max[j] - min[j]);
            } else {
                dataset->data[i].features[j] = 0; // Avoid division by zero
            }
        }
    }
}

// Function to print dataset
void print_dataset(const Dataset *dataset) {
    for (int i = 0; i < dataset->size; i++) {
        printf("DataPoint %d: ", i);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%f ", dataset->data[i].features[j]);
        }
        printf("Label: %d\n", dataset->data[i].label);
    }
}

// Function to classify using a simple nearest neighbor algorithm
int classify(const DataPoint *data_point, const Dataset *dataset) {
    double min_distance = __DBL_MAX__;
    int nearest_label = -1;

    for (int i = 0; i < dataset->size; i++) {
        double distance = 0.0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            distance += (data_point->features[j] - dataset->data[i].features[j]) * 
                        (data_point->features[j] - dataset->data[i].features[j]);
        }
        distance = sqrt(distance);

        if (distance < min_distance) {
            min_distance = distance;
            nearest_label = dataset->data[i].label;
        }
    }

    return nearest_label;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <datafile.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load dataset
    Dataset dataset = load_dataset(argv[1]);

    // Normalize dataset
    normalize_dataset(&dataset);

    // Print normalized dataset
    printf("Normalized Dataset:\n");
    print_dataset(&dataset);

    // Example classification
    DataPoint sample = {{0.5, 0.5}, -1}; // Example sample to classify (normalized)
    int label = classify(&sample, &dataset);
    printf("Classified label for sample: %d\n", label);

    return EXIT_SUCCESS;
}