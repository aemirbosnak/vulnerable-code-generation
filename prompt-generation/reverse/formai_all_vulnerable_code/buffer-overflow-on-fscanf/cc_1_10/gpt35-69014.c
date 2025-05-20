//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Size variables
#define NUM_FEATURES 784
#define NUM_LABELS 10
#define TRAIN_SIZE 60000
#define TEST_SIZE 10000
#define BATCH_SIZE 128
#define EPOCHS 10

// Function to read in data from files
void readData(FILE* fp, float data[NUM_FEATURES][TRAIN_SIZE], int labels[TRAIN_SIZE]) {
    // Read each line of data
    for (int i = 0; i < TRAIN_SIZE; i++) {
        // Read in label and pixel values
        fscanf(fp, "%d", &labels[i]);
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(fp, ",%f", &data[j][i]);
        }
    }
}

// Function to softmax a given array
void softmax(float arr[NUM_LABELS]) {
    float max = arr[0];
    for (int i = 1; i < NUM_LABELS; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    float sum = 0;
    for (int i = 0; i < NUM_LABELS; i++) {
        arr[i] = expf(arr[i] - max);
        sum += arr[i];
    }

    for (int i = 0; i < NUM_LABELS; i++) {
        arr[i] /= sum;
    }
}

int main() {
    // Open files for reading
    FILE* fp_train_data = fopen("train_data.csv", "r");
    FILE* fp_train_labels = fopen("train_labels.csv", "r");
    FILE* fp_test_data = fopen("test_data.csv", "r");
    FILE* fp_test_labels = fopen("test_labels.csv", "r");

    // Read in data from files
    float train_data[NUM_FEATURES][TRAIN_SIZE];
    int train_labels[TRAIN_SIZE];
    float test_data[NUM_FEATURES][TEST_SIZE];
    int test_labels[TEST_SIZE];
    readData(fp_train_data, train_data, train_labels);
    readData(fp_test_data, test_data, test_labels);

    // Initialize weights and bias
    float weights[NUM_LABELS][NUM_FEATURES] = {};
    float bias[NUM_LABELS] = {};

    // Train the model
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        // Shuffle the training data
        for (int i = 0; i < TRAIN_SIZE; i++) {
            int j = rand() % TRAIN_SIZE;
            float tmp[NUM_FEATURES];
            memcpy(tmp, train_data[j], sizeof(tmp));
            memcpy(train_data[j], train_data[i], sizeof(tmp));
            memcpy(train_data[i], tmp, sizeof(tmp));
            int tmp_label = train_labels[j];
            train_labels[j] = train_labels[i];
            train_labels[i] = tmp_label;
        }

        // Train in batches
        for (int batch = 0; batch < TRAIN_SIZE / BATCH_SIZE; batch++) {
            // Initialize gradients
            float gradients[NUM_LABELS][NUM_FEATURES] = {};
            float bias_gradient[NUM_LABELS] = {};

            // Calculate gradients for each sample in the batch
            for (int i = 0; i < BATCH_SIZE; i++) {
                // Calculate logits
                float logits[NUM_LABELS] = {};
                for (int j = 0; j < NUM_LABELS; j++) {
                    for (int k = 0; k < NUM_FEATURES; k++) {
                        logits[j] += weights[j][k] * train_data[k][batch * BATCH_SIZE + i];
                    }
                    logits[j] += bias[j];
                }

                // Softmax the logits
                softmax(logits);

                // Calculate loss and gradient
                int label = train_labels[batch * BATCH_SIZE + i];
                float loss_grad[NUM_LABELS] = {};
                for (int j = 0; j < NUM_LABELS; j++) {
                    loss_grad[j] = logits[j] - (j == label);
                }

                // Calculate gradients and update
                for (int j = 0; j < NUM_LABELS; j++) {
                    bias_gradient[j] += loss_grad[j];
                    for (int k = 0; k < NUM_FEATURES; k++) {
                        gradients[j][k] += loss_grad[j] * train_data[k][batch * BATCH_SIZE + i];
                    }
                }
            }

            // Update weights and bias
            for (int i = 0; i < NUM_LABELS; i++) {
                for (int j = 0; j < NUM_FEATURES; j++) {
                    weights[i][j] -= gradients[i][j] / BATCH_SIZE;
                }
                bias[i] -= bias_gradient[i] / BATCH_SIZE;
            }
        }
    }

    // Evaluate the model on test data
    int correct = 0;
    for (int i = 0; i < TEST_SIZE; i++) {
        // Calculate logits
        float logits[NUM_LABELS] = {};
        for (int j = 0; j < NUM_LABELS; j++) {
            for (int k = 0; k < NUM_FEATURES; k++) {
                logits[j] += weights[j][k] * test_data[k][i];
            }
            logits[j] += bias[j];
        }

        // Softmax the logits
        softmax(logits);

        // Get predicted label
        int predicted_label = 0;
        for (int j = 1; j < NUM_LABELS; j++) {
            if (logits[j] > logits[predicted_label]) {
                predicted_label = j;
            }
        }

        // Check if prediction is correct
        if (predicted_label == test_labels[i]) {
            correct++;
        }
    }

    // Print accuracy
    printf("Accuracy: %.2f%%\n", (float) correct / TEST_SIZE * 100);

    // Close files
    fclose(fp_train_data);
    fclose(fp_train_labels);
    fclose(fp_test_data);
    fclose(fp_test_labels);

    return 0;
}