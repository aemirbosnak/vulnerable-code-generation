//FormAI DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define IMAGE_SIZE 784
#define LAYER1_SIZE 256

/** 
 * This program is a simple image classification system that classifies images
 * of handwritten digits into 10 classes (0-9). It uses a single hidden layer
 * neural network with 256 neurons and the softmax function for multi-class
 * classification.
 */

// Function prototypes
void initialize_weights(double* w1, double* b1, double* w2, double* b2);
void forward_pass(double* x, double* w1, double* b1, double* w2, double* b2, double* h, double* y);
int argmax(double* arr, int length);

int main() {
    // Load input image from file (just a 28x28 matrix with pixel values 0-255)
    FILE* input_file = fopen("input_image.txt", "r");
    if (input_file == NULL) {
        printf("Error: failed to open input image file.\n");
        return 1;
    }
    double* x = (double*) malloc(IMAGE_SIZE * sizeof(double));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        fscanf(input_file, "%lf", &x[i]);
    }
    fclose(input_file);

    // Initialize weights and biases
    double* w1 = (double*) malloc(IMAGE_SIZE * LAYER1_SIZE * sizeof(double));
    double* b1 = (double*) malloc(LAYER1_SIZE * sizeof(double));
    double* w2 = (double*) malloc(LAYER1_SIZE * NUM_CLASSES * sizeof(double));
    double* b2 = (double*) malloc(NUM_CLASSES * sizeof(double));
    initialize_weights(w1, b1, w2, b2);

    // Forward pass
    double* h = (double*) malloc(LAYER1_SIZE * sizeof(double));
    double* y = (double*) malloc(NUM_CLASSES * sizeof(double));
    forward_pass(x, w1, b1, w2, b2, h, y);

    // Print output
    printf("Input image:\n");
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%3.0f ", x[i * IMAGE_WIDTH + j]);
        }
        printf("\n");
    }
    printf("\nOutput probabilities (%d classes):\n", NUM_CLASSES);
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%d: %.3f\n", i, y[i]);
    }
    int predicted_class = argmax(y, NUM_CLASSES);
    printf("\nPredicted class: %d\n", predicted_class);

    // Clean up
    free(x);
    free(w1);
    free(b1);
    free(w2);
    free(b2);
    free(h);
    free(y);
    return 0;
}

/**
 * Initializes the weights and biases of the neural network.
 */
void initialize_weights(double* w1, double* b1, double* w2, double* b2) {
    // Initialize weights and biases to random values
    for (int i = 0; i < IMAGE_SIZE * LAYER1_SIZE; i++) {
        w1[i] = rand() / (double) RAND_MAX - 0.5;
    }
    for (int i = 0; i < LAYER1_SIZE; i++) {
        b1[i] = rand() / (double) RAND_MAX - 0.5;
    }
    for (int i = 0; i < LAYER1_SIZE * NUM_CLASSES; i++) {
        w2[i] = rand() / (double) RAND_MAX - 0.5;
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        b2[i] = rand() / (double) RAND_MAX - 0.5;
    }
}

/**
 * Performs a forward pass through the neural network to generate output
 * probabilities for the input image.
 */
void forward_pass(double* x, double* w1, double* b1, double* w2, double* b2, double* h, double* y) {
    // Compute hidden layer activations
    for (int i = 0; i < LAYER1_SIZE; i++) {
        h[i] = b1[i];
        for (int j = 0; j < IMAGE_SIZE; j++) {
            h[i] += w1[j * LAYER1_SIZE + i] * x[j];
        }
        h[i] = fmax(0, h[i]); // ReLU activation function
    }

    // Compute output layer activations
    for (int i = 0; i < NUM_CLASSES; i++) {
        y[i] = b2[i];
        for (int j = 0; j < LAYER1_SIZE; j++) {
            y[i] += w2[j * NUM_CLASSES + i] * h[j];
        }
    }

    // Apply softmax function to output layer activations to get probabilities
    double sum = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        y[i] = exp(y[i]);
        sum += y[i];
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        y[i] /= sum;
    }
}

/**
 * Computes the index of the largest element in the given array.
 */
int argmax(double* arr, int length) {
    int max_index = 0;
    double max_value = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max_value) {
            max_index = i;
            max_value = arr[i];
        }
    }
    return max_index;
}