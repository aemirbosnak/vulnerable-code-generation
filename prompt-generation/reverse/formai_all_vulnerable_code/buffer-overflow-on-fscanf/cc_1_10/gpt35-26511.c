//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the image
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define IMAGE_SIZE IMAGE_WIDTH*IMAGE_HEIGHT

// Define the number of classes
#define NUM_CLASSES 10

// Define the maximum number of iterations for training
#define MAX_ITERATIONS 100000

// Define the learning rate
#define LEARNING_RATE 0.1

// Define the activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Define the derivative of the activation function
double sigmoid_derivative(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

int main() {
    // Read in the training data
    FILE *train_data_file = fopen("train_data.txt", "r");
    double train_data[NUM_CLASSES][IMAGE_SIZE];
    int train_labels[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        train_labels[i] = i;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(train_data_file, "%lf", &train_data[i][j]);
        }
    }
    fclose(train_data_file);
    
    // Initialize the weights and biases randomly
    double weights[NUM_CLASSES][IMAGE_SIZE];
    double biases[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
        biases[i] = (double)rand() / RAND_MAX;
    }
    
    // Train the model
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Select a random training example
        int example_index = rand() % NUM_CLASSES;
        
        // Feed the input through the network
        double input[IMAGE_SIZE];
        for (int i = 0; i < IMAGE_SIZE; i++) {
            input[i] = train_data[example_index][i];
        }
        double hidden_layer[NUM_CLASSES];
        for (int i = 0; i < NUM_CLASSES; i++) {
            double z = biases[i];
            for (int j = 0; j < IMAGE_SIZE; j++) {
                z += weights[i][j] * input[j];
            }
            hidden_layer[i] = sigmoid(z);
        }
        
        // Compute the output and error
        double output[NUM_CLASSES];
        double expected_output[NUM_CLASSES] = {0};
        expected_output[example_index] = 1;
        for (int i = 0; i < NUM_CLASSES; i++) {
            double z = biases[i];
            for (int j = 0; j < IMAGE_SIZE; j++) {
                z += weights[i][j] * input[j];
            }
            output[i] = sigmoid(z);
        }
        double error[NUM_CLASSES];
        for (int i = 0; i < NUM_CLASSES; i++) {
            error[i] = output[i] - expected_output[i];
        }
        
        // Backpropagate the error
        double grad_weights[NUM_CLASSES][IMAGE_SIZE];
        double grad_biases[NUM_CLASSES];
        for (int i = 0; i < NUM_CLASSES; i++) {
            grad_biases[i] = error[i] * sigmoid_derivative(hidden_layer[i]);
            for (int j = 0; j < IMAGE_SIZE; j++) {
                grad_weights[i][j] = grad_biases[i] * input[j];
            }
        }
        
        // Update the weights and biases
        for (int i = 0; i < NUM_CLASSES; i++) {
            biases[i] -= LEARNING_RATE * grad_biases[i];
            for (int j = 0; j < IMAGE_SIZE; j++) {
                weights[i][j] -= LEARNING_RATE * grad_weights[i][j];
            }
        }
    }
    
    // Read in the test data
    FILE *test_data_file = fopen("test_data.txt", "r");
    double test_data[NUM_CLASSES][IMAGE_SIZE];
    int test_labels[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        test_labels[i] = i;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(test_data_file, "%lf", &test_data[i][j]);
        }
    }
    fclose(test_data_file);
    
    // Compute the accuracy on the test set
    int num_correct = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        double input[IMAGE_SIZE];
        for (int j = 0; j < IMAGE_SIZE; j++) {
            input[j] = test_data[i][j];
        }
        double hidden_layer[NUM_CLASSES];
        for (int j = 0; j < NUM_CLASSES; j++) {
            double z = biases[j];
            for (int k = 0; k < IMAGE_SIZE; k++) {
                z += weights[j][k] * input[k];
            }
            hidden_layer[j] = sigmoid(z);
        }
        double output[NUM_CLASSES];
        for (int j = 0; j < NUM_CLASSES; j++) {
            double z = biases[j];
            for (int k = 0; k < IMAGE_SIZE; k++) {
                z += weights[j][k] * input[k];
            }
            output[j] = sigmoid(z);
        }
        int predicted_label = 0;
        double max_output = output[0];
        for (int j = 1; j < NUM_CLASSES; j++) {
            if (output[j] > max_output) {
                max_output = output[j];
                predicted_label = j;
            }
        }
        if (predicted_label == i) {
            num_correct++;
        }
    }
    double accuracy = (double)num_correct / NUM_CLASSES;
    printf("Test accuracy: %lf\n", accuracy);
    
    return 0;
}