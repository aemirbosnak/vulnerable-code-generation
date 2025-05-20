//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 784
#define HIDDEN_LAYER_SIZE 256
#define OUTPUT_SIZE 10
#define LEARNING_RATE 0.01
#define EPOCHS 10
#define TRAIN_SIZE 60000
#define TEST_SIZE 10000

// function to read MNIST dataset
void read_mnist(char *filename, int size, int num_images, unsigned char images[][size]) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 16, SEEK_SET);
    for(int i = 0; i < num_images; i++) {
        fread(images[i], sizeof(unsigned char), size, fp);
    }
    fclose(fp);
}

int main() {
    // read training images and labels
    unsigned char train_images[TRAIN_SIZE][INPUT_SIZE];
    unsigned char train_labels[TRAIN_SIZE];
    read_mnist("train-images.idx3-ubyte", INPUT_SIZE, TRAIN_SIZE, train_images);
    FILE *fp = fopen("train-labels.idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    fread(train_labels, sizeof(unsigned char), TRAIN_SIZE, fp);
    fclose(fp);

    // read test images and labels
    unsigned char test_images[TEST_SIZE][INPUT_SIZE];
    unsigned char test_labels[TEST_SIZE];
    read_mnist("t10k-images.idx3-ubyte", INPUT_SIZE, TEST_SIZE, test_images);
    fp = fopen("t10k-labels.idx1-ubyte", "rb");
    fseek(fp, 8, SEEK_SET);
    fread(test_labels, sizeof(unsigned char), TEST_SIZE, fp);
    fclose(fp);

    // initialize weights and biases
    float input_hidden_weights[INPUT_SIZE][HIDDEN_LAYER_SIZE];
    float hidden_output_weights[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];
    float hidden_bias[HIDDEN_LAYER_SIZE];
    float output_bias[OUTPUT_SIZE];
    for(int i = 0; i < INPUT_SIZE; i++) {
        for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            input_hidden_weights[i][j] = 2 * (((float) rand() / RAND_MAX) - 0.5) * 0.5;
        }
    }
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for(int j = 0; j < OUTPUT_SIZE; j++) {
            hidden_output_weights[i][j] = 2 * (((float) rand() / RAND_MAX) - 0.5) * 0.5;
        }
    }
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        hidden_bias[i] = ((float) rand() / RAND_MAX) - 0.5;
    }
    for(int i = 0; i < OUTPUT_SIZE; i++) {
        output_bias[i] = ((float) rand() / RAND_MAX) - 0.5;
    }

    // train the neural network
    for(int epoch = 0; epoch < EPOCHS; epoch++) {
        float total_loss = 0.0;
        for(int i = 0; i < TRAIN_SIZE; i++) {
            // forward pass
            float hidden_layer[HIDDEN_LAYER_SIZE];
            float output_layer[OUTPUT_SIZE];
            for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                hidden_layer[j] = 0.0;
                for(int k = 0; k < INPUT_SIZE; k++) {
                    hidden_layer[j] += (float)train_images[i][k] / 255.0 * input_hidden_weights[k][j];
                }
                hidden_layer[j] = 1.0 / (1.0 + exp(-hidden_layer[j] - hidden_bias[j]));
            }
            for(int j = 0; j < OUTPUT_SIZE; j++) {
                output_layer[j] = 0.0;
                for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    output_layer[j] += hidden_layer[k] * hidden_output_weights[k][j];
                }
                output_layer[j] += output_bias[j];
            }

            // calculate loss
            float loss = 0.0;
            for(int j = 0; j < OUTPUT_SIZE; j++) {
                if(j == train_labels[i]) {
                    loss += -log(output_layer[j] + 1e-9);
                } else {
                    loss += -log(1.0 - output_layer[j] + 1e-9);
                }
            }
            total_loss += loss;

            // backward pass
            float errors_output[OUTPUT_SIZE];
            for(int j = 0; j < OUTPUT_SIZE; j++) {
                if(j == train_labels[i]) {
                    errors_output[j] = output_layer[j] - 1.0;
                } else {
                    errors_output[j] = output_layer[j];
                }
            }
            float errors_hidden[HIDDEN_LAYER_SIZE];
            for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                errors_hidden[j] = 0.0;
                for(int k = 0; k < OUTPUT_SIZE; k++) {
                    errors_hidden[j] += errors_output[k] * hidden_output_weights[j][k];
                }
                errors_hidden[j] *= hidden_layer[j] * (1.0 - hidden_layer[j]);
            }

            // update weights and biases
            for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                for(int k = 0; k < INPUT_SIZE; k++) {
                    input_hidden_weights[k][j] -= LEARNING_RATE * errors_hidden[j] * (float)train_images[i][k] / 255.0;
                }
                hidden_bias[j] -= LEARNING_RATE * errors_hidden[j] * 1.0;
            }
            for(int j = 0; j < OUTPUT_SIZE; j++) {
                for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    hidden_output_weights[k][j] -= LEARNING_RATE * errors_output[j] * hidden_layer[k];
                }
                output_bias[j] -= LEARNING_RATE * errors_output[j] * 1.0;
            }
        }
        printf("Epoch %d: Average Loss = %.6f\n", epoch + 1, total_loss / TRAIN_SIZE);
    }

    // test the neural network
    int correct = 0;
    for(int i = 0; i < TEST_SIZE; i++) {
        // forward pass
        float hidden_layer[HIDDEN_LAYER_SIZE];
        float output_layer[OUTPUT_SIZE];
        for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            hidden_layer[j] = 0.0;
            for(int k = 0; k < INPUT_SIZE; k++) {
                hidden_layer[j] += (float)test_images[i][k] / 255.0 * input_hidden_weights[k][j];
            }
            hidden_layer[j] = 1.0 / (1.0 + exp(-hidden_layer[j] - hidden_bias[j]));
        }
        for(int j = 0; j < OUTPUT_SIZE; j++) {
            output_layer[j] = 0.0;
            for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                output_layer[j] += hidden_layer[k] * hidden_output_weights[k][j];
            }
            output_layer[j] += output_bias[j];
        }

        // determine predicted class
        int predicted_class = 0;
        float highest_probability = 0.0;
        for(int j = 0; j < OUTPUT_SIZE; j++) {
            if(output_layer[j] > highest_probability) {
                predicted_class = j;
                highest_probability = output_layer[j];
            }
        }

        // check if predicted class matches actual class
        if(predicted_class == test_labels[i]) {
            correct++;
        }
    }
    printf("Test Accuracy = %.2f%%\n", (float)correct / TEST_SIZE * 100.0);

    return 0;
}