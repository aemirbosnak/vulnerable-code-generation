//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INPUT_SIZE 1024
#define HIDDEN_SIZE 100

typedef struct {
  double inputs[INPUT_SIZE];
  int labels[10];
} Image;

typedef struct {
  double weights[HIDDEN_SIZE][INPUT_SIZE];
  double biases[HIDDEN_SIZE];
} HiddenLayer;

typedef struct {
  double weights[10][HIDDEN_SIZE];
  double biases[10];
} OutputLayer;

Image load_image(char *filename) {
  Image image;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  for (int i = 0; i < INPUT_SIZE; i++) {
    fscanf(fp, "%lf", &image.inputs[i]);
  }
  for (int i = 0; i < 10; i++) {
    fscanf(fp, "%d", &image.labels[i]);
  }
  fclose(fp);
  return image;
}

HiddenLayer create_hidden_layer(int hidden_size) {
  HiddenLayer layer;
  for (int i = 0; i < hidden_size; i++) {
    for (int j = 0; j < INPUT_SIZE; j++) {
      layer.weights[i][j] = (double)rand() / (double)RAND_MAX;
    }
    layer.biases[i] = (double)rand() / (double)RAND_MAX;
  }
  return layer;
}

OutputLayer create_output_layer(int output_size) {
  OutputLayer layer;
  for (int i = 0; i < output_size; i++) {
    for (int j = 0; j < HIDDEN_SIZE; j++) {
      layer.weights[i][j] = (double)rand() / (double)RAND_MAX;
    }
    layer.biases[i] = (double)rand() / (double)RAND_MAX;
  }
  return layer;
}

double dot_product(double *a, double *b, int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += a[i] * b[i];
  }
  return sum;
}

double sigmoid(double x) {
  return 1 / (1 + exp(-x));
}

void feed_forward(Image image, HiddenLayer hidden_layer, OutputLayer output_layer) {
  double hidden_activations[HIDDEN_SIZE];
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    hidden_activations[i] = sigmoid(dot_product(image.inputs, hidden_layer.weights[i], INPUT_SIZE) + hidden_layer.biases[i]);
  }
  double output_activations[10];
  for (int i = 0; i < 10; i++) {
    output_activations[i] = sigmoid(dot_product(hidden_activations, output_layer.weights[i], HIDDEN_SIZE) + output_layer.biases[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("%lf\n", output_activations[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <image_file>\n", argv[0]);
    exit(1);
  }

  Image image = load_image(argv[1]);
  HiddenLayer hidden_layer = create_hidden_layer(HIDDEN_SIZE);
  OutputLayer output_layer = create_output_layer(10);
  feed_forward(image, hidden_layer, output_layer);

  return 0;
}