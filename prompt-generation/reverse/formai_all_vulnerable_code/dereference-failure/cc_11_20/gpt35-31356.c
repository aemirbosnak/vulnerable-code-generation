//FormAI DATASET v1.0 Category: Image Classification system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define image dimensions
#define HEIGHT 28
#define WIDTH 28
#define NUM_PIXELS (HEIGHT * WIDTH)

// Define number of output classes
#define NUM_CLASSES 10

// Define hyperparameters
#define LEARNING_RATE 0.01
#define NUM_EPOCHS 1000
#define BATCH_SIZE 64

// Define activation function
float relu(float x) {
    if (x < 0) {
        return 0;
    } else {
        return x;
    }
}

// Define softmax function
void softmax(float *arr, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += exp(arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = exp(arr[i]) / sum;
    }
}

// Main function
int main() {
    // Load data and labels
    float *data = (float *) malloc(NUM_PIXELS * sizeof(float));
    int *labels = (int *) malloc(sizeof(int));
    FILE *data_file = fopen("data.bin", "rb");
    FILE *labels_file = fopen("labels.bin", "rb");
    fread(data, sizeof(float), NUM_PIXELS, data_file);
    fread(labels, sizeof(int), 1, labels_file);

    // Initialize weights and biases
    float **weights = (float **) malloc(NUM_CLASSES * sizeof(float *));
    float **biases = (float **) malloc(NUM_CLASSES * sizeof(float *));
    for (int i = 0; i < NUM_CLASSES; i++) {
        weights[i] = (float *) malloc(NUM_PIXELS * sizeof(float));
        biases[i] = (float *) malloc(sizeof(float));
        for (int j = 0; j < NUM_PIXELS; j++) {
            weights[i][j] = rand() / RAND_MAX;
        }
        biases[i][0] = rand() / RAND_MAX;
    }

    // Train model
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        // Shuffle data and labels
        for (int i = 0; i < NUM_PIXELS; i++) {
            int j = rand() % NUM_PIXELS;
            float temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        int j = rand() % 10;
        labels[0] = j;

        // Initialize gradients
        float **grad_weights = (float **) malloc(NUM_CLASSES * sizeof(float *));
        float **grad_biases = (float **) malloc(NUM_CLASSES * sizeof(float *));
        for (int i = 0; i < NUM_CLASSES; i++) {
            grad_weights[i] = (float *) calloc(NUM_PIXELS, sizeof(float));
            grad_biases[i] = (float *) calloc(1, sizeof(float));
        }

        // Loop over batches
        for (int batch = 0; batch < NUM_PIXELS / BATCH_SIZE; batch++) {
            // Initialize batch gradients
            float **batch_grad_weights = (float **) malloc(NUM_CLASSES * sizeof(float *));
            float **batch_grad_biases = (float **) malloc(NUM_CLASSES * sizeof(float *));
            for (int i = 0; i < NUM_CLASSES; i++) {
                batch_grad_weights[i] = (float *) calloc(NUM_PIXELS, sizeof(float));
                batch_grad_biases[i] = (float *) calloc(1, sizeof(float));
            }
            int start_index = batch * BATCH_SIZE;
            int end_index = start_index + BATCH_SIZE - 1;

            // Loop over batch
            for (int i = start_index; i <= end_index; i++) {
                // Forward pass
                float *output = (float *) calloc(NUM_CLASSES, sizeof(float));
                for (int j = 0; j < NUM_CLASSES; j++) {
                    for (int k = 0; k < NUM_PIXELS; k++) {
                        output[j] += weights[j][k] * data[i * NUM_PIXELS + k];
                    }
                    output[j] += biases[j][0];
                    output[j] = relu(output[j]);
                }
                softmax(output, NUM_CLASSES);

                // Backward pass
                int label = labels[0];
                float *grad_output = (float *) calloc(NUM_CLASSES, sizeof(float));
                for (int j = 0; j < NUM_CLASSES; j++) {
                    if (j == label) {
                        grad_output[j] = output[j] - 1;
                    } else {
                        grad_output[j] = output[j];
                    }
                }
                for (int j = 0; j < NUM_CLASSES; j++) {
                    for (int k = 0; k < NUM_PIXELS; k++) {
                        batch_grad_weights[j][k] += grad_output[j] * data[i * NUM_PIXELS + k];
                    }
                    batch_grad_biases[j][0] += grad_output[j];
                }
                free(output);
                free(grad_output);
            }

            // Update gradients
            for (int i = 0; i < NUM_CLASSES; i++) {
                for (int j = 0; j < NUM_PIXELS; j++) {
                    grad_weights[i][j] += batch_grad_weights[i][j] / BATCH_SIZE;
                }
                grad_biases[i][0] += batch_grad_biases[i][0] / BATCH_SIZE;
            }

            // Free batch gradients
            for (int i = 0; i < NUM_CLASSES; i++) {
                free(batch_grad_weights[i]);
                free(batch_grad_biases[i]);
            }
            free(batch_grad_weights);
            free(batch_grad_biases);
        }

        // Update weights and biases
        for (int i = 0; i < NUM_CLASSES; i++) {
            for (int j = 0; j < NUM_PIXELS; j++) {
                weights[i][j] -= LEARNING_RATE * grad_weights[i][j];
            }
            biases[i][0] -= LEARNING_RATE * grad_biases[i][0];
        }

        // Free gradients
        for (int i = 0; i < NUM_CLASSES; i++) {
            free(grad_weights[i]);
            free(grad_biases[i]);
        }
        free(grad_weights);
        free(grad_biases);

        // Print training accuracy
        if (epoch % 10 == 0) {
            int num_correct = 0;
            for (int i = 0; i < NUM_PIXELS; i++) {
                float *output = (float *) calloc(NUM_CLASSES, sizeof(float));
                for (int j = 0; j < NUM_CLASSES; j++) {
                    for (int k = 0; k < NUM_PIXELS; k++) {
                        output[j] += weights[j][k] * data[i * NUM_PIXELS + k];
                    }
                    output[j] += biases[j][0];
                    output[j] = relu(output[j]);
                }
                softmax(output, NUM_CLASSES);
                int pred = 0;
                float best_score = output[0];
                for (int j = 1; j < NUM_CLASSES; j++) {
                    if (output[j] > best_score) {
                        pred = j;
                        best_score = output[j];
                    }
                }
                if (pred == labels[0]) {
                    num_correct++;
                }
                free(output);
            }
            float acc = (float) num_correct / NUM_PIXELS;
            printf("Epoch %d, Accuracy: %f\n", epoch, acc);
        }
    }

    // Free memory
    free(data);
    free(labels);
    for (int i = 0; i < NUM_CLASSES; i++) {
        free(weights[i]);
        free(biases[i]);
    }
    free(weights);
    free(biases);

    return 0;
}