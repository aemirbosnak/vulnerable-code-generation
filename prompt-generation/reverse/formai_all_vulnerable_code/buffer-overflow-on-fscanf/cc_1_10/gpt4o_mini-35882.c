//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 1000
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    int label;
} DataPoint;

typedef struct {
    DataPoint data[MAX_DATA_POINTS];
    int size;
    int feature_count;
} Dataset;

void load_data(const char *filename, Dataset *dataset) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    dataset->size = 0;
    while (fscanf(file, "%lf,%lf,%d", 
                  &dataset->data[dataset->size].features[0],
                  &dataset->data[dataset->size].features[1],
                  &dataset->data[dataset->size].label) != EOF) {
        dataset->size++;
        if (dataset->size >= MAX_DATA_POINTS) break;
    }
    fclose(file);
}

double euclidean_distance(const DataPoint *a, const DataPoint *b) {
    double sum = 0.0;
    for (int i = 0; i < MAX_FEATURES; i++) {
        sum += pow(a->features[i] - b->features[i], 2);
    }
    return sqrt(sum);
}

void classify(const Dataset *dataset, const DataPoint *input, int k, int *predicted_label) {
    double distances[MAX_DATA_POINTS] = {0};
    int indices[MAX_DATA_POINTS] = {0};

    for (int i = 0; i < dataset->size; i++) {
        distances[i] = euclidean_distance(&dataset->data[i], input);
        indices[i] = i;
    }

    for (int i = 0; i < dataset->size - 1; i++) {
        for (int j = 0; j < dataset->size - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                double temp_dist = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp_dist;

                int temp_idx = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp_idx;
            }
        }
    }

    int count[2] = {0, 0}; // Assuming binary classification (labels 0 and 1)
    for (int i = 0; i < k; i++) {
        count[dataset->data[indices[i]].label]++;
    }
    
    *predicted_label = (count[0] > count[1]) ? 0 : 1; // Majority voting
}

void print_summary(const Dataset *dataset) {
    printf("Total Data Points: %d\n", dataset->size);
    for (int i = 0; i < dataset->size; i++) {
        printf("Data Point %d: [", i);
        for (int j = 0; j < dataset->feature_count; j++) {
            printf("%lf", dataset->data[i].features[j]);
            if (j < dataset->feature_count - 1) printf(", ");
        }
        printf("], Label: %d\n", dataset->data[i].label);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Dataset dataset;
    load_data(argv[1], &dataset);
    dataset.feature_count = 2; // Assuming 2 features for the sake of example
    print_summary(&dataset);

    DataPoint new_point = {{5.1, 3.5}, -1}; // Sample input point to classify
    int k = 3; // Number of neighbors to consider
    int predicted_label = -1;

    classify(&dataset, &new_point, k, &predicted_label);
    printf("Predicted label for the new point: %d\n", predicted_label);

    return 0;
}