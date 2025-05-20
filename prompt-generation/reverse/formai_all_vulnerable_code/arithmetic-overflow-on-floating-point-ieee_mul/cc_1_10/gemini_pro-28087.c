//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define IMG_WIDTH  28
#define IMG_HEIGHT 28
#define IMG_SIZE   (IMG_WIDTH * IMG_HEIGHT)

#define NUM_CLASSES 10

typedef struct {
  float data[IMG_SIZE];
  uint8_t label;
} Image;

typedef struct {
  float weights[NUM_CLASSES][IMG_SIZE];
  float biases[NUM_CLASSES];
} Model;

// Load an image from a file
Image* load_image(const char* filename) {
  FILE* file = fopen(filename, "rb");
  if (!file) {
    printf("Error opening file: %s\n", filename);
    return NULL;
  }

  Image* image = malloc(sizeof(Image));
  if (!image) {
    printf("Error allocating memory for image\n");
    fclose(file);
    return NULL;
  }

  fread(image->data, sizeof(float), IMG_SIZE, file);
  image->label = fgetc(file);
  fclose(file);

  return image;
}

// Load a model from a file
Model* load_model(const char* filename) {
  FILE* file = fopen(filename, "rb");
  if (!file) {
    printf("Error opening file: %s\n", filename);
    return NULL;
  }

  Model* model = malloc(sizeof(Model));
  if (!model) {
    printf("Error allocating memory for model\n");
    fclose(file);
    return NULL;
  }

  fread(model->weights, sizeof(float), NUM_CLASSES * IMG_SIZE, file);
  fread(model->biases, sizeof(float), NUM_CLASSES, file);
  fclose(file);

  return model;
}

// Classify an image using the model
int classify_image(Image* image, Model* model) {
  // Compute the dot product between the image data and the weights for each class
  float scores[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    scores[i] = 0.0f;
    for (int j = 0; j < IMG_SIZE; j++) {
      scores[i] += image->data[j] * model->weights[i][j];
    }
    scores[i] += model->biases[i];
  }

  // Find the class with the highest score
  int max_class = 0;
  float max_score = scores[0];
  for (int i = 1; i < NUM_CLASSES; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      max_class = i;
    }
  }

  return max_class;
}

// Main function
int main() {
  // Load the image and model
  Image* image = load_image("image.bin");
  if (!image) {
    printf("Error loading image\n");
    return -1;
  }

  Model* model = load_model("model.bin");
  if (!model) {
    printf("Error loading model\n");
    free(image);
    return -1;
  }

  // Classify the image
  int predicted_class = classify_image(image, model);

  // Print the predicted class
  printf("Predicted class: %d\n", predicted_class);

  // Free the memory allocated for the image and model
  free(image);
  free(model);

  return 0;
}