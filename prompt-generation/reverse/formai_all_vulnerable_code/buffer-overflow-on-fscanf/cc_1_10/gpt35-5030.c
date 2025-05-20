//FormAI DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784  // 28x28 image
#define HIDDEN_LAYER_SIZE 64
#define OUTPUT_SIZE 10   // 10 possible classes

typedef struct Layer {
    int size;
    double *neurons;
    double *biases;
    double **weights;
} Layer;

typedef struct Network {
    int n_layers;
    Layer *layers;
} Network;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

Layer create_layer(int size, int prev_size) {
    Layer layer;
    layer.size = size;
    layer.neurons = malloc(size * sizeof(double));
    layer.biases = malloc(size * sizeof(double));
    layer.weights = malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        layer.weights[i] = malloc(prev_size * sizeof(double));
        for (int j = 0; j < prev_size; j++) {
            layer.weights[i][j] = ((double)rand() / RAND_MAX) - 0.5;
        }
    }
    for (int i = 0; i < size; i++) {
        layer.biases[i] = ((double)rand() / RAND_MAX) - 0.5;
    }
    return layer;
}

Network create_network(int input_size, int hidden_layer_size, int output_size) {
    Network network;
    network.n_layers = 3;
    network.layers = malloc(network.n_layers * sizeof(Layer));
    network.layers[0] = create_layer(hidden_layer_size, input_size);
    network.layers[1] = create_layer(hidden_layer_size, hidden_layer_size);
    network.layers[2] = create_layer(output_size, hidden_layer_size);
    return network;
}

double *feedforward(Network network, double *input) {
    double *output = malloc(network.layers[network.n_layers-1].size * sizeof(double));
    for (int i = 0; i < network.layers[0].size; i++) {
        network.layers[0].neurons[i] = input[i];
    }
    for (int i = 1; i < network.n_layers; i++) {
        Layer prev_layer = network.layers[i-1];
        Layer layer = network.layers[i];
        for (int j = 0; j < layer.size; j++) {
            double z = 0.0;
            for (int k = 0; k < prev_layer.size; k++) {
                z += layer.weights[j][k] * prev_layer.neurons[k];
            }
            z += layer.biases[j];
            layer.neurons[j] = sigmoid(z);
        }
    }
    for (int i = 0; i < network.layers[network.n_layers-1].size; i++) {
        output[i] = network.layers[network.n_layers-1].neurons[i];
    }
    return output;
}

int predict(double *output, int size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (output[i] > output[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    // Load example image and label
    double input[INPUT_SIZE];
    FILE *fp = fopen("example_image.txt", "r");
    for (int i = 0; i < INPUT_SIZE; i++) {
        fscanf(fp, "%lf,", &input[i]);
    }
    fclose(fp);

    int label;
    fp = fopen("example_label.txt", "r");
    fscanf(fp, "%d", &label);
    fclose(fp);

    // Create network
    Network network = create_network(INPUT_SIZE, HIDDEN_LAYER_SIZE, OUTPUT_SIZE);

    // Feedforward
    double *output = feedforward(network, input);

    // Predict
    int predicted_label = predict(output, OUTPUT_SIZE);

    // Print results
    printf("Input label: %d\n", label);
    printf("Predicted label: %d\n", predicted_label);

    // Cleanup
    free(network.layers[0].neurons);
    free(network.layers[1].neurons);
    free(network.layers[2].neurons);
    free(network.layers[0].biases);
    free(network.layers[1].biases);
    free(network.layers[2].biases);
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        free(network.layers[0].weights[i]);
        free(network.layers[1].weights[i]);
    }
    free(network.layers[0].weights);
    free(network.layers[1].weights);
    free(network.layers[2].weights);
    free(network.layers);
    free(output);

    return 0;
}