//FormAI DATASET v1.0 Category: Image Classification system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Defining the constants and variables
#define INPUT_NEURONS 784
#define HIDDEN_NEURONS 16
#define OUTPUT_NEURONS 10
#define LEARNING_RATE 0.2

float sigmoid(float x) {
    return (1.0 / (1.0 + exp(-x)));
}

float dsigmoid(float x) {
    return (x * (1 - x));
}

float error(float* output, float* target) {
    float sum = 0;
    for(int i=0;i<OUTPUT_NEURONS;i++) {
        sum += (target[i] - output[i]) * (target[i] - output[i]);
    }
    return sum;
}

int main(){
    // Creating the necessary arrays
    float input[INPUT_NEURONS];
    float hidden[HIDDEN_NEURONS];
    float output[OUTPUT_NEURONS];
    float target[OUTPUT_NEURONS];

    // Reading the input values
    printf("Enter the input values: ");
    for(int i=0;i<INPUT_NEURONS;i++) {
        scanf("%f", &input[i]);
    }

    // Initializing the synaptic weights
    float weights_ih[INPUT_NEURONS][HIDDEN_NEURONS];
    float weights_ho[HIDDEN_NEURONS][OUTPUT_NEURONS];
    for(int i=0;i<INPUT_NEURONS;i++) {
        for(int j=0;j<HIDDEN_NEURONS;j++) {
            weights_ih[i][j] = ((float)rand()/(float)RAND_MAX);
        }
    }
    for(int i=0;i<HIDDEN_NEURONS;i++) {
        for(int j=0;j<OUTPUT_NEURONS;j++) {
            weights_ho[i][j] = ((float)rand()/(float)RAND_MAX);
        }
    }

    // Feedforward pass
    for(int i=0;i<HIDDEN_NEURONS;i++) {
        hidden[i] = 0;
        for(int j=0;j<INPUT_NEURONS;j++) {
            hidden[i] += input[j] * weights_ih[j][i];
        }
        hidden[i] = sigmoid(hidden[i]);
    }
    for(int i=0;i<OUTPUT_NEURONS;i++) {
        output[i] = 0;
        for(int j=0;j<HIDDEN_NEURONS;j++) {
            output[i] += hidden[j] * weights_ho[j][i];
        }
        output[i] = sigmoid(output[i]);
    }

    // Reading the target values
    printf("\nEnter the target values: ");
    for(int i=0;i<OUTPUT_NEURONS;i++) {
        scanf("%f", &target[i]);
    }

    // Backpropagation pass
    float delta_o[OUTPUT_NEURONS];
    float delta_h[HIDDEN_NEURONS];
    for(int i=0;i<OUTPUT_NEURONS;i++) {
        delta_o[i] = (target[i] - output[i]) * dsigmoid(output[i]);
        for(int j=0;j<HIDDEN_NEURONS;j++) {
            weights_ho[j][i] += LEARNING_RATE * hidden[j] * delta_o[i];
        }
    }
    for(int i=0;i<HIDDEN_NEURONS;i++) {
        delta_h[i] = 0;
        for(int j=0;j<OUTPUT_NEURONS;j++) {
            delta_h[i] += delta_o[j] * weights_ho[i][j];
        }
        delta_h[i] *= dsigmoid(hidden[i]);
        for(int j=0;j<INPUT_NEURONS;j++) {
            weights_ih[j][i] += LEARNING_RATE * input[j] * delta_h[i];
        }
    }

    // Printing the final output and error
    printf("\nFinal output: ");
    for(int i=0;i<OUTPUT_NEURONS;i++) {
        printf("%f ", output[i]);
    }
    printf("\nError: %f", error(output, target));

    return 0;
}