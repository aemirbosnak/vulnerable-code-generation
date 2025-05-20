//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
/**
 * Created by robot on 2020-04-02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of features to use
#define NUM_FEATURES 10

// Define the number of classes
#define NUM_CLASSES 2

// Define the learning rate
#define LEARNING_RATE 0.1

// Define the number of iterations
#define NUM_ITERATIONS 1000

// Define the file name
#define FILE_NAME "data.csv"

// Declare the training data
double training_data[MAX_SENTENCE_LENGTH][NUM_FEATURES];

// Declare the training labels
int training_labels[MAX_SENTENCE_LENGTH];

// Declare the test data
double test_data[MAX_SENTENCE_LENGTH][NUM_FEATURES];

// Declare the test labels
int test_labels[MAX_SENTENCE_LENGTH];

// Declare the model weights
double model_weights[NUM_FEATURES];

// Declare the model bias
double model_bias;

// Function to load the data
void load_data(char *file_name) {
  // Open the file
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the data
  int i = 0;
  while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d", &training_data[i][0], &training_data[i][1], &training_data[i][2], &training_data[i][3], &training_data[i][4], &training_data[i][5], &training_data[i][6], &training_data[i][7], &training_data[i][8], &training_data[i][9], &training_labels[i]) != EOF) {
    i++;
  }

  // Close the file
  fclose(file);
}

// Function to train the model
void train_model() {
  // Initialize the model weights and bias
  for (int i = 0; i < NUM_FEATURES; i++) {
    model_weights[i] = 0.0;
  }
  model_bias = 0.0;

  // Iterate over the training data
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    // Compute the gradient of the loss function
    double gradient[NUM_FEATURES];
    double bias_gradient = 0.0;
    for (int j = 0; j < MAX_SENTENCE_LENGTH; j++) {
      // Compute the predicted label
      double predicted_label = 0.0;
      for (int k = 0; k < NUM_FEATURES; k++) {
        predicted_label += model_weights[k] * training_data[j][k];
      }
      predicted_label += model_bias;

      // Compute the gradient of the loss function
      double error = predicted_label - training_labels[j];
      for (int k = 0; k < NUM_FEATURES; k++) {
        gradient[k] += error * training_data[j][k];
      }
      bias_gradient += error;
    }

    // Update the model weights and bias
    for (int k = 0; k < NUM_FEATURES; k++) {
      model_weights[k] -= LEARNING_RATE * gradient[k];
    }
    model_bias -= LEARNING_RATE * bias_gradient;
  }
}

// Function to test the model
void test_model() {
  // Compute the accuracy of the model
  int correct = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    // Compute the predicted label
    double predicted_label = 0.0;
    for (int j = 0; j < NUM_FEATURES; j++) {
      predicted_label += model_weights[j] * test_data[i][j];
    }
    predicted_label += model_bias;

    // Check if the predicted label is correct
    if (predicted_label > 0.5 && test_labels[i] == 1) {
      correct++;
    } else if (predicted_label <= 0.5 && test_labels[i] == 0) {
      correct++;
    }
  }

  // Print the accuracy of the model
  printf("Accuracy: %lf\n", (double)correct / MAX_SENTENCE_LENGTH);
}

// Main function
int main() {
  // Load the data
  load_data(FILE_NAME);

  // Train the model
  train_model();

  // Test the model
  test_model();

  return 0;
}