//FormAI DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 5
#define IMG_SIZE 784 //28x28

// Define structure for each image
typedef struct Image {
    float pixels[IMG_SIZE]; // Flattened pixel values
    int label; // The actual classification category
} Image;

// Randomly initialize weights for neural network
float* initialize_weights(int input_size, int num_hidden_layers, int hidden_size, int output_size) {
    int total_weights = input_size * hidden_size;

    for (int h = 0; h < num_hidden_layers; h++) {
        total_weights += hidden_size * hidden_size;
    }

    total_weights += hidden_size * output_size;

    float* weights = malloc(total_weights * sizeof(float));

    srand(1); // Set random seed to 1
    for (int i = 0; i < total_weights; i++) {
        weights[i] = (float) rand()/RAND_MAX;
    }

    return weights;
}

// Forward pass through neural network and return predicted class
int predict(Image img, float* weights, int input_size, int num_hidden_layers, int hidden_size, int output_size) {
    float* hidden_layer[num_hidden_layers];
    float output[output_size];

    // Initialize hidden layer(s)
    for (int h = 0; h < num_hidden_layers; h++) {
        hidden_layer[h] = malloc(hidden_size * sizeof(float));
    }

    // First hidden layer
    for (int i = 0; i < hidden_size; i++) {
        float dot_product = 0;
        for (int j = 0; j < input_size; j++) {
            dot_product += weights[i*input_size + j] * img.pixels[j];
        }
        hidden_layer[0][i] = 1/(1 + exp(-dot_product));
    }

    // Additional hidden layers
    for (int h = 1; h < num_hidden_layers; h++) {
        for (int i = 0; i < hidden_size; i++) {
            float dot_product = 0;
            for (int j = 0; j < hidden_size; j++) {
                dot_product += weights[input_size*hidden_size + (h-1)*hidden_size*hidden_size + i*hidden_size + j] * hidden_layer[h-1][j];
            }
            hidden_layer[h][i] = 1/(1 + exp(-dot_product));
        }
    }

    // Output layer
    for (int i = 0; i < output_size; i++) {
        float dot_product = 0;
        for (int j = 0; j < hidden_size; j++) {
            dot_product += weights[input_size*hidden_size + num_hidden_layers*hidden_size*hidden_size + i*hidden_size + j] * hidden_layer[num_hidden_layers-1][j];
        }
        output[i] = 1/(1 + exp(-dot_product));
    }

    // Determine predicted class
    int max_index = 0;
    for (int i = 1; i < output_size; i++) {
        if (output[i] > output[max_index]) {
            max_index = i;
        }
    }

    // Free memory used for hidden layers
    for (int h = 0; h < num_hidden_layers; h++) {
        free(hidden_layer[h]);
    }

    return max_index; 
}

