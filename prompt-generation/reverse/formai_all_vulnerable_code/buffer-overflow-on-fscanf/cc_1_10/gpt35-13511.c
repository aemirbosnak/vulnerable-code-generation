//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum image size
#define MAX_SIZE 100

// Define the number of categories
#define NUM_CATEGORIES 5

// Define the number of features per image
#define NUM_FEATURES 10

// Define the number of training images
#define NUM_TRAINING_IMAGES 50

// Define the number of test images
#define NUM_TEST_IMAGES 10

// Define the number of epochs
#define NUM_EPOCHS 100

// Define the learning rate
#define LEARNING_RATE 0.01

// Define the sigmoid function
double sigmoid(double x) {
  return 1 / (1 + exp(-x));
}

// Define the derivative of the sigmoid function
double sigmoid_derivative(double x) {
  double sig = sigmoid(x);
  return sig * (1 - sig);
}

int main() {
  // Initialize the training data
  double training_data[NUM_TRAINING_IMAGES][NUM_FEATURES];
  int training_labels[NUM_TRAINING_IMAGES];

  // Initialize the test data
  double test_data[NUM_TEST_IMAGES][NUM_FEATURES];
  int test_labels[NUM_TEST_IMAGES];

  // Initialize the weights
  double weights[NUM_CATEGORIES][NUM_FEATURES];
  for (int i = 0; i < NUM_CATEGORIES; i++) {
    for (int j = 0; j < NUM_FEATURES; j++) {
      weights[i][j] = ((double) rand() / RAND_MAX) * 0.1 - 0.05;
    }
  }

  // Load the training data
  FILE *training_file = fopen("training_data.txt", "r");
  if (training_file == NULL) {
    printf("Error opening training data file\n");
    exit(1);
  }
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    for (int j = 0; j < NUM_FEATURES; j++) {
      fscanf(training_file, "%lf", &training_data[i][j]);
    }
    fscanf(training_file, "%d", &training_labels[i]);
  }
  fclose(training_file);

  // Load the test data
  FILE *test_file = fopen("test_data.txt", "r");
  if (test_file == NULL) {
    printf("Error opening test data file\n");
    exit(1);
  }
  for (int i = 0; i < NUM_TEST_IMAGES; i++) {
    for (int j = 0; j < NUM_FEATURES; j++) {
      fscanf(test_file, "%lf", &test_data[i][j]);
    }
    fscanf(test_file, "%d", &test_labels[i]);
  }
  fclose(test_file);

  // Train the model
  for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
    double total_loss = 0;
    for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
      // Compute the output
      double output[NUM_CATEGORIES];
      for (int j = 0; j < NUM_CATEGORIES; j++) {
        output[j] = 0;
        for (int k = 0; k < NUM_FEATURES; k++) {
          output[j] += weights[j][k] * training_data[i][k];
        }
        output[j] = sigmoid(output[j]);
      }

      // Compute the loss
      double loss = 0;
      for (int j = 0; j < NUM_CATEGORIES; j++) {
        double target = (j == training_labels[i]) ? 1 : 0;
        loss += pow(target - output[j], 2);
      }
      total_loss += loss;

      // Update the weights
      for (int j = 0; j < NUM_CATEGORIES; j++) {
        for (int k = 0; k < NUM_FEATURES; k++) {
          double gradient = 0;
          for (int l = 0; l < NUM_CATEGORIES; l++) {
            double target = (l == training_labels[i]) ? 1 : 0;
            double output_error = output[l] - target;
            gradient += output_error * sigmoid_derivative(output[j]) * training_data[i][k];
          }
          weights[j][k] -= LEARNING_RATE * gradient;
        }
      }
    }
    printf("Epoch %d: Loss = %lf\n", epoch, total_loss);
  }

  // Test the model
  int num_correct = 0;
  for (int i = 0; i < NUM_TEST_IMAGES; i++) {
    // Compute the output
    double output[NUM_CATEGORIES];
    for (int j = 0; j < NUM_CATEGORIES; j++) {
      output[j] = 0;
      for (int k = 0; k < NUM_FEATURES; k++) {
        output[j] += weights[j][k] * test_data[i][k];
      }
      output[j] = sigmoid(output[j]);
    }

    // Determine the predicted label
    int predicted_label = 0;
    for (int j = 0; j < NUM_CATEGORIES; j++) {
      if (output[j] > output[predicted_label]) {
        predicted_label = j;
      }
    }

    // Check if the prediction is correct
    if (predicted_label == test_labels[i]) {
      num_correct++;
    }
  }

  // Print the accuracy
  printf("Accuracy = %lf\n", (double) num_correct / NUM_TEST_IMAGES);

  return 0;
}