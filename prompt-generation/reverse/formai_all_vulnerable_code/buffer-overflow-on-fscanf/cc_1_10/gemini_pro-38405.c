//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NEURON_COUNT 100
#define IMAGE_SIZE 28
#define IMAGE_DATA_SIZE (IMAGE_SIZE * IMAGE_SIZE)
#define NUM_CLASSES 10

typedef struct {
    float weights[NEURON_COUNT];
    float bias;
} Neuron;

typedef struct {
    Neuron neurons[NUM_CLASSES];
} Classifier;

Classifier* create_classifier() {
    Classifier* classifier = malloc(sizeof(Classifier));
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NEURON_COUNT; j++) {
            classifier->neurons[i].weights[j] = (float) rand() / RAND_MAX;
        }
        classifier->neurons[i].bias = (float) rand() / RAND_MAX;
    }
    return classifier;
}

void train_classifier(Classifier* classifier, float* training_data, int* training_labels, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        float* image_data = training_data + i * IMAGE_DATA_SIZE;
        int label = training_labels[i];

        // Forward pass
        float activations[NUM_CLASSES];
        for (int j = 0; j < NUM_CLASSES; j++) {
            float dot_product = 0;
            for (int k = 0; k < NEURON_COUNT; k++) {
                dot_product += classifier->neurons[j].weights[k] * image_data[k];
            }
            activations[j] = dot_product + classifier->neurons[j].bias;
        }

        // Softmax
        float sum_of_exps = 0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            sum_of_exps += exp(activations[j]);
        }
        for (int j = 0; j < NUM_CLASSES; j++) {
            activations[j] = exp(activations[j]) / sum_of_exps;
        }

        // Update weights and biases
        for (int j = 0; j < NUM_CLASSES; j++) {
            for (int k = 0; k < NEURON_COUNT; k++) {
                classifier->neurons[j].weights[k] -= 0.01 * (activations[j] - (j == label ? 1 : 0)) * image_data[k];
            }
            classifier->neurons[j].bias -= 0.01 * (activations[j] - (j == label ? 1 : 0));
        }
    }
}

int predict_label(Classifier* classifier, float* image_data) {
    // Forward pass
    float activations[NUM_CLASSES];
    for (int j = 0; j < NUM_CLASSES; j++) {
        float dot_product = 0;
        for (int k = 0; k < NEURON_COUNT; k++) {
            dot_product += classifier->neurons[j].weights[k] * image_data[k];
        }
        activations[j] = dot_product + classifier->neurons[j].bias;
    }

    // Softmax
    float sum_of_exps = 0;
    for (int j = 0; j < NUM_CLASSES; j++) {
        sum_of_exps += exp(activations[j]);
    }
    for (int j = 0; j < NUM_CLASSES; j++) {
        activations[j] = exp(activations[j]) / sum_of_exps;
    }

    // Find the class with the highest activation
    int predicted_label = 0;
    float max_activation = activations[0];
    for (int j = 1; j < NUM_CLASSES; j++) {
        if (activations[j] > max_activation) {
            predicted_label = j;
            max_activation = activations[j];
        }
    }
    return predicted_label;
}

int main() {
    // Load the training data
    FILE* training_data_file = fopen("training_data.csv", "r");
    float* training_data = malloc(IMAGE_DATA_SIZE * 10000);
    int* training_labels = malloc(10000);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < IMAGE_DATA_SIZE; j++) {
            fscanf(training_data_file, "%f,", &training_data[i * IMAGE_DATA_SIZE + j]);
        }
        fscanf(training_data_file, "%d\n", &training_labels[i]);
    }
    fclose(training_data_file);

    // Create the classifier
    Classifier* classifier = create_classifier();

    // Train the classifier
    train_classifier(classifier, training_data, training_labels, 10000);

    // Load the test data
    FILE* test_data_file = fopen("test_data.csv", "r");
    float* test_data = malloc(IMAGE_DATA_SIZE * 1000);
    int* test_labels = malloc(1000);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < IMAGE_DATA_SIZE; j++) {
            fscanf(test_data_file, "%f,", &test_data[i * IMAGE_DATA_SIZE + j]);
        }
        fscanf(test_data_file, "%d\n", &test_labels[i]);
    }
    fclose(test_data_file);

    // Evaluate the classifier
    int correct_predictions = 0;
    for (int i = 0; i < 1000; i++) {
        int predicted_label = predict_label(classifier, test_data + i * IMAGE_DATA_SIZE);
        if (predicted_label == test_labels[i]) {
            correct_predictions++;
        }
    }
    float accuracy = (float) correct_predictions / 1000;
    printf("Accuracy: %f\n", accuracy);

    return 0;
}