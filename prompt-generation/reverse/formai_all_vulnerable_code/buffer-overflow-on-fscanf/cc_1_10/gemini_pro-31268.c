//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <omp.h>

#define NUM_THREADS 8
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define NUM_CLASSES 10

typedef struct {
  float data[IMAGE_WIDTH][IMAGE_HEIGHT];
  int label;
} Image;

typedef struct {
  float weights[NUM_CLASSES][IMAGE_WIDTH * IMAGE_HEIGHT];
  float biases[NUM_CLASSES];
} Model;

Image* load_image(char* filename) {
  Image* image = malloc(sizeof(Image));
  FILE* file = fopen(filename, "r");
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      fscanf(file, "%f", &image->data[i][j]);
    }
  }
  fscanf(file, "%d", &image->label);
  fclose(file);
  return image;
}

Model* load_model(char* filename) {
  Model* model = malloc(sizeof(Model));
  FILE* file = fopen(filename, "r");
  for (int i = 0; i < NUM_CLASSES; i++) {
    for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      fscanf(file, "%f", &model->weights[i][j]);
    }
    fscanf(file, "%f", &model->biases[i]);
  }
  fclose(file);
  return model;
}

void predict(Image* image, Model* model) {
  float scores[NUM_CLASSES];
  for (int i = 0; i < NUM_CLASSES; i++) {
    scores[i] = 0;
    for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
      scores[i] += model->weights[i][j] * image->data[j % IMAGE_WIDTH][j / IMAGE_WIDTH];
    }
    scores[i] += model->biases[i];
  }
  int prediction = 0;
  float max_score = -INFINITY;
  for (int i = 0; i < NUM_CLASSES; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      prediction = i;
    }
  }
  printf("Predicted class: %d\n", prediction);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <image_file> <model_file>\n", argv[0]);
    return 1;
  }
  Image* image = load_image(argv[1]);
  Model* model = load_model(argv[2]);
  predict(image, model);
  free(image);
  free(model);
  return 0;
}