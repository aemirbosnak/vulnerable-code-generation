//FormAI DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the neural network structure
#define INPUT_SIZE 784
#define HIDDEN_SIZE 256
#define OUTPUT_SIZE 10

typedef struct nn {
    double W1[INPUT_SIZE][HIDDEN_SIZE];
    double W2[HIDDEN_SIZE][OUTPUT_SIZE];
    double b1[HIDDEN_SIZE];
    double b2[OUTPUT_SIZE];
} NeuralNet;

// Helper functions for loading MNIST dataset
void read_magic_number(FILE* fp, int* magic_number) {
    unsigned char buffer[4];
    fread(buffer, sizeof(buffer), 1, fp);
    *magic_number = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

void read_images(FILE* fp, double* images, int num_images) {
    unsigned char buffer[784];
    for (int i = 0; i < num_images; i++) {
        fread(buffer, sizeof(buffer), 1, fp);
        for (int j = 0; j < 784; j++) {
            images[i * 784 + j] = buffer[j] / 255.0;
        }
    }
}

void read_labels(FILE* fp, int* labels, int num_labels) {
    unsigned char buffer[1];
    for (int i = 0; i < num_labels; i++) {
        fread(buffer, sizeof(buffer), 1, fp);
        labels[i] = buffer[0];
    }
}

// Load the MNIST dataset
void load_mnist(const char* images_file, const char* labels_file, double** X, int** y, int* num_examples) {
    // Read images
    FILE* fp = fopen(images_file, "rb");
    read_magic_number(fp, NULL);
    read_magic_number(fp, num_examples);
    *X = malloc(*num_examples * 784 * sizeof(double));
    read_images(fp, *X, *num_examples);
    fclose(fp);

    // Read labels
    fp = fopen(labels_file, "rb");
    read_magic_number(fp, NULL);
    read_magic_number(fp, NULL);
    *y = malloc(*num_examples * sizeof(int));
    read_labels(fp, *y, *num_examples);
    fclose(fp);
}

// Initialize the neural network weights and biases
void initialize_nn(NeuralNet* nn) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            nn->W1[i][j] = (double) rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            nn->W2[i][j] = (double) rand() / RAND_MAX;
        }
        nn->b2[i] = 0;
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        nn->b1[i] = 0;
    }
}

// Softmax activation function
void softmax(double* x, int n) {
    double max = -INFINITY;
    for (int i = 0; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        x[i] = exp(x[i] - max);
        sum += x[i];
    }
    for (int i = 0; i < n; i++) {
        x[i] /= sum;
    }
}

// Forward pass through the neural network
void forward(NeuralNet* nn, double* x, double* y) {
    double z1[HIDDEN_SIZE];
    double z2[OUTPUT_SIZE];

    // Hidden layer
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        z1[i] = nn->b1[i];
        for (int j = 0; j < INPUT_SIZE; j++) {
            z1[i] += nn->W1[j][i] * x[j];
        }
        y[i] = fmax(0.0, z1[i]);
    }

    // Output layer
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        z2[i] = nn->b2[i];
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            z2[i] += nn->W2[j][i] * y[j];
        }
    }

    softmax(z2, OUTPUT_SIZE);
    memcpy(y, z2, OUTPUT_SIZE * sizeof(double));
}

// Train the neural network using backpropagation
void train(NeuralNet* nn, double* X, int* y, int num_examples, double learning_rate, int num_epochs) {
    double y1[HIDDEN_SIZE];
    double y2[OUTPUT_SIZE];
    double d1[HIDDEN_SIZE];
    double d2[OUTPUT_SIZE];

    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < num_examples; i++) {
            double* x = &X[i * 784];
            int label = y[i];

            // Forward pass
            forward(nn, x, y1);
            memcpy(y2, y1, HIDDEN_SIZE * sizeof(double));

            // Compute deltas for output layer
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                if (j == label) {
                    d2[j] = y2[j] - 1;
                } else {
                    d2[j] = y2[j];
                }
            }

            // Backpropagation through output layer
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                d1[j] = 0;
                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    d1[j] += nn->W2[j][k] * d2[k];
                }
                if (y1[j] <= 0) {
                    d1[j] = 0;
                }
            }

            // Update weights and biases
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                for (int k = 0; k < INPUT_SIZE; k++) {
                    nn->W1[k][j] -= learning_rate * d1[j] * x[k];
                }
                nn->b1[j] -= learning_rate * d1[j];
            }
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    nn->W2[k][j] -= learning_rate * d2[j] * y1[k];
                }
                nn->b2[j] -= learning_rate * d2[j];
            }
        }
    }
}

// Test the neural network on a set of images
void test(NeuralNet* nn, double* X, int* y, int num_examples) {
    int correct = 0;
    for (int i = 0; i < num_examples; i++) {
        double* x = &X[i * 784];
        int label = y[i];

        double y2[OUTPUT_SIZE];
        forward(nn, x, y2);

        int predicted = -1;
        double max_prob = -INFINITY;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (y2[j] > max_prob) {
                predicted = j;
                max_prob = y2[j];
            }
        }

        if (predicted == label) {
            correct++;
        }
    }
    printf("Accuracy: %.2f%%\n", 100.0 * correct / num_examples);
}

int main() {
    // Load the MNIST dataset
    double* X_train;
    int* y_train;
    int num_train_examples;
    load_mnist("train-images-idx3-ubyte", "train-labels-idx1-ubyte", &X_train, &y_train, &num_train_examples);

    double* X_test;
    int* y_test;
    int num_test_examples;
    load_mnist("t10k-images-idx3-ubyte", "t10k-labels-idx1-ubyte", &X_test, &y_test, &num_test_examples);

    // Initialize the neural network
    NeuralNet nn;
    initialize_nn(&nn);

    // Train the neural network
    train(&nn, X_train, y_train, num_train_examples, 0.001, 10);

    // Test the neural network
    test(&nn, X_test, y_test, num_test_examples);

    // Free memory
    free(X_train);
    free(y_train);
    free(X_test);
    free(y_test);

    return 0;
}