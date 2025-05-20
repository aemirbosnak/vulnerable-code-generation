//FormAI DATASET v1.0 Category: Image Classification system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define NUM_CLASSES 3  // Number of image classes
#define NUM_SAMPLES 150  // Number of image samples
#define NUM_FEATURES 4  // Number of image features
#define LEARN_RATE 0.05  // Learning rate for training

// Function to read in image data
int read_data(float data[][NUM_FEATURES], int labels[]) {
    FILE *fp;
    char filename[] = "iris_data.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    for (int i = 0; i < NUM_SAMPLES; i++) {
        fscanf(fp, "%f,%f,%f,%f,%d", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &labels[i]);
    }
    fclose(fp);
    return 0;
}

// Function to initialize weights randomly
void init_weights(float weights[][NUM_FEATURES], int num_weights) {
    for (int i = 0; i < num_weights; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            weights[i][j] = ((float)rand() / (float)RAND_MAX) * 2.0 - 1.0;
        }
    }
}

// Function to predict image class
int predict(float data[], float weights[][NUM_FEATURES], int num_weights) {
    float max_val = -INFINITY;
    int max_idx = -1;
    for (int i = 0; i < num_weights; i++) {
        float sum = 0.0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            sum += data[j] * weights[i][j];
        }
        float val = exp(sum) / (1 + exp(sum));
        if (val > max_val) {
            max_val = val;
            max_idx = i;
        }
    }
    return max_idx;
}

// Function to train the model
void train(float data[][NUM_FEATURES], int labels[], float weights[][NUM_FEATURES], int num_weights) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        float data_point[NUM_FEATURES];
        for (int j = 0; j < NUM_FEATURES; j++) {
            data_point[j] = data[i][j];
        }
        int label = labels[i];
        for (int j = 0; j < num_weights; j++) {
            float predict_val = predict(data_point, weights, num_weights);
            float true_val = (j == label) ? 1 : 0;
            for (int k = 0; k < NUM_FEATURES; k++) {
                weights[j][k] += LEARN_RATE * (true_val - predict_val) * data_point[k];
            }
        }
    }
}

int main() {
    float data[NUM_SAMPLES][NUM_FEATURES];
    int labels[NUM_SAMPLES];
    read_data(data, labels);  // Read in image data
    float weights[NUM_CLASSES][NUM_FEATURES];
    init_weights(weights, NUM_CLASSES);  // Initialize weights randomly
    train(data, labels, weights, NUM_CLASSES);  // Train model
    float test_data[] = {5.1, 3.5, 1.4, 0.2};  // Test data
    printf("Predicted class: %d\n", predict(test_data, weights, NUM_CLASSES));
    return 0;
}