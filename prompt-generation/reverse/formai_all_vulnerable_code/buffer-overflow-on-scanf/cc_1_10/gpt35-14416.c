//FormAI DATASET v1.0 Category: Image Classification system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10

double weights_ih[INPUT_SIZE][HIDDEN_SIZE];
double weights_ho[HIDDEN_SIZE][OUTPUT_SIZE];

/* Initialize the weights randomly */
void init_weights() {
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            weights_ih[i][j] = rand() / (double) RAND_MAX;
        }
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weights_ho[i][j] = rand() / (double) RAND_MAX;
        }
    }
}

/* Sigmoid activation function */
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

/* Feedforward function */
void feedforward(double input[INPUT_SIZE], double output[OUTPUT_SIZE]) {
    double hidden[HIDDEN_SIZE];

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;

        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input[j] * weights_ih[j][i];
        }

        hidden[i] = sigmoid(sum);
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;

        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden[j] * weights_ho[j][i];
        }

        output[i] = sigmoid(sum);
    }
}

/* Example program main function */
int main() {
    double input[INPUT_SIZE];
    double output[OUTPUT_SIZE];
    int choice;

    printf("Welcome to the Image Classification System example program!\n");
    printf("To classify an image, please enter the pixel values (0-255) of the image:\n");
    
    for (int i = 0; i < INPUT_SIZE; i++) {
        printf("Pixel %d: ", i+1);
        scanf("%lf", &input[i]);
    }

    init_weights();
    feedforward(input, output);

    printf("\n\n");
    printf("RESULTS:\n");
    printf("Classification Confidence:\n");
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("Class %d: %f\n", i, output[i]);
    }

    return 0;
}