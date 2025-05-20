//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100

typedef struct {
  int class;
  double features[MAX_FEATURES];
} Image;

typedef struct {
  int num_classes;
  int num_features;
  double weights[MAX_CLASSES][MAX_FEATURES];
  double biases[MAX_CLASSES];
} Model;

Image load_image(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  Image image;
  fscanf(file, "%d", &image.class);
  for (int i = 0; i < MAX_FEATURES; i++) {
    fscanf(file, "%lf", &image.features[i]);
  }

  fclose(file);
  return image;
}

Model load_model(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  Model model;
  fscanf(file, "%d", &model.num_classes);
  fscanf(file, "%d", &model.num_features);
  for (int i = 0; i < model.num_classes; i++) {
    for (int j = 0; j < model.num_features; j++) {
      fscanf(file, "%lf", &model.weights[i][j]);
    }
  }
  for (int i = 0; i < model.num_classes; i++) {
    fscanf(file, "%lf", &model.biases[i]);
  }

  fclose(file);
  return model;
}

int predict(const Image *image, const Model *model) {
  double scores[MAX_CLASSES];
  for (int i = 0; i < model->num_classes; i++) {
    double score = model->biases[i];
    for (int j = 0; j < model->num_features; j++) {
      score += model->weights[i][j] * image->features[j];
    }
    scores[i] = score;
  }

  int max_index = 0;
  for (int i = 1; i < model->num_classes; i++) {
    if (scores[i] > scores[max_index]) {
      max_index = i;
    }
  }

  return max_index;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s image_file model_file\n", argv[0]);
    exit(1);
  }

  Image image = load_image(argv[1]);
  Model model = load_model(argv[2]);

  int prediction = predict(&image, &model);
  printf("Predicted class: %d\n", prediction);

  return 0;
}