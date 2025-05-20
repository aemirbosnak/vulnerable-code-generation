//FormAI DATASET v1.0 Category: Image Classification system ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 2
#define IMAGE_SIZE 784 // 28x28

// Function to load image data from file
void load_image_data(float* image_data, char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp != NULL) {
        for (int i = 0; i < IMAGE_SIZE; i++) {
            fscanf(fp, "%f", &image_data[i]);
        }
    }

    fclose(fp);
}

// Function to perform normalized dot product between two vectors
float dot_product(float* v1, float* v2, int n) {
    float dot = 0.0f;

    for (int i = 0; i < n; i++) {
        dot += v1[i] * v2[i];
    }

    return dot / n;
}

// Function to calculate softmax of output layer
void softmax(float* output, int n) {
    float max_val = output[0];

    for (int i = 1; i < n; i++) {
        if (output[i] > max_val) {
            max_val = output[i];
        }
    }

    float exp_sum = 0.0f;

    for (int i = 0; i < n; i++) {
        output[i] = exp(output[i] - max_val);
        exp_sum += output[i];
    }

    for (int i = 0; i < n; i++) {
        output[i] = output[i] / exp_sum;
    }
}

// Function to perform forward pass of neural network
void forward_pass(float* image_data, float* weights, float* biases, float* output) {
    float hidden_layer[NUM_CLASSES];

    for (int i = 0; i < NUM_CLASSES; i++) {
        hidden_layer[i] = dot_product(&weights[i * IMAGE_SIZE], image_data, IMAGE_SIZE) + biases[i];
    }

    softmax(hidden_layer, NUM_CLASSES);

    for (int i = 0; i < NUM_CLASSES; i++) {
        output[i] = hidden_layer[i];
    }
}

int main() {
    float image_data[IMAGE_SIZE];
    float weights[NUM_CLASSES * IMAGE_SIZE];
    float biases[NUM_CLASSES];
    float output[NUM_CLASSES];

    load_image_data(image_data, "test_image.txt");

    // Load weights and biases
    // (not shown in this example program)

    forward_pass(image_data, weights, biases, output);

    // Print predicted class
    int predicted_class = 0;
    float max_val = output[0];

    for (int i = 1; i < NUM_CLASSES; i++) {
        if (output[i] > max_val) {
            predicted_class = i;
            max_val = output[i];
        }
    }

    printf("Predicted class: %d\n", predicted_class);

    return 0;
}