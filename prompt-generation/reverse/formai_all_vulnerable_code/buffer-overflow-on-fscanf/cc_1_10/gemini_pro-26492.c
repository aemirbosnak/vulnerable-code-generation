//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of classes
#define NUM_CLASSES 3

// Define the size of the image
#define IMAGE_SIZE 28 * 28

// Define the number of training images
#define NUM_TRAINING_IMAGES 1000

// Define the number of testing images
#define NUM_TESTING_IMAGES 100

// Load the training data
float training_data[NUM_TRAINING_IMAGES][IMAGE_SIZE];
int training_labels[NUM_TRAINING_IMAGES];

// Load the testing data
float testing_data[NUM_TESTING_IMAGES][IMAGE_SIZE];
int testing_labels[NUM_TESTING_IMAGES];

// Define the weights for each class
float weights[NUM_CLASSES];

// Define the bias for each class
float bias[NUM_CLASSES];

// Train the model
void train_model() {
  // Initialize the weights and biases
  for (int i = 0; i < NUM_CLASSES; i++) {
    weights[i] = 0.0;
    bias[i] = 0.0;
  }

  // Train the model using the training data
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    // Compute the dot product of the weights and the image
    float dot_product = 0.0;
    for (int j = 0; j < IMAGE_SIZE; j++) {
      dot_product += weights[training_labels[i]] * training_data[i][j];
    }

    // Add the bias
    dot_product += bias[training_labels[i]];

    // Compute the output of the model
    float output = 1.0 / (1.0 + exp(-dot_product));

    // Update the weights and biases
    for (int j = 0; j < IMAGE_SIZE; j++) {
      weights[training_labels[i]] += training_data[i][j] * (output - 1.0);
    }
    bias[training_labels[i]] += (output - 1.0);
  }
}

// Test the model
void test_model() {
  // Test the model using the testing data
  int correct_predictions = 0;
  for (int i = 0; i < NUM_TESTING_IMAGES; i++) {
    // Compute the dot product of the weights and the image
    float dot_product = 0.0;
    for (int j = 0; j < IMAGE_SIZE; j++) {
      dot_product += weights[testing_labels[i]] * testing_data[i][j];
    }

    // Add the bias
    dot_product += bias[testing_labels[i]];

    // Compute the output of the model
    float output = 1.0 / (1.0 + exp(-dot_product));

    // Check if the prediction is correct
    if (output > 0.5) {
      if (testing_labels[i] == 1) {
        correct_predictions++;
      }
    } else {
      if (testing_labels[i] == 0) {
        correct_predictions++;
      }
    }
  }

  // Print the accuracy
  float accuracy = (float)correct_predictions / NUM_TESTING_IMAGES;
  printf("Accuracy: %f\n", accuracy);
}

// Main function
int main() {
  // Load the training data
  FILE *training_data_file = fopen("training_data.txt", "r");
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      fscanf(training_data_file, "%f", &training_data[i][j]);
    }
    fscanf(training_data_file, "%d", &training_labels[i]);
  }
  fclose(training_data_file);

  // Load the testing data
  FILE *testing_data_file = fopen("testing_data.txt", "r");
  for (int i = 0; i < NUM_TESTING_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      fscanf(testing_data_file, "%f", &testing_data[i][j]);
    }
    fscanf(testing_data_file, "%d", &testing_labels[i]);
  }
  fclose(testing_data_file);

  // Train the model
  train_model();

  // Test the model
  test_model();

  return 0;
}