//FormAI DATASET v1.0 Category: Image Classification system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// declaring the input and output matrices
int input[10][784], output[10][10];

// declaring the weights and biases
double w1[784][128], w2[128][10], b1[128], b2[10];

// function to initialize the weights and biases randomly
void init_weights_and_biases() {
    for (int i = 0; i < 784; i++) {
        for (int j = 0; j < 128; j++) {
            w1[i][j] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
        }
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 10; j++) {
            w2[i][j] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
        }
    }
    for (int i = 0; i < 128; i++) {
        b1[i] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
    }
    for (int i = 0; i < 10; i++) {
        b2[i] = ((double)rand() / (double)RAND_MAX) * 0.1 - 0.05;
    }
}

// function to compute the feedforward pass
void compute_feedforward(int input_index) {
    double hidden_layer[128], output_layer[10];

    // compute the hidden layer neurons
    for (int i = 0; i < 128; i++) {
        hidden_layer[i] = 0.0;
        for (int j = 0; j < 784; j++) {
            hidden_layer[i] += w1[j][i] * input[input_index][j];
        }
        hidden_layer[i] += b1[i];
        hidden_layer[i] = fmax(0.0, hidden_layer[i]); // ReLU activation function
    }

    // compute the output layer neurons
    for (int i = 0; i < 10; i++) {
        output_layer[i] = 0.0;
        for (int j = 0; j < 128; j++) {
            output_layer[i] += w2[j][i] * hidden_layer[j];
        }
        output_layer[i] += b2[i];
        output[input_index][i] = output_layer[i];
    }
}

// function to compute the softmax probability distribution
void compute_softmax(int output_index) {
    double sum = 0.0;
    for (int i = 0; i < 10; i++) {
        sum += exp(output[output_index][i]);
    }
    for (int i = 0; i < 10; i++) {
        output[output_index][i] = exp(output[output_index][i]) / sum;
    }
}

int main() {
    // load the input matrix
    FILE* fp = fopen("input_matrix.txt", "r");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 784; j++) {
            fscanf(fp, "%d", &input[i][j]);
        }
    }
    fclose(fp);

    // initialize the weights and biases
    init_weights_and_biases();

    // compute the feedforward pass and softmax probabilities for each input
    for (int i = 0; i < 10; i++) {
        compute_feedforward(i);
        compute_softmax(i);
    }

    // print the output probabilities
    printf("Output probabilities:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%lf ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}