//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 28 * 28

float sigmoid(float x) {
  return 1 / (1 + exp(-x));
}

int main() {
  // Load the image data.
  float image[IMAGE_SIZE];
  FILE *image_file = fopen("image.bin", "rb");
  fread(image, sizeof(float), IMAGE_SIZE, image_file);
  fclose(image_file);

  // Create the neural network.
  float weights[NUM_CLASSES][IMAGE_SIZE];
  float biases[NUM_CLASSES];

  // Load the neural network weights and biases.
  FILE *model_file = fopen("model.bin", "rb");
  fread(weights, sizeof(float), NUM_CLASSES * IMAGE_SIZE, model_file);
  fread(biases, sizeof(float), NUM_CLASSES, model_file);
  fclose(model_file);

  // Forward pass through the neural network.
  float activations[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    float sum = biases[i];
    for (int j = 0; j < IMAGE_SIZE; j++) {
      sum += weights[i][j] * image[j];
    }
    activations[i] = sigmoid(sum);
  }

  // Find the class with the highest activation.
  int predicted_class = 0;
  float max_activation = activations[0];
  for (int i = 1; i < NUM_CLASSES; i++) {
    if (activations[i] > max_activation) {
      predicted_class = i;
      max_activation = activations[i];
    }
  }

  // Print the predicted class.
  printf("Predicted class: %d\n", predicted_class);

  return 0;
}