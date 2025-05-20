//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define IMAGE_SIZE 28
#define NUM_CLASSES 10
#define TRAINING_SAMPLES 1000
#define TESTING_SAMPLES 100
#define K 3 // Number of neighbors to consider

typedef struct {
    int label;
    unsigned char image[IMAGE_SIZE][IMAGE_SIZE];
} Sample;

// Function to calculate the Euclidean distance between two images
double euclidean_distance(unsigned char img1[IMAGE_SIZE][IMAGE_SIZE], unsigned char img2[IMAGE_SIZE][IMAGE_SIZE]) {
    double sum = 0.0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            sum += pow(img1[i][j] - img2[i][j], 2);
        }
    }
    return sqrt(sum);
}

// Function to classify an image using KNN
int classify(Sample training_samples[], Sample test_sample) {
    double distances[TRAINING_SAMPLES];
    int nearest_labels[K] = {0};

    // Calculate distances from the test sample to all training samples
    for (int i = 0; i < TRAINING_SAMPLES; i++) {
        distances[i] = euclidean_distance(training_samples[i].image, test_sample.image);
    }

    // Find the K nearest neighbors
    for (int i = 0; i < K; i++) {
        double min_distance = INFINITY;
        int min_index = -1;
        for (int j = 0; j < TRAINING_SAMPLES; j++) {
            if (distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }
        nearest_labels[i] = training_samples[min_index].label;
        distances[min_index] = INFINITY; // Mark this sample as used
    }

    // Voting to determine the final label
    int label_count[NUM_CLASSES] = {0};
    for (int i = 0; i < K; i++) {
        label_count[nearest_labels[i]]++;
    }

    // Determine the predicted label
    int max_count = -1;
    int predicted_label = -1;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (label_count[i] > max_count) {
            max_count = label_count[i];
            predicted_label = i;
        }
    }

    return predicted_label;
}

// Function to load training data from a file
void load_training_data(const char* filename, Sample training_samples[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open training data file.\n");
        exit(1);
    }
    for (int i = 0; i < TRAINING_SAMPLES; i++) {
        fscanf(file, "%d", &training_samples[i].label);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                fscanf(file, "%hhu", &training_samples[i].image[j][k]);
            }
        }
    }
    fclose(file);
}

// Function to load testing data from a file
void load_testing_data(const char* filename, Sample testing_samples[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open testing data file.\n");
        exit(1);
    }
    for (int i = 0; i < TESTING_SAMPLES; i++) {
        fscanf(file, "%d", &testing_samples[i].label);
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                fscanf(file, "%hhu", &testing_samples[i].image[j][k]);
            }
        }
    }
    fclose(file);
}

// Main function to execute the classification
int main() {
    Sample training_samples[TRAINING_SAMPLES];
    Sample testing_samples[TESTING_SAMPLES];
    
    load_training_data("training_data.txt", training_samples);
    load_testing_data("testing_data.txt", testing_samples);
    
    int correct_predictions = 0;

    for (int i = 0; i < TESTING_SAMPLES; i++) {
        int predicted_label = classify(training_samples, testing_samples[i]);
        printf("True label: %d, Predicted label: %d\n", testing_samples[i].label, predicted_label);
        if (predicted_label == testing_samples[i].label) {
            correct_predictions++;
        }
    }

    double accuracy = (double)correct_predictions / TESTING_SAMPLES * 100.0;
    printf("Classification accuracy: %.2f%%\n", accuracy);

    return 0;
}