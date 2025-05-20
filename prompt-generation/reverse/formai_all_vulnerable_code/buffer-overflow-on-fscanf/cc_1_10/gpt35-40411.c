//FormAI DATASET v1.0 Category: Image Classification system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10

#define LEARNING_RATE 0.1
#define EPOCHS 50
#define BATCH_SIZE 32

// sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// derivative of sigmoid activation function
double sigmoid_prime(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

// initialize weights with random values
void initialize_weights(double *weights, int size) {
    for (int i = 0; i < size; i++) {
        weights[i] = (double) rand() / RAND_MAX;
    }
}

// forward propagation
void forward(double *inputs, double *hidden, double *output, double *w1, double *w2) {
    // hidden layer
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += inputs[j] * w1[j * HIDDEN_SIZE + i];
        }
        hidden[i] = sigmoid(sum);
    }

    // output layer
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += hidden[j] * w2[j * OUTPUT_SIZE + i];
        }
        output[i] = sigmoid(sum);
    }
}

// backward propagation
void backward(double *inputs, double *hidden, double *output, double *target, double *w1, double *w2, double *d_w1, double *d_w2) {
    // output layer error
    double output_error[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_error[i] = (target[i] - output[i]) * sigmoid_prime(output[i]);
    }

    // hidden layer error
    double hidden_error[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            sum += output_error[j] * w2[i * OUTPUT_SIZE + j];
        }
        hidden_error[i] = sum * sigmoid_prime(hidden[i]);
    }

    // update output layer weights
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            d_w2[j * OUTPUT_SIZE + i] += output_error[i] * hidden[j] * LEARNING_RATE;
        }
    }

    // update hidden layer weights
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            d_w1[j * HIDDEN_SIZE + i] += hidden_error[i] * inputs[j] * LEARNING_RATE;
        }
    }
}

// train the neural network
void train(double **inputs, int *targets, int size, double *w1, double *w2) {
    int iterations = (int) ceil((double) size / BATCH_SIZE);
    int index[size];
    for (int i = 0; i < size; i++) {
        index[i] = i;
    }

    for (int e = 0; e < EPOCHS; e++) {
        double d_w1[INPUT_SIZE * HIDDEN_SIZE] = {0.0};
        double d_w2[HIDDEN_SIZE * OUTPUT_SIZE] = {0.0};

        for (int i = 0; i < iterations; i++) {
            int start = i * BATCH_SIZE;
            int end = fmin(start + BATCH_SIZE, size);

            // shuffle data
            for (int j = end - 1; j > start; j--) {
                int k = rand() % (j - start + 1) + start;
                int tmp = index[j];
                index[j] = index[k];
                index[k] = tmp;
            }

            for (int j = start; j < end; j++) {
                double hidden[HIDDEN_SIZE];
                double output[OUTPUT_SIZE];
                forward(inputs[index[j]], hidden, output, w1, w2);
                backward(inputs[index[j]], hidden, output, targets + index[j] * OUTPUT_SIZE, w1, w2, d_w1, d_w2);
            }
        }

        // update weights
        for (int i = 0; i < INPUT_SIZE * HIDDEN_SIZE; i++) {
            w1[i] += d_w1[i];
        }
        for (int i = 0; i < HIDDEN_SIZE * OUTPUT_SIZE; i++) {
            w2[i] += d_w2[i];
        }

        // calculate accuracy
        int correct = 0;
        for (int i = 0; i < size; i++) {
            double output[OUTPUT_SIZE];
            forward(inputs[i], NULL, output, w1, w2);
            int prediction = 0;
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                if (output[j] > output[prediction]) {
                    prediction = j;
                }
            }
            if (prediction == targets[i * OUTPUT_SIZE]) {
                correct++;
            }
        }
        printf("Epoch %d: %.2f%% accuracy\n", e + 1, 100.0 * correct / size);
    }
}

int main() {
    // load data
    FILE *f = fopen("mnist_train.csv", "r");
    double **inputs = (double **) malloc(sizeof(double *) * 60000);
    int *targets = (int *) malloc(sizeof(int) * 60000);
    for (int i = 0; i < 60000; i++) {
        inputs[i] = (double *) malloc(sizeof(double) * INPUT_SIZE);
        fscanf(f, "%d,", &targets[i]);
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(f, "%lf,", &inputs[i][j]);
            inputs[i][j] /= 255.0;
        }
    }
    fclose(f);

    // initialize weights
    double *w1 = (double *) malloc(sizeof(double) * INPUT_SIZE * HIDDEN_SIZE);
    initialize_weights(w1, INPUT_SIZE * HIDDEN_SIZE);
    double *w2 = (double *) malloc(sizeof(double) * HIDDEN_SIZE * OUTPUT_SIZE);
    initialize_weights(w2, HIDDEN_SIZE * OUTPUT_SIZE);

    // train model
    train(inputs, targets, 60000, w1, w2);

    // load test data
    f = fopen("mnist_test.csv", "r");
    double **test_inputs = (double **) malloc(sizeof(double *) * 10000);
    int *test_targets = (int *) malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; i++) {
        test_inputs[i] = (double *) malloc(sizeof(double) * INPUT_SIZE);
        fscanf(f, "%d,", &test_targets[i]);
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(f, "%lf,", &test_inputs[i][j]);
            test_inputs[i][j] /= 255.0;
        }
    }
    fclose(f);

    // test model
    int correct = 0;
    for (int i = 0; i < 10000; i++) {
        double output[OUTPUT_SIZE];
        forward(test_inputs[i], NULL, output, w1, w2);
        int prediction = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (output[j] > output[prediction]) {
                prediction = j;
            }
        }
        if (prediction == test_targets[i]) {
            correct++;
        }
    }
    printf("Test accuracy: %.2f%%\n", 100.0 * correct / 10000);

    // free memory
    for (int i = 0; i < 60000; i++) {
        free(inputs[i]);
    }
    free(inputs);
    free(targets);
    free(w1);
    free(w2);
    for (int i = 0; i < 10000; i++) {
        free(test_inputs[i]);
    }
    free(test_inputs);
    free(test_targets);

    return 0;
}