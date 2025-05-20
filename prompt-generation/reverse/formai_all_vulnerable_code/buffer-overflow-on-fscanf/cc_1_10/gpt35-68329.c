//FormAI DATASET v1.0 Category: Image Classification system ; Style: single-threaded
// A Single-threaded C Image Classification System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define IMG_HEIGHT 28
#define IMG_WIDTH 28
#define IMG_TOTAL_SIZE 784
#define LABEL_SIZE 10
#define INPUT_FILE "test_data.txt"
#define WEIGHTS_FILE "weights_data.txt"

// Functions
void sigmoid(double* x, int size);
void load_input_data(double* input_data);
void load_weights(double** weights, double* bias);
int classify_image(double* input_data, double* weights, double bias);

int main() {
    // Load Input Data
    double input_data[IMG_TOTAL_SIZE];
    load_input_data(input_data);

    // Load Weights and Bias
    double* weights;
    double bias;
    load_weights(&weights, &bias);

    // Classify Image
    int predicted_label = classify_image(input_data, weights, bias);

    // Print Predicted Label
    printf("Predicted Label: %d\n", predicted_label);

    // Free Memory
    free(weights);

    return 0;
}

// Sigmoid Function
void sigmoid(double* x, int size) {
    for(int i=0; i<size; i++) {
        x[i] = 1.0 / (1.0 + exp(-x[i]));
    }
}

// Load Input Data
void load_input_data(double* input_data) {
    FILE* fp = fopen(INPUT_FILE, "r");
    if(fp == NULL) {
        printf("Error: Failed to open file: %s\n", INPUT_FILE);
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<IMG_TOTAL_SIZE; i++) {
        fscanf(fp, "%lf,", &input_data[i]);
    }

    fclose(fp);
}

// Load Weights and Bias
void load_weights(double** weights, double* bias) {
    // Allocate Memory for Weights
    *weights = (double*)malloc(LABEL_SIZE * IMG_TOTAL_SIZE * sizeof(double));
    if(*weights == NULL) {
        printf("Error: Failed to allocate memory for weights\n");
        exit(EXIT_FAILURE);
    }

    // Load Weights and Bias
    FILE* fp = fopen(WEIGHTS_FILE, "r");
    if(fp == NULL) {
        printf("Error: Failed to open file: %s\n", WEIGHTS_FILE);
        exit(EXIT_FAILURE);
    }

    // Load Weights
    for(int i=0; i<LABEL_SIZE; i++) {
        for(int j=0; j<IMG_TOTAL_SIZE; j++) {
            fscanf(fp, "%lf,", &(*weights)[i*IMG_TOTAL_SIZE+j]);
        }
    }

    // Load Bias
    fscanf(fp, "%lf", bias);

    // Close File
    fclose(fp);
}

// Classify Image
int classify_image(double* input_data, double* weights, double bias) {
    // Calculate Outputs
    double outputs[LABEL_SIZE] = {0};
    for(int i=0; i<LABEL_SIZE; i++) {
        for(int j=0; j<IMG_TOTAL_SIZE; j++) {
            outputs[i] += input_data[j] * weights[i*IMG_TOTAL_SIZE+j];
        }
        outputs[i] += bias;
    }

    // Pass Outputs through Sigmoid Function
    sigmoid(outputs, LABEL_SIZE);

    // Find Max Output
    int max_index = 0;
    double max_val = outputs[0];
    for(int i=1; i<LABEL_SIZE; i++) {
        if(outputs[i] > max_val) {
            max_val = outputs[i];
            max_index = i;
        }
    }

    return max_index;
}