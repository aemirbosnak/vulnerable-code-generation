//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 28 * 28

typedef struct {
  float data[IMAGE_SIZE];
  int label;
} Image;

typedef struct {
  float weights[IMAGE_SIZE * NUM_CLASSES];
  float biases[NUM_CLASSES];
} Model;

void read_image(Image *image) {
  // Read the image data from a file or other source
  for (int i = 0; i < IMAGE_SIZE; i++) {
    scanf("%f", &image->data[i]);
  }

  // Read the image label
  scanf("%d", &image->label);
}

void read_model(Model *model) {
  // Read the model weights and biases from a file or other source
  for (int i = 0; i < IMAGE_SIZE * NUM_CLASSES; i++) {
    scanf("%f", &model->weights[i]);
  }

  for (int i = 0; i < NUM_CLASSES; i++) {
    scanf("%f", &model->biases[i]);
  }
}

float dot_product(float *a, float *b, int size) {
  float result = 0;
  for (int i = 0; i < size; i++) {
    result += a[i] * b[i];
  }
  return result;
}

int classify(Image *image, Model *model) {
  // Calculate the dot product between the image data and each set of weights
  float scores[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    scores[i] = dot_product(image->data, &model->weights[i * IMAGE_SIZE], IMAGE_SIZE);
  }

  // Add the biases to the scores
  for (int i = 0; i < NUM_CLASSES; i++) {
    scores[i] += model->biases[i];
  }

  // Return the index of the class with the highest score
  int max_index = 0;
  float max_score = -INFINITY;
  for (int i = 0; i < NUM_CLASSES; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      max_index = i;
    }
  }

  return max_index;
}

int main() {
  // Read the image
  Image image;
  read_image(&image);

  // Read the model
  Model model;
  read_model(&model);

  // Classify the image
  int predicted_label = classify(&image, &model);

  // Print the predicted label
  printf("Predicted label: %d\n", predicted_label);

  return 0;
}