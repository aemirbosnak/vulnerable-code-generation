//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define NUM_FEATURES 784
#define DATA_SIZE 60000
#define EPOCHS 10
#define LEARNING_RATE 0.001
#define BATCH_SIZE 32

struct Layer {
    int num_nodes;
    double *weights;
    double *bias;
};

typedef struct Layer Layer;

void init_layer(Layer *layer, int num_nodes, int input_size) {
    layer->num_nodes = num_nodes;
    layer->weights = malloc(num_nodes * input_size * sizeof(double));
    layer->bias = malloc(num_nodes * sizeof(double));

    for (int i = 0; i < num_nodes; i++) {
        layer->bias[i] = 0.0;
        for (int j = 0; j < input_size; j++) {
            layer->weights[i * input_size + j] = sqrt(2.0 / (double) input_size) * ((double) rand() / RAND_MAX - 0.5);
        }
    }
}

int predict(double *input, Layer *layers, int num_layers) {
    double *output = malloc(layers[0].num_nodes * sizeof(double));
    double *input_copy = malloc(NUM_FEATURES * sizeof(double));
    for (int i = 0; i < NUM_FEATURES; i++) {
        input_copy[i] = input[i];
    }
    for (int i = 0; i < num_layers; i++) {
        for (int j = 0; j < layers[i].num_nodes; j++) {
            output[j] = layers[i].bias[j];
            for (int k = 0; k < NUM_FEATURES; k++) {
                output[j] += input_copy[k] * layers[i].weights[j * NUM_FEATURES + k];
            }
            if (i != num_layers - 1) {
                output[j] = fmax(output[j], 0.0);
            }
        }
        for (int j = 0; j < layers[i].num_nodes; j++) {
            input_copy[j] = output[j];
        }
    }
    int result = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (output[i] > output[result]) {
            result = i;
        }
    }
    free(output);
    free(input_copy);
    return result;
}

int main() {
    Layer layers[2];
    init_layer(&layers[0], 64, NUM_FEATURES);
    init_layer(&layers[1], NUM_CLASSES, 64);

    double *data = malloc(DATA_SIZE * NUM_FEATURES * sizeof(double));
    int *labels = malloc(DATA_SIZE * sizeof(int));
    FILE *file = fopen("mnist_train.csv", "r");
    for (int i = 0; i < DATA_SIZE; i++) {
        char line[4096];
        fgets(line, 4096, file);
        int label = strtol(line, &line, 10);
        labels[i] = label;
        for (int j = 0; j < NUM_FEATURES; j++) {
            data[i * NUM_FEATURES + j] = strtod(line, &line) / 255.0;
        }
    }
    fclose(file);

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        double accuracy = 0.0;
        for (int i = 0; i < DATA_SIZE; i += BATCH_SIZE) {
            double *batch = data + i * NUM_FEATURES;
            int *batch_labels = labels + i;

            double gradient[NUM_CLASSES][64][NUM_FEATURES];
            double bias_gradient[NUM_CLASSES][64];

            for (int j = 0; j < BATCH_SIZE; j++) {
                int label = batch_labels[j];

                double output[64];
                double input_copy[NUM_FEATURES];
                for (int k = 0; k < NUM_FEATURES; k++) {
                    input_copy[k] = batch[j * NUM_FEATURES + k];
                }
                for (int k = 0; k < 64; k++) {
                    output[k] = layers[0].bias[k];
                    for (int l = 0; l < NUM_FEATURES; l++) {
                        output[k] += input_copy[l] * layers[0].weights[k * NUM_FEATURES + l];
                    }
                    if (output[k] < 0.0) {
                        output[k] = 0.0;
                    }
                }
                double final_output[NUM_CLASSES];
                for (int k = 0; k < NUM_CLASSES; k++) {
                    final_output[k] = 0.0;
                    for (int l = 0; l < 64; l++) {
                        final_output[k] += output[l] * layers[1].weights[k * 64 + l];
                    }
                    final_output[k] += layers[1].bias[k];
                }

                int predict_label = 0;
                for (int k = 0; k < NUM_CLASSES; k++) {
                    if (final_output[k] > final_output[predict_label]) {
                        predict_label = k;
                    }
                }

                if (predict_label == label) {
                    accuracy += 1.0 / DATA_SIZE;
                }

                double one_hot[NUM_CLASSES];
                for (int k = 0; k < NUM_CLASSES; k++) {
                    one_hot[k] = (k == label) ? 1.0 : 0.0;
                }

                double delta2[NUM_CLASSES];
                for (int k = 0; k < NUM_CLASSES; k++) {
                    delta2[k] = (final_output[k] - one_hot[k]) / BATCH_SIZE;
                    bias_gradient[k][0] += delta2[k];
                    for (int l = 0; l < 64; l++) {
                        gradient[k][l][0] += delta2[k] * output[l];
                    }
                }

                for (int k = 0; k < 64; k++) {
                    double delta1 = 0.0;
                    for (int l = 0; l < NUM_CLASSES; l++) {
                        delta1 += delta2[l] * layers[1].weights[l * 64 + k];
                    }
                    delta1 *= (output[k] > 0.0) ? 1.0 : 0.0;
                    for (int l = 0; l < NUM_FEATURES; l++) {
                        gradient[label][k][l] += delta1 * batch[j * NUM_FEATURES + l];
                    }
                    bias_gradient[label][k] += delta1;
                }
            }

            for (int j = 0; j < NUM_CLASSES; j++) {
                for (int k = 0; k < 64; k++) {
                    for (int l = 0; l < NUM_FEATURES; l++) {
                        layers[0].weights[k * NUM_FEATURES + l] -= LEARNING_RATE * gradient[j][k][l];
                    }
                    layers[0].bias[k] -= LEARNING_RATE * bias_gradient[j][k];
                }
                for (int k = 0; k < 64; k++) {
                    layers[1].weights[j * 64 + k] -= LEARNING_RATE * gradient[j][k][0];
                }
                layers[1].bias[j] -= LEARNING_RATE * bias_gradient[j][0];
            }

        }
        printf("Epoch %d, Accuracy = %.4lf\n", epoch + 1, accuracy);
    }

    free(data);
    free(labels);
    free(layers[0].weights);
    free(layers[0].bias);
    free(layers[1].weights);
    free(layers[1].bias);

    return 0;
}