//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of classes
#define NUM_CLASSES 5

// Define the size of the image
#define IMAGE_SIZE 28 * 28

// Define the number of training images
#define NUM_TRAINING_IMAGES 10000

// Define the number of test images
#define NUM_TEST_IMAGES 1000

// Load the training data
float training_data[NUM_TRAINING_IMAGES][IMAGE_SIZE];
int training_labels[NUM_TRAINING_IMAGES];

// Load the test data
float test_data[NUM_TEST_IMAGES][IMAGE_SIZE];
int test_labels[NUM_TEST_IMAGES];

// Load the model
float model[NUM_CLASSES][IMAGE_SIZE];

// Train the model
void train_model() {
  // Initialize the model
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      model[i][j] = 0.0;
    }
  }

  // Train the model on the training data
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    // Get the image
    float* image = training_data[i];

    // Get the label
    int label = training_labels[i];

    // Update the model
    for (int j = 0; j < IMAGE_SIZE; j++) {
      model[label][j] += image[j];
    }
  }

  // Normalize the model
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      model[i][j] /= NUM_TRAINING_IMAGES;
    }
  }
}

// Test the model
void test_model() {
  // Test the model on the test data
  int correct = 0;
  for (int i = 0; i < NUM_TEST_IMAGES; i++) {
    // Get the image
    float* image = test_data[i];

    // Get the label
    int label = test_labels[i];

    // Predict the label
    int predicted_label = -1;
    float max_score = -1.0;
    for (int j = 0; j < NUM_CLASSES; j++) {
      float score = 0.0;
      for (int k = 0; k < IMAGE_SIZE; k++) {
        score += image[k] * model[j][k];
      }
      if (score > max_score) {
        max_score = score;
        predicted_label = j;
      }
    }

    // Check if the prediction is correct
    if (predicted_label == label) {
      correct++;
    }
  }

  // Print the accuracy
  float accuracy = (float)correct / NUM_TEST_IMAGES;
  printf("Accuracy: %f\n", accuracy);
}

// Main function
int main() {
  // Load the training data
  FILE* training_data_file = fopen("training_data.csv", "r");
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      fscanf(training_data_file, "%f,", &training_data[i][j]);
    }
    fscanf(training_data_file, "%d\n", &training_labels[i]);
  }
  fclose(training_data_file);

  // Load the test data
  FILE* test_data_file = fopen("test_data.csv", "r");
  for (int i = 0; i < NUM_TEST_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      fscanf(test_data_file, "%f,", &test_data[i][j]);
    }
    fscanf(test_data_file, "%d\n", &test_labels[i]);
  }
  fclose(test_data_file);

  // Train the model
  train_model();

  // Test the model
  test_model();

  return 0;
}