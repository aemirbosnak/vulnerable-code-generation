//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784
#define NUM_HIDDEN_LAYERS 2
#define HIDDEN_LAYER_SIZE 64
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.1

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

int main() {
    // Load training data
    double **input_data = (double **)malloc(sizeof(double *) * 60000);
    int *output_data = (int *)malloc(sizeof(int) * 60000);
    FILE *f = fopen("train.csv", "r");
    char buffer[100];
    fgets(buffer, 100, f); // skip header
    for (int i = 0; i < 60000; i++) {
        input_data[i] = (double *)malloc(sizeof(double) * INPUT_SIZE);
        fscanf(f, "%d,", &output_data[i]);
        for (int j = 0; j < INPUT_SIZE; j++) {
            char c;
            fscanf(f, "%c", &c);
            input_data[i][j] = c / 255.0;
        }
        fscanf(f, "\n");
    }
    fclose(f);

    // Initialize weights
    double **hidden_weights = (double **)malloc(sizeof(double *) * NUM_HIDDEN_LAYERS);
    for (int i = 0; i < NUM_HIDDEN_LAYERS; i++) {
        hidden_weights[i] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE * (i == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE));
        for (int j = 0; j < HIDDEN_LAYER_SIZE * (i == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE); j++) {
            hidden_weights[i][j] = (rand() / (double)RAND_MAX - 0.5) * 2.0 * sqrt(6.0 / (HIDDEN_LAYER_SIZE + (i == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE)));
        }
    }
    double *output_weights = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE * OUTPUT_SIZE);
    for (int i = 0; i < HIDDEN_LAYER_SIZE * OUTPUT_SIZE; i++) {
        output_weights[i] = (rand() / (double)RAND_MAX - 0.5) * 2.0 * sqrt(6.0 / (HIDDEN_LAYER_SIZE + OUTPUT_SIZE));
    }

    // Train the model
    int num_iterations = 100;
    for (int iter = 0; iter < num_iterations; iter++) {
        printf("Iteration %d\n", iter);
        for (int i = 0; i < 60000; i++) {
            // Forward pass
            double **hidden_outputs = (double **)malloc(sizeof(double *) * NUM_HIDDEN_LAYERS);
            hidden_outputs[0] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE);
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                hidden_outputs[0][j] = 0;
                for (int k = 0; k < INPUT_SIZE; k++) {
                    hidden_outputs[0][j] += input_data[i][k] * hidden_weights[0][j * INPUT_SIZE + k];
                }
                hidden_outputs[0][j] = sigmoid(hidden_outputs[0][j]);
            }
            for (int j = 1; j < NUM_HIDDEN_LAYERS; j++) {
                hidden_outputs[j] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE);
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    hidden_outputs[j][k] = 0;
                    for (int l = 0; l < HIDDEN_LAYER_SIZE; l++) {
                        hidden_outputs[j][k] += hidden_outputs[j-1][l] * hidden_weights[j][k * HIDDEN_LAYER_SIZE + l];
                    }
                    hidden_outputs[j][k] = sigmoid(hidden_outputs[j][k]);
                }
            }
            double *output = (double *)malloc(sizeof(double) * OUTPUT_SIZE);
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                output[j] = 0;
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    output[j] += hidden_outputs[NUM_HIDDEN_LAYERS-1][k] * output_weights[k * OUTPUT_SIZE + j];
                }
                output[j] = sigmoid(output[j]);
            }

            // Backward pass
            double *output_grad = (double *)malloc(sizeof(double) * OUTPUT_SIZE);
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                output_grad[j] = (output_data[i] == j ? 1.0 : 0.0) - output[j];
            }
            double **hidden_grads = (double **)malloc(sizeof(double *) * NUM_HIDDEN_LAYERS);
            for (int j = NUM_HIDDEN_LAYERS-1; j >= 0; j--) {
                hidden_grads[j] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE);
                if (j == NUM_HIDDEN_LAYERS-1) {
                    for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                        double error = 0;
                        for (int l = 0; l < OUTPUT_SIZE; l++) {
                            error += output_grad[l] * output_weights[k * OUTPUT_SIZE + l];
                        }
                        hidden_grads[j][k] = error * hidden_outputs[j][k] * (1.0 - hidden_outputs[j][k]);
                    }
                } else {
                    for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                        double error = 0;
                        for (int l = 0; l < HIDDEN_LAYER_SIZE; l++) {
                            error += hidden_grads[j+1][l] * hidden_weights[j+1][l * HIDDEN_LAYER_SIZE + k];
                        }
                        hidden_grads[j][k] = error * hidden_outputs[j][k] * (1.0 - hidden_outputs[j][k]);
                    }
                }

                double **hidden_weights_delta = (double **)malloc(sizeof(double *) * HIDDEN_LAYER_SIZE);
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    hidden_weights_delta[k] = (double *)malloc(sizeof(double) * (j == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE));
                    for (int l = 0; l < (j == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE); l++) {
                        if (j == 0) {
                            hidden_weights_delta[k][l] = LEARNING_RATE * hidden_grads[j][k] * input_data[i][l];
                        } else {
                            hidden_weights_delta[k][l] = LEARNING_RATE * hidden_grads[j][k] * hidden_outputs[j-1][l];
                        }
                        hidden_weights[j][k * (j == 0 ? INPUT_SIZE : HIDDEN_LAYER_SIZE) + l] += hidden_weights_delta[k][l];
                    }
                }
                for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    free(hidden_weights_delta[k]);
                }
                free(hidden_weights_delta);
            }
            double *output_weights_delta = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE * OUTPUT_SIZE);
            for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                for (int k = 0; k < OUTPUT_SIZE; k++) {
                    output_weights_delta[j * OUTPUT_SIZE + k] = LEARNING_RATE * output_grad[k] * hidden_outputs[NUM_HIDDEN_LAYERS-1][j];
                    output_weights[j * OUTPUT_SIZE + k] += output_weights_delta[j * OUTPUT_SIZE + k];
                }
            }
            free(output_grad);
            for (int j = NUM_HIDDEN_LAYERS-1; j >= 0; j--) {
                free(hidden_grads[j]);
            }
            free(hidden_grads);
            free(output);
            for (int j = NUM_HIDDEN_LAYERS-1; j >= 0; j--) {
                free(hidden_outputs[j]);
            }
            free(hidden_outputs[0]);
            free(hidden_outputs);
        }
    }

    // Load test data
    f = fopen("test.csv", "r");
    fgets(buffer, 100, f); // skip header
    int num_correct = 0;
    int num_test = 0;
    while (fgets(buffer, 100, f) != NULL) {
        num_test++;
        double *input = (double *)malloc(sizeof(double) * INPUT_SIZE);
        int output;
        for (int i = 0; i < INPUT_SIZE; i++) {
            char c;
            fscanf(f, "%c", &c);
            input[i] = c / 255.0;
        }
        fscanf(f, "\n");

        // Forward pass
        double **hidden_outputs = (double **)malloc(sizeof(double *) * NUM_HIDDEN_LAYERS);
        hidden_outputs[0] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE);
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            hidden_outputs[0][j] = 0;
            for (int k = 0; k < INPUT_SIZE; k++) {
                hidden_outputs[0][j] += input[k] * hidden_weights[0][j * INPUT_SIZE + k];
            }
            hidden_outputs[0][j] = sigmoid(hidden_outputs[0][j]);
        }
        for (int j = 1; j < NUM_HIDDEN_LAYERS; j++) {
            hidden_outputs[j] = (double *)malloc(sizeof(double) * HIDDEN_LAYER_SIZE);
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                hidden_outputs[j][k] = 0;
                for (int l = 0; l < HIDDEN_LAYER_SIZE; l++) {
                    hidden_outputs[j][k] += hidden_outputs[j-1][l] * hidden_weights[j][k * HIDDEN_LAYER_SIZE + l];
                }
                hidden_outputs[j][k] = sigmoid(hidden_outputs[j][k]);
            }
        }
        double *output_probs = (double *)malloc(sizeof(double) * OUTPUT_SIZE);
        double max_prob = 0;
        int max_idx = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            output_probs[j] = 0;
            for (int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                output_probs[j] += hidden_outputs[NUM_HIDDEN_LAYERS-1][k] * output_weights[k * OUTPUT_SIZE + j];
            }
            output_probs[j] = sigmoid(output_probs[j]);
            if (output_probs[j] > max_prob) {
                max_prob = output_probs[j];
                max_idx = j;
            }
        }

        // Check if correct
        if (max_idx == output) {
            num_correct++;
        }

        // Free memory
        free(input);
        for (int j = NUM_HIDDEN_LAYERS-1; j >= 0; j--) {
            free(hidden_outputs[j]);
        }
        free(hidden_outputs[0]);
        free(hidden_outputs);
        free(output_probs);
    }
    fclose(f);

    // Print accuracy
    printf("Accuracy: %f\n", num_correct / (double)num_test);

    // Free memory
    for (int i = 0; i < 60000; i++) {
        free(input_data[i]);
    }
    free(input_data);
    free(output_data);
    for (int i = 0; i < NUM_HIDDEN_LAYERS; i++) {
        free(hidden_weights[i]);
    }
    free(hidden_weights);
    free(output_weights);
    return 0;
}