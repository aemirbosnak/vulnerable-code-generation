//FormAI DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for image dimensions
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

// Define a struct to represent an image
typedef struct {
    int pixels[IMAGE_WIDTH][IMAGE_HEIGHT];
    int label;
} Image;

// Define a struct to represent a neural network layer
typedef struct {
    int num_inputs;
    int num_outputs;
    float weights[784][10];
    float biases[10];
} Layer;

// Define a function to load a single image from a file
Image loadImage(char* filename) {
    FILE* file = fopen(filename, "r");
    Image img;

    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            fscanf(file, "%d", &img.pixels[i][j]);
        }
    }

    fscanf(file, "%d", &img.label);

    fclose(file);
    return img;
}

// Define a function to initialize a neural network layer with random weights and biases
void initLayer(Layer* layer) {
    for (int i = 0; i < layer->num_inputs; i++) {
        for (int j = 0; j < layer->num_outputs; j++) {
            layer->weights[i][j] = ((float) rand()) / ((float) RAND_MAX);
        }
    }

    for (int i = 0; i < layer->num_outputs; i++) {
        layer->biases[i] = ((float) rand()) / ((float) RAND_MAX);
    }
}

// Define a function to compute the output of a neural network layer given an input vector
void feedForward(Layer* layer, float* input, float* output) {
    for (int i = 0; i < layer->num_outputs; i++) {
        output[i] = 0.0;
        for (int j = 0; j < layer->num_inputs; j++) {
            output[i] += input[j] * layer->weights[j][i];
        }
        output[i] += layer->biases[i];
    }
}

int main() {
    // Load an image from a file
    Image img = loadImage("example_image.txt");

    // Initialize a neural network layer
    Layer layer;
    layer.num_inputs = IMAGE_WIDTH * IMAGE_HEIGHT;
    layer.num_outputs = 10;
    initLayer(&layer);

    // Convert the image pixel matrix into an input vector
    float input[784];
    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            input[i * IMAGE_WIDTH + j] = ((float) img.pixels[i][j]) / 255.0;
        }
    }

    // Compute the output of the neural network layer for this input vector
    float output[10];
    feedForward(&layer, input, output);

    // Find the index of the output neuron with maximum activation
    int max_index = 0;
    for (int i = 1; i < 10; i++) {
        if (output[i] > output[max_index]) {
            max_index = i;
        }
    }

    // Print the predicted label for the image
    printf("Predicted label: %d\n", max_index);

    return 0;
}