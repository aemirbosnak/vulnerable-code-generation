//FormAI DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_NODES 784
#define HIDDEN_NODES 16
#define OUTPUT_NODES 10

float input_layer[INPUT_NODES];
float hidden_layer[HIDDEN_NODES];
float output_layer[OUTPUT_NODES];

float hidden_layer_weights[INPUT_NODES][HIDDEN_NODES];
float output_layer_weights[HIDDEN_NODES][OUTPUT_NODES];
float hidden_layer_biases[HIDDEN_NODES];
float output_layer_biases[OUTPUT_NODES];

// Initialize weights and biases with random values between -1 and 1
void initialize_weights_and_biases() {
    for (int i = 0; i < INPUT_NODES; i++) {
        for (int j = 0; j < HIDDEN_NODES; j++) {
            hidden_layer_weights[i][j] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
        }
    }
    for (int i = 0; i < HIDDEN_NODES; i++) {
        for (int j = 0; j < OUTPUT_NODES; j++) {
            output_layer_weights[i][j] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
        }
        output_layer_biases[i] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
    }
    for (int i = 0; i < HIDDEN_NODES; i++) {
        hidden_layer_biases[i] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
    }
}

// Sigmoid activation function
float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

// Softmax activation function for output layer
void softmax() {
    float max_output = output_layer[0];
    for (int i = 1; i < OUTPUT_NODES; i++) {
        if (output_layer[i] > max_output) {
            max_output = output_layer[i];
        }
    }
    float denominator = 0.0;
    for (int i = 0; i < OUTPUT_NODES; i++) {
        denominator += exp(output_layer[i] - max_output);
    }
    for (int i = 0; i < OUTPUT_NODES; i++) {
        output_layer[i] = exp(output_layer[i] - max_output) / denominator;
    }
}

// Forward propagation
void forward_propagation() {
    // Input layer to hidden layer
    for (int i = 0; i < HIDDEN_NODES; i++) {
        float sum = 0.0;
        for (int j = 0; j < INPUT_NODES; j++) {
            sum += input_layer[j] * hidden_layer_weights[j][i];
        }
        hidden_layer[i] = sigmoid(sum + hidden_layer_biases[i]);
    }
    // Hidden layer to output layer
    for (int i = 0; i < OUTPUT_NODES; i++) {
        float sum = 0.0;
        for (int j = 0; j < HIDDEN_NODES; j++) {
            sum += hidden_layer[j] * output_layer_weights[j][i];
        }
        output_layer[i] = sum + output_layer_biases[i];
    }
    softmax(); // Apply activation function to output layer
}

// Predict the digit 
int predict() {
    int max_index = 0;
    for (int i = 1; i < OUTPUT_NODES; i++) {
        if (output_layer[i] > output_layer[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    // Load input image
    FILE *fptr;
    char filename[50];
    printf("Enter the name of the input image file: \n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (int i = 0; i < INPUT_NODES; i++) {
        fscanf(fptr, "%f", &input_layer[i]);
    }
    fclose(fptr);

    // Initialize weights and biases
    initialize_weights_and_biases();

    // Forward propagation
    forward_propagation();

    // Predict the digit 
    int prediction = predict();
    printf("The input image is classified as digit %d.\n", prediction);

    return 0;
}