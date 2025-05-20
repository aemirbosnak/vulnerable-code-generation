//FormAI DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_SIZE 28

// Function to calculate the Euclidean distance between two vectors
double euclidean_distance(double a[], double b[]) {
    double sum = 0.0;
    for(int i = 0; i < IMAGE_SIZE*IMAGE_SIZE; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

// Function to find the index of the nearest neighbor
int find_nn_index(double features[], double images[][IMAGE_SIZE*IMAGE_SIZE], int num_images) {
    int min_index = 0;
    double min_distance = euclidean_distance(features, images[0]);

    for(int i = 1; i < num_images; i++) {
        double dist = euclidean_distance(features, images[i]);
        if(dist < min_distance) {
            min_index = i;
            min_distance = dist;
        }
    }

    return min_index;
}

// Function to classify the input image
int classify_image(double input[], double images[][IMAGE_SIZE*IMAGE_SIZE], int labels[], int num_images, int k) {
    double distances[num_images];
    int nn_indices[k];

    // Find the k nearest neighbors
    for(int i = 0; i < num_images; i++) {
        double dist = euclidean_distance(input, images[i]);

        if(i < k) {
            distances[i] = dist;
            nn_indices[i] = i;
        } else {
            int max_index = 0;
            double max_dist = distances[0];

            for(int j = 1; j < k; j++) {
                if(distances[j] > max_dist) {
                    max_index = j;
                    max_dist = distances[j];
                }
            }

            if(dist < max_dist) {
                distances[max_index] = dist;
                nn_indices[max_index] = i;
            }
        }
    }

    // Count the number of occurrences of each label among the k nearest neighbors
    int label_counts[10] = {0};

    for(int i = 0; i < k; i++) {
        int index = nn_indices[i];
        int label = labels[index];
        label_counts[label]++;
    }

    // Find the label with the maximum count
    int max_count = 0;
    int max_label = 0;

    for(int i = 0; i < 10; i++) {
        if(label_counts[i] > max_count) {
            max_count = label_counts[i];
            max_label = i;
        }
    }

    return max_label;
}

int main() {
    // Load the training set
    FILE *fp = fopen("mnist_train.csv", "r");
    if(fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    int num_images = 60000;
    double images[num_images][IMAGE_SIZE*IMAGE_SIZE];
    int labels[num_images];

    for(int i = 0; i < num_images; i++) {
        int label;
        fscanf(fp, "%d,", &label);
        labels[i] = label;

        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            fscanf(fp, "%lf,", &images[i][j]);
        }
    }

    fclose(fp);

    // Load the test set
    fp = fopen("mnist_test.csv", "r");
    if(fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    int num_test_images = 10000;
    double test_images[num_test_images][IMAGE_SIZE*IMAGE_SIZE];
    int test_labels[num_test_images];

    for(int i = 0; i < num_test_images; i++) {
        int label;
        fscanf(fp, "%d,", &label);
        test_labels[i] = label;

        for(int j = 0; j < IMAGE_SIZE*IMAGE_SIZE; j++) {
            fscanf(fp, "%lf,", &test_images[i][j]);
        }
    }

    fclose(fp);

    // Test the classifier
    int k = 5;
    int correct = 0;

    for(int i = 0; i < num_test_images; i++) {
        int predicted_label = classify_image(test_images[i], images, labels, num_images, k);

        if(predicted_label == test_labels[i]) {
            correct++;
        }
    }

    double accuracy = (double)correct / num_test_images * 100.0;
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}