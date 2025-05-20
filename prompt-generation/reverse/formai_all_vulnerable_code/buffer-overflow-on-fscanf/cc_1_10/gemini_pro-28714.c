//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of classes
#define NUM_CLASSES 10

// Define the size of the input image
#define IMAGE_SIZE 28

// Define the number of hidden units
#define NUM_HIDDEN 100

// Define the learning rate
#define LEARNING_RATE 0.01

// Load the training data
float** load_training_data(int* num_images) {
  FILE* file = fopen("training_data.txt", "r");
  fscanf(file, "%d", num_images);
  float** data = malloc(*num_images * sizeof(float*));
  for (int i = 0; i < *num_images; i++) {
    data[i] = malloc(IMAGE_SIZE * sizeof(float));
    for (int j = 0; j < IMAGE_SIZE; j++) {
      fscanf(file, "%f", &data[i][j]);
    }
  }
  fclose(file);
  return data;
}

// Load the training labels
int* load_training_labels(int* num_images) {
  FILE* file = fopen("training_labels.txt", "r");
  fscanf(file, "%d", num_images);
  int* labels = malloc(*num_images * sizeof(int));
  for (int i = 0; i < *num_images; i++) {
    fscanf(file, "%d", &labels[i]);
  }
  fclose(file);
  return labels;
}

// Initialize the weights
void initialize_weights(float** weights, int num_inputs, int num_outputs) {
  for (int i = 0; i < num_inputs; i++) {
    for (int j = 0; j < num_outputs; j++) {
      weights[i][j] = (float)rand() / (float)RAND_MAX;
    }
  }
}

// Forward pass
void forward_pass(float** weights, float* inputs, float* outputs, int num_inputs, int num_outputs) {
  for (int i = 0; i < num_outputs; i++) {
    outputs[i] = 0;
    for (int j = 0; j < num_inputs; j++) {
      outputs[i] += weights[j][i] * inputs[j];
    }
    outputs[i] = 1 / (1 + exp(-outputs[i]));
  }
}

// Backward pass
void backward_pass(float** weights, float* inputs, float* outputs, float* targets, int num_inputs, int num_outputs) {
  // Calculate the error
  float error = 0;
  for (int i = 0; i < num_outputs; i++) {
    error += 0.5 * pow(targets[i] - outputs[i], 2);
  }

  // Calculate the gradients
  float** gradients = malloc(num_inputs * sizeof(float*));
  for (int i = 0; i < num_inputs; i++) {
    gradients[i] = malloc(num_outputs * sizeof(float));
    for (int j = 0; j < num_outputs; j++) {
      gradients[i][j] = (outputs[j] - targets[j]) * outputs[j] * (1 - outputs[j]) * inputs[i];
    }
  }

  // Update the weights
  for (int i = 0; i < num_inputs; i++) {
    for (int j = 0; j < num_outputs; j++) {
      weights[i][j] -= LEARNING_RATE * gradients[i][j];
    }
  }

  // Free the gradients
  for (int i = 0; i < num_inputs; i++) {
    free(gradients[i]);
  }
  free(gradients);
}

// Train the model
void train_model(float** weights, float** training_data, int* training_labels, int num_images, int num_epochs) {
  for (int epoch = 0; epoch < num_epochs; epoch++) {
    for (int image = 0; image < num_images; image++) {
      // Forward pass
      float outputs[NUM_CLASSES];
      forward_pass(weights, training_data[image], outputs, IMAGE_SIZE, NUM_CLASSES);

      // Backward pass
      float targets[NUM_CLASSES];
      for (int i = 0; i < NUM_CLASSES; i++) {
        targets[i] = 0;
      }
      targets[training_labels[image]] = 1;
      backward_pass(weights, training_data[image], outputs, targets, IMAGE_SIZE, NUM_CLASSES);
    }
  }
}

// Test the model
float test_model(float** weights, float** test_data, int* test_labels, int num_images) {
  int correct = 0;
  for (int image = 0; image < num_images; image++) {
    // Forward pass
    float outputs[NUM_CLASSES];
    forward_pass(weights, test_data[image], outputs, IMAGE_SIZE, NUM_CLASSES);

    // Get the predicted class
    int predicted_class = 0;
    float max_output = -1;
    for (int i = 0; i < NUM_CLASSES; i++) {
      if (outputs[i] > max_output) {
        predicted_class = i;
        max_output = outputs[i];
      }
    }

    // Check if the prediction is correct
    if (predicted_class == test_labels[image]) {
      correct++;
    }
  }
  return (float)correct / num_images;
}

int main() {
  // Load the training data
  int num_images;
  float** training_data = load_training_data(&num_images);

  // Load the training labels
  int* training_labels = load_training_labels(&num_images);

  // Initialize the weights
  float** weights = malloc(IMAGE_SIZE * sizeof(float*));
  for (int i = 0; i < IMAGE_SIZE; i++) {
    weights[i] = malloc(NUM_CLASSES * sizeof(float));
  }
  initialize_weights(weights, IMAGE_SIZE, NUM_CLASSES);

  // Train the model
  train_model(weights, training_data, training_labels, num_images, 10);

  // Load the test data
  float** test_data = load_training_data(&num_images);

  // Load the test labels
  int* test_labels = load_training_labels(&num_images);

  // Test the model
  float accuracy = test_model(weights, test_data, test_labels, num_images);

  // Print the accuracy
  printf("Accuracy: %f\n", accuracy);

  // Free the memory
  for (int i = 0; i < IMAGE_SIZE; i++) {
    free(weights[i]);
  }
  free(weights);
  for (int i = 0; i < num_images; i++) {
    free(training_data[i]);
    free(test_data[i]);
  }
  free(training_data);
  free(test_data);
  free(training_labels);
  free(test_labels);

  return 0;
}