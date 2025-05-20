//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 28*28
#define BATCH_SIZE 16

// The weights and biases are stored in a single array.
// The first 784 values are the weights for the first layer,
// the next 784 values are the weights for the second layer,
// and so on.
// The last 10 values are the biases for the output layer.
float weights[784*10+10];

// Load the weights and biases from a file.
void load_weights(const char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    perror(filename);
    exit(1);
  }
  fread(weights, sizeof(float), 784*10+10, f);
  fclose(f);
}

// Classify a single image.
int classify_image(const uint8_t *image) {
  // Compute the activations for the first layer.
  float activations[10];
  for (int i = 0; i < 10; i++) {
    activations[i] = 0;
    for (int j = 0; j < IMAGE_SIZE; j++) {
      activations[i] += image[j] * weights[i*IMAGE_SIZE+j];
    }
    activations[i] += weights[784*10+i];
  }

  // Apply the ReLU activation function.
  for (int i = 0; i < 10; i++) {
    if (activations[i] < 0) {
      activations[i] = 0;
    }
  }

  // Compute the activations for the output layer.
  float output[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    output[i] = 0;
    for (int j = 0; j < 10; j++) {
      output[i] += activations[j] * weights[784*10+10+i*10+j];
    }
  }

  // Find the class with the highest activation.
  int class = -1;
  float max_activation = -1;
  for (int i = 0; i < NUM_CLASSES; i++) {
    if (output[i] > max_activation) {
      max_activation = output[i];
      class = i;
    }
  }

  return class;
}

// Classify a batch of images.
void classify_batch(const uint8_t *images, int *labels) {
  for (int i = 0; i < BATCH_SIZE; i++) {
    labels[i] = classify_image(&images[i*IMAGE_SIZE]);
  }
}

// Evaluate the model on a dataset.
float evaluate_model(const uint8_t *images, const int *labels, int num_images) {
  int correct = 0;
  for (int i = 0; i < num_images; i++) {
    int predicted_label = classify_image(&images[i*IMAGE_SIZE]);
    if (predicted_label == labels[i]) {
      correct++;
    }
  }
  return (float)correct / num_images;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <weights file> <test data file>\n", argv[0]);
    exit(1);
  }

  // Load the weights and biases.
  load_weights(argv[1]);

  // Load the test data.
  FILE *f = fopen(argv[2], "rb");
  if (!f) {
    perror(argv[2]);
    exit(1);
  }

  uint8_t images[10000*IMAGE_SIZE];
  int labels[10000];

  fread(images, sizeof(uint8_t), 10000*IMAGE_SIZE, f);
  fread(labels, sizeof(int), 10000, f);

  fclose(f);
  
  // Evaluate the model on the test data.
  float accuracy = evaluate_model(images, labels, 10000);

  printf("Accuracy: %.2f%%\n", accuracy*100);

  return 0;
}