//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 256
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.1

double sigmoid (double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative (double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

int main () {
    // initialize neurons
    double input_layer[INPUT_SIZE];
    double hidden_layer[HIDDEN_SIZE];
    double output_layer[OUTPUT_SIZE];

    // read input layer from file
    FILE* input_file = fopen("input.txt", "r");
    for (int i = 0; i < INPUT_SIZE; i++) {
        fscanf(input_file, "%lf", &input_layer[i]);
    }
    fclose(input_file);

    // randomly initialize weights
    double hidden_weights[HIDDEN_SIZE][INPUT_SIZE];
    double output_weights[OUTPUT_SIZE][HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_weights[i][j] = ((double) rand() / RAND_MAX - 0.5) * 2;
        }
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_weights[i][j] = ((double) rand() / RAND_MAX - 0.5) * 2;
        }
    }

    // forward pass
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input_layer[j] * hidden_weights[i][j];
        }
        hidden_layer[i] = sigmoid(sum);
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden_layer[j] * output_weights[i][j];
        }
        output_layer[i] = sigmoid(sum);
    }

    // calculate output layer errors
    double expected_output[OUTPUT_SIZE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    double output_errors[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_errors[i] = (expected_output[i] - output_layer[i]) * sigmoid_derivative(output_layer[i]);
    }

    // calculate hidden layer errors
    double hidden_errors[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            sum += output_weights[j][i] * output_errors[j];
        }
        hidden_errors[i] = sum * sigmoid_derivative(hidden_layer[i]);
    }

    // update output weights
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_weights[i][j] += LEARNING_RATE * output_errors[i] * hidden_layer[j];
        }
    }

    // update hidden weights
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_weights[i][j] += LEARNING_RATE * hidden_errors[i] * input_layer[j];
        }
    }

    // output predicted label
    int predicted_label = 0;
    for (int i = 1; i < OUTPUT_SIZE; i++) {
        if (output_layer[i] > output_layer[predicted_label]) {
            predicted_label = i;
        }
    }
    printf("Predicted label: %d\n", predicted_label);

    return 0;
}