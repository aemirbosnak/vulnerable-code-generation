//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the number of classes
#define NUM_CLASSES 10

// Define the size of the input image
#define IMAGE_SIZE 28

// Define the number of training images
#define NUM_TRAINING_IMAGES 60000

// Define the number of testing images
#define NUM_TESTING_IMAGES 10000

// Define the learning rate
#define LEARNING_RATE 0.001

// Define the number of epochs
#define NUM_EPOCHS 10

// Create a struct to represent an image
typedef struct {
  float data[IMAGE_SIZE][IMAGE_SIZE];
  int label;
} Image;

// Create a struct to represent a layer of neurons
typedef struct {
  float weights[IMAGE_SIZE][IMAGE_SIZE];
  float biases[IMAGE_SIZE];
  float outputs[IMAGE_SIZE];
} Layer;

// Create a struct to represent a neural network
typedef struct {
  Layer layers[NUM_CLASSES];
} NeuralNetwork;

// Load the training images from a file
Image* load_training_images(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  Image* images = (Image*)malloc(NUM_TRAINING_IMAGES * sizeof(Image));
  for (int i = 0; i < NUM_TRAINING_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      for (int k = 0; k < IMAGE_SIZE; k++) {
        fscanf(file, "%f", &images[i].data[j][k]);
      }
    }
    fscanf(file, "%d", &images[i].label);
  }

  fclose(file);

  return images;
}

// Load the testing images from a file
Image* load_testing_images(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  Image* images = (Image*)malloc(NUM_TESTING_IMAGES * sizeof(Image));
  for (int i = 0; i < NUM_TESTING_IMAGES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      for (int k = 0; k < IMAGE_SIZE; k++) {
        fscanf(file, "%f", &images[i].data[j][k]);
      }
    }
    fscanf(file, "%d", &images[i].label);
  }

  fclose(file);

  return images;
}

// Initialize the neural network
void initialize_neural_network(NeuralNetwork* network) {
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      for (int k = 0; k < IMAGE_SIZE; k++) {
        network->layers[i].weights[j][k] = (float)rand() / (float)RAND_MAX;
      }
    }
    for (int j = 0; j < IMAGE_SIZE; j++) {
      network->layers[i].biases[j] = (float)rand() / (float)RAND_MAX;
    }
  }
}

// Forward propagate the input image through the neural network
void forward_propagate(NeuralNetwork* network, Image* image) {
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      float sum = 0.0;
      for (int k = 0; k < IMAGE_SIZE; k++) {
        sum += image->data[j][k] * network->layers[i].weights[j][k];
      }
      sum += network->layers[i].biases[j];
      network->layers[i].outputs[j] = 1.0 / (1.0 + exp(-sum));
    }
  }
}

// Backpropagate the error through the neural network
void backpropagate(NeuralNetwork* network, Image* image, int label) {
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      float error = (float)label - network->layers[i].outputs[j];
      for (int k = 0; k < IMAGE_SIZE; k++) {
        network->layers[i].weights[j][k] -= LEARNING_RATE * error * image->data[j][k];
      }
      network->layers[i].biases[j] -= LEARNING_RATE * error;
    }
  }
}

// Train the neural network
void train_neural_network(NeuralNetwork* network, Image* training_images) {
  for (int i = 0; i < NUM_EPOCHS; i++) {
    for (int j = 0; j < NUM_TRAINING_IMAGES; j++) {
      forward_propagate(network, &training_images[j]);
      backpropagate(network, &training_images[j], training_images[j].label);
    }
  }
}

// Test the neural network
int test_neural_network(NeuralNetwork* network, Image* testing_images) {
  int correct = 0;
  for (int i = 0; i < NUM_TESTING_IMAGES; i++) {
    forward_propagate(network, &testing_images[i]);
    int predicted_label = 0;
    float max_output = 0.0;
    for (int j = 0; j < NUM_CLASSES; j++) {
      if (network->layers[j].outputs[0] > max_output) {
        max_output = network->layers[j].outputs[0];
        predicted_label = j;
      }
    }
    if (predicted_label == testing_images[i].label) {
      correct++;
    }
  }
  return correct;
}

// Main function
int main() {
  // Load the training images
  Image* training_images = load_training_images("train-images.csv");
  if (training_images == NULL) {
    printf("Error loading training images.\n");
    return 1;
  }

  // Load the testing images
  Image* testing_images = load_testing_images("test-images.csv");
  if (testing_images == NULL) {
    printf("Error loading testing images.\n");
    return 1;
  }

  // Initialize the neural network
  NeuralNetwork network;
  initialize_neural_network(&network);

  // Train the neural network
  train_neural_network(&network, training_images);

  // Test the neural network
  int correct = test_neural_network(&network, testing_images);

  // Print the accuracy
  printf("Accuracy: %f\n", (float)correct / (float)NUM_TESTING_IMAGES);

  // Free the memory
  free(training_images);
  free(testing_images);

  return 0;
}