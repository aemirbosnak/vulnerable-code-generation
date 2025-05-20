//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the number of classes
#define NUM_CLASSES 10

// Define the number of features
#define NUM_FEATURES 784

// Define the number of training examples
#define NUM_TRAINING_EXAMPLES 60000

// Define the number of test examples
#define NUM_TEST_EXAMPLES 10000

// Define the learning rate
#define LEARNING_RATE 0.1

// Define the number of iterations
#define NUM_ITERATIONS 100

// Define the input file name
#define INPUT_FILE_NAME "mnist_train.csv"

// Define the output file name
#define OUTPUT_FILE_NAME "mnist_model.txt"

// Define the data structure for a training example
typedef struct {
  double features[NUM_FEATURES];
  int label;
} training_example;

// Define the data structure for a model
typedef struct {
  double weights[NUM_FEATURES];
  double bias;
} model;

// Load the training data from a file
training_example* load_training_data(char* filename, int* num_examples) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  // Read the number of examples
  fscanf(file, "%d", num_examples);

  // Allocate memory for the training data
  training_example* data = malloc(*num_examples * sizeof(training_example));

  // Read the training data
  for (int i = 0; i < *num_examples; i++) {
    // Read the features
    for (int j = 0; j < NUM_FEATURES; j++) {
      fscanf(file, "%lf,", &data[i].features[j]);
    }

    // Read the label
    fscanf(file, "%d\n", &data[i].label);
  }

  // Close the file
  fclose(file);

  // Return the training data
  return data;
}

// Save the model to a file
void save_model(model* model, char* filename) {
  // Open the file
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  // Write the weights
  for (int i = 0; i < NUM_FEATURES; i++) {
    fprintf(file, "%lf\n", model->weights[i]);
  }

  // Write the bias
  fprintf(file, "%lf\n", model->bias);

  // Close the file
  fclose(file);
}

// Train the model
void train_model(training_example* data, int num_examples, model* model) {
  // Initialize the weights and bias
  for (int i = 0; i < NUM_FEATURES; i++) {
    model->weights[i] = 0.0;
  }
  model->bias = 0.0;

  // Train the model for a number of iterations
  for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
    // Loop through the training data
    for (int i = 0; i < num_examples; i++) {
      // Calculate the predicted label
      double predicted_label = 0.0;
      for (int j = 0; j < NUM_FEATURES; j++) {
        predicted_label += model->weights[j] * data[i].features[j];
      }
      predicted_label += model->bias;

      // Calculate the error
      double error = predicted_label - data[i].label;

      // Update the weights and bias
      for (int j = 0; j < NUM_FEATURES; j++) {
        model->weights[j] -= LEARNING_RATE * error * data[i].features[j];
      }
      model->bias -= LEARNING_RATE * error;
    }
  }
}

// Test the model
double test_model(training_example* data, int num_examples, model* model) {
  // Initialize the number of correct predictions
  int num_correct_predictions = 0;

  // Loop through the test data
  for (int i = 0; i < num_examples; i++) {
    // Calculate the predicted label
    double predicted_label = 0.0;
    for (int j = 0; j < NUM_FEATURES; j++) {
      predicted_label += model->weights[j] * data[i].features[j];
    }
    predicted_label += model->bias;

    // Check if the predicted label is correct
    if (predicted_label == data[i].label) {
      num_correct_predictions++;
    }
  }

  // Calculate the accuracy
  double accuracy = (double)num_correct_predictions / num_examples;

  // Return the accuracy
  return accuracy;
}

int main() {
  // Load the training data
  int num_training_examples;
  training_example* training_data = load_training_data(INPUT_FILE_NAME, &num_training_examples);

  // Train the model
  model model;
  train_model(training_data, num_training_examples, &model);

  // Save the model
  save_model(&model, OUTPUT_FILE_NAME);

  // Test the model
  int num_test_examples;
  training_example* test_data = load_training_data("mnist_test.csv", &num_test_examples);
  double accuracy = test_model(test_data, num_test_examples, &model);

  // Print the accuracy
  printf("Accuracy: %lf\n", accuracy);

  // Free the memory
  free(training_data);
  free(test_data);

  return 0;
}