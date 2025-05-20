//FormAI DATASET v1.0 Category: Image Classification system ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the image dataset and the number of classes
#define NUM_IMAGES 1000
#define NUM_CLASSES 10

// Define the size of each image
#define IMAGE_SIZE 784 // 28x28 pixels

int main() {

    // Welcome to the Cyberpunk Image Classification System..!

    printf("Welcome to the Cyberpunk Image Classification System..!\n");

    // Load the image dataset into memory

    int images[NUM_IMAGES][IMAGE_SIZE];
    int labels[NUM_IMAGES];

    FILE *fp = fopen("images.dat", "r");
    for (int i = 0; i < NUM_IMAGES; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(fp, "%d", &images[i][j]);
        }
        fscanf(fp, "%d", &labels[i]);
    }
    fclose(fp);

    // Define the neural network architecture

    int input_size = IMAGE_SIZE;
    int hidden_size = 128;
    int output_size = NUM_CLASSES;

    float weights1[input_size][hidden_size];
    float biases1[hidden_size];
    float weights2[hidden_size][output_size];
    float biases2[output_size];

    // Initialize the weights and biases randomly

    srand(42);
    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < hidden_size; j++) {
            weights1[i][j] = ((float)rand() / RAND_MAX) * 0.2 - 0.1;
        }
    }

    for (int i = 0; i < hidden_size; i++) {
        biases1[i] = ((float)rand() / RAND_MAX) * 0.2 - 0.1;
    }

    for (int i = 0; i < hidden_size; i++) {
        for (int j = 0; j < output_size; j++) {
            weights2[i][j] = ((float)rand() / RAND_MAX) * 0.2 - 0.1;
        }
    }

    for (int i = 0; i < output_size; i++) {
        biases2[i] = ((float)rand() / RAND_MAX) * 0.2 - 0.1;
    }

    // Train the neural network using backpropagation

    int num_epochs = 100;
    float learning_rate = 0.1;

    for (int epoch = 0; epoch < num_epochs; epoch++) {

        // Loop through each image in the dataset
        for (int i = 0; i < NUM_IMAGES; i++) {

            // Set the input and target output vectors
            float input[input_size];
            float target_output[output_size];
            for (int j = 0; j < input_size; j++) {
                input[j] = (float)images[i][j] / 255.0;
            }
            for (int j = 0; j < output_size; j++) {
                target_output[j] = (j == labels[i]) ? 1.0 : 0.0;
            }

            // Perform forward propagation
            float hidden[hidden_size];
            float output[output_size];
            for (int j = 0; j < hidden_size; j++) {
                hidden[j] = biases1[j];
                for (int k = 0; k < input_size; k++) {
                    hidden[j] += input[k] * weights1[k][j];
                }
                hidden[j] = (hidden[j] > 0) ? hidden[j] : 0; // ReLU activation function
            }
            for (int j = 0; j < output_size; j++) {
                output[j] = biases2[j];
                for (int k = 0; k < hidden_size; k++) {
                    output[j] += hidden[k] * weights2[k][j];
                }
                output[j] = 1.0 / (1.0 + exp(-output[j])); // Sigmoid activation function
            }

            // Perform backward propagation
            float delta_output[output_size];
            float delta_hidden[hidden_size];
            for (int j = 0; j < output_size; j++) {
                delta_output[j] = output[j] - target_output[j];
            }
            for (int j = 0; j < hidden_size; j++) {
                delta_hidden[j] = 0;
                for (int k = 0; k < output_size; k++) {
                    delta_hidden[j] += delta_output[k] * weights2[j][k];
                }
                delta_hidden[j] *= (hidden[j] > 0) ? 1 : 0; // Derivative of ReLU activation function
            }
            for (int j = 0; j < output_size; j++) {
                biases2[j] -= learning_rate * delta_output[j];
                for (int k = 0; k < hidden_size; k++) {
                    weights2[k][j] -= learning_rate * hidden[k] * delta_output[j];
                }
            }
            for (int j = 0; j < hidden_size; j++) {
                biases1[j] -= learning_rate * delta_hidden[j];
                for (int k = 0; k < input_size; k++) {
                    weights1[k][j] -= learning_rate * input[k] * delta_hidden[j];
                }
            }
        }

        // Print the current epoch and accuracy
        int correct = 0;
        for (int i = 0; i < NUM_IMAGES; i++) {
            float input[input_size];
            for (int j = 0; j < input_size; j++) {
                input[j] = (float)images[i][j] / 255.0;
            }
            float hidden[hidden_size];
            float output[output_size];
            for (int j = 0; j < hidden_size; j++) {
                hidden[j] = biases1[j];
                for (int k = 0; k < input_size; k++) {
                    hidden[j] += input[k] * weights1[k][j];
                }
                hidden[j] = (hidden[j] > 0) ? hidden[j] : 0; // ReLU activation function
            }
            for (int j = 0; j < output_size; j++) {
                output[j] = biases2[j];
                for (int k = 0; k < hidden_size; k++) {
                    output[j] += hidden[k] * weights2[k][j];
                }
                output[j] = 1.0 / (1.0 + exp(-output[j])); // Sigmoid activation function
            }
            int prediction = 0;
            for (int j = 1; j < output_size; j++) {
                if (output[j] > output[prediction]) {
                    prediction = j;
                }
            }
            if (prediction == labels[i]) {
                correct++;
            }
        }
        float accuracy = (float)correct / NUM_IMAGES;
        printf("Epoch %d, Accuracy = %.2f%%\n", epoch+1, accuracy*100);
    }

    // Save the learned weights and biases to disk

    fp = fopen("weights1.dat", "w");
    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < hidden_size; j++) {
            fprintf(fp, "%.10f\n", weights1[i][j]);
        }
    }
    fclose(fp);

    fp = fopen("biases1.dat", "w");
    for (int i = 0; i < hidden_size; i++) {
        fprintf(fp, "%.10f\n", biases1[i]);
    }
    fclose(fp);

    fp = fopen("weights2.dat", "w");
    for (int i = 0; i < hidden_size; i++) {
        for (int j = 0; j < output_size; j++) {
            fprintf(fp, "%.10f\n", weights2[i][j]);
        }
    }
    fclose(fp);

    fp = fopen("biases2.dat", "w");
    for (int i = 0; i < output_size; i++) {
        fprintf(fp, "%.10f\n", biases2[i]);
    }
    fclose(fp);

    // Sayonara..!

    printf("Thank you for using the Cyberpunk Image Classification System..!\n");

    return 0;
}