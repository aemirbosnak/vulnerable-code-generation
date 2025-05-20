//FormAI DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

// Neural network layers
#define INPUT_LAYER_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define HIDDEN_LAYER_SIZE 32
#define OUTPUT_LAYER_SIZE 10

// Maximum number of images to classify
#define MAX_IMAGES 1000

// Structure to represent an image
typedef struct {
    int label;
    double pixels[IMAGE_WIDTH * IMAGE_HEIGHT];
} Image;

// Function to read images from file
int read_images(char *filename, Image *images, int max_images) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading file %s", filename);
        return 0;
    }
    int count = 0;
    while (!feof(fp) && count < max_images) {
        Image image;
        fscanf(fp, "%d,", &image.label);
        for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
            fscanf(fp, "%lf,", &image.pixels[i]);
        }
        images[count++] = image;
    }
    fclose(fp);
    return count;
}

// Function to normalize pixel values to range from 0 to 1
void normalize_images(Image *images, int num_images) {
    for (int i = 0; i < num_images; i++) {
        for (int j = 0; j < INPUT_LAYER_SIZE; j++) {
            images[i].pixels[j] /= 255.0;
        }
    }
}

// Sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of sigmoid activation function
double sigmoid_derivative(double x) {
    return sigmoid(x) * (1.0 - sigmoid(x));
}

int main() {
    // Read training images
    Image images[MAX_IMAGES];
    int num_images = read_images("train.csv", images, MAX_IMAGES);
    if (num_images == 0) {
        return 1;
    }
    printf("Read %d images\n", num_images);

    // Normalize image pixel values
    normalize_images(images, num_images);

    // Initialize weights for input layer -> hidden layer and bias for hidden layer
    double w1[INPUT_LAYER_SIZE][HIDDEN_LAYER_SIZE];
    double bias1[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < INPUT_LAYER_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            w1[i][j] = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
        }
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        bias1[i] = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
    }

    // Initialize weights for hidden layer -> output layer and bias for output layer
    double w2[HIDDEN_LAYER_SIZE][OUTPUT_LAYER_SIZE];
    double bias2[OUTPUT_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
            w2[i][j] = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
        }
    }
    for (int i = 0; i < OUTPUT_LAYER_SIZE; i++) {
        bias2[i] = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
    }

    // Train neural network with backpropagation
    int num_iterations = 1000;
    double learning_rate = 0.01;
    for (int iter = 0; iter < num_iterations; iter++) {
        double total_error = 0.0;
        for (int i = 0; i < num_images; i++) {
            // Forward pass (input -> hidden layer)
            double hidden[HIDDEN_LAYER_SIZE];
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                hidden[j] = bias1[j];
                for (int k = 0; k < INPUT_LAYER_SIZE; k++) {
                    hidden[j] += images[i].pixels[k] * w1[k][j];
                }
                hidden[j] = sigmoid(hidden[j]);
            }

            // Forward pass (hidden layer -> output)
            double output[OUTPUT_LAYER_SIZE];
            for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
                output[j] = bias2[j];
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    output[j] += hidden[k] * w2[k][j];
                }
                output[j] = sigmoid(output[j]);
            }

            // Backward pass (output -> hidden layer)
            double output_error[OUTPUT_LAYER_SIZE];
            for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
                output_error[j] = images[i].label == j ? output[j] - 1.0 : output[j];
            }
            double hidden_error[HIDDEN_LAYER_SIZE];
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                hidden_error[j] = 0.0;
                for (int k = 0; k < OUTPUT_LAYER_SIZE; k++) {
                    hidden_error[j] += output_error[k] * w2[j][k];
                }
                hidden_error[j] *= sigmoid_derivative(hidden[j]);
            }

            // Update weights and biases
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                for (int k = 0; k < INPUT_LAYER_SIZE; k++) {
                    w1[k][j] -= learning_rate * images[i].pixels[k] * hidden_error[j];
                }
                bias1[j] -= learning_rate * hidden_error[j];
            }
            for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    w2[k][j] -= learning_rate * hidden[k] * output_error[j];
                }
                bias2[j] -= learning_rate * output_error[j];
            }

            // Update total error for this iteration
            for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
                total_error += 0.5 * (images[i].label == j ? 1.0 - output[j] : output[j]) * (images[i].label == j ? 1.0 - output[j] : output[j]);
            }
        }
        total_error /= num_images;
        printf("Iteration %3d: total error = %lf\n", iter, total_error);
    }

    // Read test images
    Image test_images[MAX_IMAGES];
    int num_test_images = read_images("test.csv", test_images, MAX_IMAGES);
    if (num_test_images == 0) {
        return 1;
    }
    printf("Read %d test images\n", num_test_images);

    // Normalize test image pixel values
    normalize_images(test_images, num_test_images);

    // Classify test images
    for (int i = 0; i < num_test_images; i++) {
        // Forward pass (input -> hidden layer)
        double hidden[HIDDEN_LAYER_SIZE];
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            hidden[j] = bias1[j];
            for (int k = 0; k < INPUT_LAYER_SIZE; k++) {
                hidden[j] += test_images[i].pixels[k] * w1[k][j];
            }
            hidden[j] = sigmoid(hidden[j]);
        }

        // Forward pass (hidden layer -> output)
        double output[OUTPUT_LAYER_SIZE];
        for (int j = 0; j < OUTPUT_LAYER_SIZE; j++) {
            output[j] = bias2[j];
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                output[j] += hidden[k] * w2[k][j];
            }
            output[j] = sigmoid(output[j]);
        }

        // Find label with highest output value
        int label = 0;
        for (int j = 1; j < OUTPUT_LAYER_SIZE; j++) {
            if (output[j] > output[label]) {
                label = j;
            }
        }

        printf("Test image %d classified as %d\n", i + 1, label);
    }

    return 0;
}