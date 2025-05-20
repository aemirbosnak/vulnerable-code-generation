//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_FEATURES 10

typedef struct {
    double features[NUM_FEATURES];
    int label;
} data_point;

// Load data from a file
data_point* load_data(char *filename, int *num_data_points) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Get the number of data points
    fscanf(fp, "%d", num_data_points);

    // Allocate memory for the data points
    data_point *data = malloc(*num_data_points * sizeof(data_point));
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the data points
    for (int i = 0; i < *num_data_points; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(fp, "%lf", &data[i].features[j]);
        }
        fscanf(fp, "%d", &data[i].label);
    }

    // Close the file
    fclose(fp);

    return data;
}

// Free the memory allocated for the data points
void free_data(data_point *data, int num_data_points) {
    free(data);
}

// Calculate the mean of a feature
double calculate_mean(double *feature, int num_data_points) {
    double sum = 0.0;
    for (int i = 0; i < num_data_points; i++) {
        sum += feature[i];
    }
    return sum / num_data_points;
}

// Calculate the standard deviation of a feature
double calculate_standard_deviation(double *feature, int num_data_points) {
    double mean = calculate_mean(feature, num_data_points);
    double sum_of_squared_differences = 0.0;
    for (int i = 0; i < num_data_points; i++) {
        sum_of_squared_differences += (feature[i] - mean) * (feature[i] - mean);
    }
    return sqrt(sum_of_squared_differences / num_data_points);
}

// Calculate the z-score of a data point
double calculate_z_score(data_point *data, double *feature_means, double *feature_standard_deviations, int num_features) {
    double z_score = 0.0;
    for (int i = 0; i < num_features; i++) {
        z_score += ((data->features[i] - feature_means[i]) / feature_standard_deviations[i]) * ((data->features[i] - feature_means[i]) / feature_standard_deviations[i]);
    }
    return sqrt(z_score);
}

// Train the intrusion detection system
void train_ids(data_point *data, int num_data_points) {
    // Calculate the mean and standard deviation of each feature
    double feature_means[NUM_FEATURES];
    double feature_standard_deviations[NUM_FEATURES];
    for (int i = 0; i < NUM_FEATURES; i++) {
        double *feature = malloc(num_data_points * sizeof(double));
        for (int j = 0; j < num_data_points; j++) {
            feature[j] = data[j].features[i];
        }
        feature_means[i] = calculate_mean(feature, num_data_points);
        feature_standard_deviations[i] = calculate_standard_deviation(feature, num_data_points);
        free(feature);
    }

    // Save the mean and standard deviation to a file
    FILE *fp = fopen("ids_model.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    for (int i = 0; i < NUM_FEATURES; i++) {
        fprintf(fp, "%lf %lf\n", feature_means[i], feature_standard_deviations[i]);
    }
    fclose(fp);
}

// Load the intrusion detection system model
void load_ids_model(double *feature_means, double *feature_standard_deviations) {
    // Open the file
    FILE *fp = fopen("ids_model.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    // Read the mean and standard deviation of each feature
    for (int i = 0; i < NUM_FEATURES; i++) {
        fscanf(fp, "%lf %lf", &feature_means[i], &feature_standard_deviations[i]);
    }

    // Close the file
    fclose(fp);
}

// Test the intrusion detection system
void test_ids(data_point *data, int num_data_points) {
    // Load the intrusion detection system model
    double feature_means[NUM_FEATURES];
    double feature_standard_deviations[NUM_FEATURES];
    load_ids_model(feature_means, feature_standard_deviations);

    // Calculate the z-score of each data point
    double z_scores[num_data_points];
    for (int i = 0; i < num_data_points; i++) {
        z_scores[i] = calculate_z_score(&data[i], feature_means, feature_standard_deviations, NUM_FEATURES);
    }

    // Print the z-scores
    for (int i = 0; i < num_data_points; i++) {
        printf("%lf\n", z_scores[i]);
    }
}

int main() {
    // Load the data
    int num_data_points;
    data_point *data = load_data("data.txt", &num_data_points);
    if (data == NULL) {
        return 1;
    }

    // Train the intrusion detection system
    train_ids(data, num_data_points);

    // Test the intrusion detection system
    test_ids(data, num_data_points);

    // Free the memory allocated for the data
    free_data(data, num_data_points);

    return 0;
}