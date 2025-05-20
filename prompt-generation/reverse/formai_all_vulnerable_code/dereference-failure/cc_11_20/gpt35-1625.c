//FormAI DATASET v1.0 Category: Image Classification system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the image size (must be square)
#define IMAGE_SIZE 64

// Define the number of image classes
#define NUM_CLASSES 10

// Define the number of training images per class
#define TRAIN_IMAGES_PER_CLASS 50

// Define the number of testing images per class
#define TEST_IMAGES_PER_CLASS 10

// Define the number of iterations for training
#define NUM_ITERATIONS 1000

// Define the learning rate
#define LEARNING_RATE 0.01

// Define the sigmoid function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

int main() {
    // Allocate memory for training and testing data (an array of image arrays)
    double** train_data = malloc(sizeof(double*) * NUM_CLASSES * TRAIN_IMAGES_PER_CLASS);
    double** test_data = malloc(sizeof(double*) * NUM_CLASSES * TEST_IMAGES_PER_CLASS);
    
    // Fill in training and testing data randomly with values between 0 and 1
    for (int i = 0; i < NUM_CLASSES * TRAIN_IMAGES_PER_CLASS; i++) {
        train_data[i] = malloc(sizeof(double) * IMAGE_SIZE * IMAGE_SIZE);
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            train_data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < NUM_CLASSES * TEST_IMAGES_PER_CLASS; i++) {
        test_data[i] = malloc(sizeof(double) * IMAGE_SIZE * IMAGE_SIZE);
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            test_data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // Allocate memory for weight matrix and bias vector
    double** weights = malloc(sizeof(double*) * NUM_CLASSES);
    double* biases = malloc(sizeof(double) * NUM_CLASSES);
    
    // Initialize weight matrix and bias vector randomly with values between -1 and 1
    for (int i = 0; i < NUM_CLASSES; i++) {
        weights[i] = malloc(sizeof(double) * IMAGE_SIZE * IMAGE_SIZE);
        for (int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
        biases[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    
    // Train the network
    for (int iteration = 1; iteration <= NUM_ITERATIONS; iteration++) {
        // Loop over each training image
        for (int image_index = 0; image_index < NUM_CLASSES * TRAIN_IMAGES_PER_CLASS; image_index++) {
            // Extract the true class label of the image
            int true_class = image_index / TRAIN_IMAGES_PER_CLASS;
            
            // Compute the predictions for all classes
            double predictions[NUM_CLASSES];
            for (int class_index = 0; class_index < NUM_CLASSES; class_index++) {
                double sum = biases[class_index];
                for (int pixel_index = 0; pixel_index < IMAGE_SIZE * IMAGE_SIZE; pixel_index++) {
                    sum += weights[class_index][pixel_index] * train_data[image_index][pixel_index];
                }
                predictions[class_index] = sigmoid(sum);
            }
            
            // Compute the errors for all classes
            double errors[NUM_CLASSES];
            for (int class_index = 0; class_index < NUM_CLASSES; class_index++) {
                if (class_index == true_class) {
                    errors[class_index] = predictions[class_index] - 1;
                } else {
                    errors[class_index] = predictions[class_index];
                }
            }
            
            // Update the weights and biases accordingly
            for (int class_index = 0; class_index < NUM_CLASSES; class_index++) {
                for (int pixel_index = 0; pixel_index < IMAGE_SIZE * IMAGE_SIZE; pixel_index++) {
                    weights[class_index][pixel_index] -= LEARNING_RATE * errors[class_index] * train_data[image_index][pixel_index];
                }
                biases[class_index] -= LEARNING_RATE * errors[class_index];
            }
        }
    }
    
    // Test the network
    int num_correct = 0;
    for (int image_index = 0; image_index < NUM_CLASSES * TEST_IMAGES_PER_CLASS; image_index++) {
        // Extract the true class label of the image
        int true_class = image_index / TEST_IMAGES_PER_CLASS;
        
        // Compute the predictions for all classes
        double predictions[NUM_CLASSES];
        for (int class_index = 0; class_index < NUM_CLASSES; class_index++) {
            double sum = biases[class_index];
            for (int pixel_index = 0; pixel_index < IMAGE_SIZE * IMAGE_SIZE; pixel_index++) {
                sum += weights[class_index][pixel_index] * test_data[image_index][pixel_index];
            }
            predictions[class_index] = sigmoid(sum);
        }
        
        // Choose the class with highest prediction as the predicted class
        int predicted_class = 0;
        for (int class_index = 1; class_index < NUM_CLASSES; class_index++) {
            if (predictions[class_index] > predictions[predicted_class]) {
                predicted_class = class_index;
            }
        }
        
        // Check if the prediction is correct
        if (predicted_class == true_class) {
            num_correct++;
        }
    }
    
    // Print the accuracy
    double accuracy = (double)num_correct / (NUM_CLASSES * TEST_IMAGES_PER_CLASS);
    printf("Accuracy: %.2f%%\n", accuracy * 100);
    
    // Free memory
    for (int i = 0; i < NUM_CLASSES * TRAIN_IMAGES_PER_CLASS; i++) {
        free(train_data[i]);
    }
    for (int i = 0; i < NUM_CLASSES * TEST_IMAGES_PER_CLASS; i++) {
        free(test_data[i]);
    }
    free(train_data);
    free(test_data);
    for (int i = 0; i < NUM_CLASSES; i++) {
        free(weights[i]);
    }
    free(weights);
    free(biases);
    
    return 0;
}