// Train neural network using backpropagation
void train_network(float* weights, Image* training_data, int num_images, int input_size, int num_hidden_layers, int hidden_size, int output_size, int num_iterations, float learning_rate) {
    // Loop through each iteration
    for (int i = 0; i < num_iterations; i++) {
        // Loop through each training image
        for (int j = 0; j < num_images; j++) {
            Image img = training_data[j];

            // Feed forward
            float* hidden_layer[num_hidden_layers];
            float output[output_size];

            // Initialize hidden layer(s)
            for (int h = 0; h < num_hidden_layers; h++) {
                hidden_layer[h] = malloc(hidden_size * sizeof(float));
            }

            // First hidden layer
            for (int k = 0; k < hidden_size; k++) {
                float dot_product = 0;
                for (int l = 0; l < input_size; l++) {
                    dot_product += weights[k*input_size + l] * img.pixels[l];
                }
                hidden_layer[0][k] = 1/(1 + exp(-dot_product));
            }

            // Additional hidden layers
            for (int h = 1; h < num_hidden_layers; h++) {
                for (int k = 0; k < hidden_size; k++) {
                    float dot_product = 0;
                    for (int l = 0; l < hidden_size; l++) {
                        dot_product += weights[input_size*hidden_size + (h-1)*hidden_size*hidden_size + k*hidden_size + l] * hidden_layer[h-1][l];
                    }
                    hidden_layer[h][k] = 1/(1 + exp(-dot_product));
                }
            }

            // Output layer
            for (int k = 0; k < output_size; k++) {
                float dot_product = 0;
                for (int l = 0; l < hidden_size; l++) {
                    dot_product += weights[input_size*hidden_size + num_hidden_layers*hidden_size*hidden_size + k*hidden_size + l] * hidden_layer[num_hidden_layers-1][l];
                }
                output[k] = 1/(1 + exp(-dot_product));
            }

            // Backpropagation
            float output_error[output_size];
            for (int k = 0; k < output_size; k++) {
                int label = (k == img.label) ? 1 : 0;
                output_error[k] = output[k] * (1 - output[k]) * (output[k] - label);
            }

            float hidden_error[num_hidden_layers][hidden_size];
            for (int h = 0; h < num_hidden_layers; h++) {
                for (int k = 0; k < hidden_size; k++) {
                    float dot_product = 0;
                    if (h == num_hidden_layers - 1) {
                        for (int l = 0; l < output_size; l++) {
                            dot_product += weights[input_size*hidden_size + num_hidden_layers*hidden_size*hidden_size + l*hidden_size + k] * output_error[l];
                        }
                    } else {
                        for (int l = 0; l < hidden_size; l++) {
                            dot_product += weights[input_size*hidden_size + (h+1)*hidden_size*hidden_size + l*hidden_size + k] * hidden_error[h+1][l];
                        }
                    }
                    hidden_error[h][k] = hidden_layer[h][k] * (1 - hidden_layer[h][k]) * dot_product;
                }
            }

            // Update weights
            for (int k = 0; k < hidden_size; k++) {
                for (int l = 0; l < input_size; l++) {
                    weights[k*input_size + l] -= learning_rate * img.pixels[l] * hidden_error[0][k];
                }
            }

            for (int h = 1; h < num_hidden_layers; h++) {
                for (int k = 0; k < hidden_size; k++) {
                    for (int l = 0; l < hidden_size; l++) {
                        weights[input_size*hidden_size + (h-1)*hidden_size*hidden_size + k*hidden_size + l] -= learning_rate * hidden_layer[h-1][l] * hidden_error[h][k];
                    }
                }
            }

            for (int k = 0; k < output_size; k++) {
                for (int l = 0; l < hidden_size; l++) {
                    weights[input_size*hidden_size + num_hidden_layers*hidden_size*hidden_size + k*hidden_size + l] -= learning_rate * hidden_layer[num_hidden_layers-1][l] * output_error[k];
                }
            }

            // Free memory used for hidden layers
            for (int h = 0; h < num_hidden_layers; h++) {
                free(hidden_layer[h]);
            }
        }
    }
}

int main() {
    // Initialize weight values
    int input_size = IMG_SIZE;
    int num_hidden_layers = 1;
    int hidden_size = 50;
    int output_size = NUM_CLASSES;
    float* weights = initialize_weights(input_size, num_hidden_layers, hidden_size, output_size);

    // Load training data
    int num_train_images = 50000;
    Image* train_data = malloc(num_train_images * sizeof(Image));
    FILE* fp = fopen("train_images.bin", "rb");
    unsigned char buf[IMG_SIZE]; // Assume each image is 28x28 pixels
    for (int i = 0; i < num_train_images; i++) {
        fread(buf, 1, IMG_SIZE, fp);
        for (int j = 0; j < IMG_SIZE; j++) {
            train_data[i].pixels[j] = (float) buf[j] / 255;
        }
    }
    fclose(fp);

    // Load training labels
    fp = fopen("train_labels.bin", "rb");
    for (int i = 0; i < num_train_images; i++) {
        unsigned char label;
        fread(&label, 1, 1, fp);
        train_data[i].label = label;
    }
    fclose(fp);

    // Train neural network
    int num_iterations = 10;
    float learning_rate = 0.1;
    train_network(weights, train_data, num_train_images, input_size, num_hidden_layers, hidden_size, output_size, num_iterations, learning_rate);

    // Load test data
    int num_test_images = 10000;
    Image* test_data = malloc(num_test_images * sizeof(Image));
    fp = fopen("test_images.bin", "rb");
    for (int i = 0; i < num_test_images; i++) {
        fread(buf, 1, IMG_SIZE, fp);
        for (int j = 0; j < IMG_SIZE; j++) {
            test_data[i].pixels[j] = (float) buf[j] / 255;
        }
    }
    fclose(fp);

    // Load test labels
    fp = fopen("test_labels.bin", "rb");
    int correct = 0;
    for (int i = 0; i < num_test_images; i++) {
        unsigned char label;
        fread(&label, 1, 1, fp);
        test_data[i].label = label;

        int predicted_class = predict(test_data[i], weights, input_size, num_hidden_layers, hidden_size, output_size);
        if (predicted_class == test_data[i].label) {
            correct++;
        }
    }
    fclose(fp);

    // Print accuracy
    printf("Accuracy: %f\n", (float) correct / num_test_images);

    return 0;
}