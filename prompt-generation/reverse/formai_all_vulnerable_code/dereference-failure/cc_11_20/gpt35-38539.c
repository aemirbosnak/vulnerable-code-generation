//FormAI DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 10
#define NUM_IMAGES 1000

double images[NUM_IMAGES][28][28];
int labels[NUM_IMAGES];

double weights[784][NUM_CLASSES];
double biases[NUM_CLASSES];

int main() {
    // Load images and labels from file
    FILE *image_file = fopen("images.bin", "rb");
    FILE *label_file = fopen("labels.bin", "rb");
    if (image_file == NULL || label_file == NULL) {
        fprintf(stderr, "Error: could not open image and/or label file\n");
        exit(1);
    }
    for (int i = 0; i < NUM_IMAGES; i++) {
        fread(images[i], sizeof(double), 28 * 28, image_file);
        fread(&labels[i], sizeof(int), 1, label_file);
    }
    fclose(image_file);
    fclose(label_file);

    // Initialize weights and biases randomly
    for (int i = 0; i < 784; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        biases[i] = (double)rand() / RAND_MAX;
    }

    // Train the model using stochastic gradient descent
    double learning_rate = 0.01;
    int num_epochs = 10;
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        double loss = 0.0;
        for (int i = 0; i < NUM_IMAGES; i++) {
            // Make a prediction using the current weights and biases
            double prediction[NUM_CLASSES];
            for (int j = 0; j < NUM_CLASSES; j++) {
                prediction[j] = biases[j];
                for (int k = 0; k < 784; k++) {
                    prediction[j] += weights[k][j] * images[i][k / 28][k % 28];
                }
            }

            // Compute the cross-entropy loss
            double target[NUM_CLASSES] = {0};
            target[labels[i]] = 1;
            for (int j = 0; j < NUM_CLASSES; j++) {
                loss -= target[j] * log(prediction[j]);
            }

            // Update the weights and biases using backpropagation
            for (int j = 0; j < NUM_CLASSES; j++) {
                double error = prediction[j] - target[j];
                biases[j] -= learning_rate * error;
                for (int k = 0; k < 784; k++) {
                    weights[k][j] -= learning_rate * error * images[i][k / 28][k % 28];
                }
            }
        }
        printf("Epoch %d: loss = %lf\n", epoch, loss / NUM_IMAGES);
    }

    return 0;
}