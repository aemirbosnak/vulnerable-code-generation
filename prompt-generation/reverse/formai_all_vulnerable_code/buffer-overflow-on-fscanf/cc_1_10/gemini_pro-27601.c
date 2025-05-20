//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the image size
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

// Define the number of classes
#define NUM_CLASSES 10

// Define the input file name
#define INPUT_FILE "image.txt"

// Define the model file name
#define MODEL_FILE "model.bin"

// Define the output file name
#define OUTPUT_FILE "output.txt"

// Load the image from a file
int load_image(float *image, char *filename) {
  FILE *fp;
  int i, j;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  // Read the image data
  for (i = 0; i < IMAGE_HEIGHT; i++) {
    for (j = 0; j < IMAGE_WIDTH; j++) {
      fscanf(fp, "%f", &image[i * IMAGE_WIDTH + j]);
    }
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Load the model from a file
int load_model(float *model, char *filename) {
  FILE *fp;
  int i, j;

  // Open the file
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }

  // Read the model data
  for (i = 0; i < NUM_CLASSES; i++) {
    for (j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      fread(&model[i * IMAGE_WIDTH * IMAGE_HEIGHT + j], sizeof(float), 1, fp);
    }
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Classify the image
int classify_image(float *image, float *model, int *label) {
  int i, j;
  float max_score;

  // Calculate the scores for each class
  for (i = 0; i < NUM_CLASSES; i++) {
    float score = 0;
    for (j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      score += image[j] * model[i * IMAGE_WIDTH * IMAGE_HEIGHT + j];
    }
    if (i == 0) {
      max_score = score;
      *label = i;
    } else if (score > max_score) {
      max_score = score;
      *label = i;
    }
  }

  return 0;
}

// Save the output to a file
int save_output(int label, char *filename) {
  FILE *fp;

  // Open the file
  fp = fopen(filename, "w");
  if (fp == NULL) {
    return -1;
  }

  // Write the label to the file
  fprintf(fp, "%d\n", label);

  // Close the file
  fclose(fp);

  return 0;
}

// Main function
int main(int argc, char **argv) {
  // Allocate memory for the image
  float *image = (float *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(float));

  // Load the image from a file
  if (load_image(image, INPUT_FILE) != 0) {
    return -1;
  }

  // Allocate memory for the model
  float *model = (float *)malloc(NUM_CLASSES * IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(float));

  // Load the model from a file
  if (load_model(model, MODEL_FILE) != 0) {
    return -1;
  }

  // Classify the image
  int label;
  if (classify_image(image, model, &label) != 0) {
    return -1;
  }

  // Save the output to a file
  if (save_output(label, OUTPUT_FILE) != 0) {
    return -1;
  }

  // Free the memory
  free(image);
  free(model);

  return 0;
}