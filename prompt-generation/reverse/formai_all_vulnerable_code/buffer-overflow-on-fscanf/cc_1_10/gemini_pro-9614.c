//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH  28
#define IMAGE_HEIGHT 28

// Define the number of classes
#define NUM_CLASSES 10

// Define the input image
unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT];

// Define the weights and biases for the neural network
float weights[NUM_CLASSES][IMAGE_WIDTH * IMAGE_HEIGHT];
float biases[NUM_CLASSES];

// Define the activation function
float activation(float x) {
  return 1.0 / (1.0 + exp(-x));
}

// Define the forward pass function
float forward_pass(float *input) {
  // Compute the weighted sum of the input and weights
  float weighted_sum = 0.0;
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      weighted_sum += input[j] * weights[i][j];
    }
    weighted_sum += biases[i];
  }

  // Apply the activation function to the weighted sum
  return activation(weighted_sum);
}

// Define the main function
int main() {
  // Load the input image
  FILE *image_file = fopen("image.txt", "r");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      fscanf(image_file, "%d", &image[i][j]);
    }
  }
  fclose(image_file);

  // Load the weights and biases
  FILE *weights_file = fopen("weights.txt", "r");
  if (weights_file == NULL) {
    fprintf(stderr, "Error opening weights file\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      fscanf(weights_file, "%f", &weights[i][j]);
    }
    fscanf(weights_file, "%f", &biases[i]);
  }
  fclose(weights_file);

  // Reshape the input image into a 1D array
  float input[IMAGE_WIDTH * IMAGE_HEIGHT];
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      input[i * IMAGE_WIDTH + j] = (float)image[i][j] / 255.0;
    }
  }

  // Perform the forward pass
  float probabilities[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    probabilities[i] = forward_pass(input);
  }

  // Find the class with the highest probability
  int predicted_class = 0;
  float max_probability = 0.0;
  for (int i = 0; i < NUM_CLASSES; i++) {
    if (probabilities[i] > max_probability) {
      max_probability = probabilities[i];
      predicted_class = i;
    }
  }

  // Print the predicted class
  printf("Predicted class: %d\n", predicted_class);

  return EXIT_SUCCESS;
}