//FormAI DATASET v1.0 Category: Image Classification system ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGES 1000
#define MAX_LABELS 10
#define IMAGE_HEIGHT 28
#define IMAGE_WIDTH 28

typedef struct Image {
  int label;
  float pixels[IMAGE_HEIGHT][IMAGE_WIDTH];
} Image;

Image images[MAX_IMAGES];
float weights[MAX_LABELS][IMAGE_HEIGHT][IMAGE_WIDTH] = {0};

int main() {
  int num_images = 0;
  char filename[100];
  printf("Enter filename of training data:\n");
  scanf("%s", filename);

  FILE* file_ptr = fopen(filename, "r");
  if (!file_ptr) {
    printf("Error: failed to open file\n");
    exit(1);
  }

  // Read in images from file
  while (fscanf(file_ptr, "%d", &images[num_images].label) == 1) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
      for (int j = 0; j < IMAGE_WIDTH; j++) {
        fscanf(file_ptr, "%f", &(images[num_images].pixels[i][j]));
      }
    }
    num_images++;
    if (num_images >= MAX_IMAGES) {
      break; // Maximum number of images exceeded
    }
  }

  // Train the model
  for (int i = 0; i < num_images; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      for (int k = 0; k < IMAGE_WIDTH; k++) {
        int label = images[i].label;
        weights[label][j][k] += images[i].pixels[j][k];
      }
    }
  }

  // Normalize the weights
  for (int i = 0; i < MAX_LABELS; i++) {
    float sum = 0;
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      for (int k = 0; k < IMAGE_WIDTH; k++) {
        sum += weights[i][j][k];
      }
    }
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      for (int k = 0; k < IMAGE_WIDTH; k++) {
        weights[i][j][k] /= sum;
      }
    }
  }

  // Test the model
  int num_correct = 0;
  printf("Enter filename of test data:\n");
  scanf("%s", filename);

  file_ptr = fopen(filename, "r");
  if (!file_ptr) {
    printf("Error: failed to open file\n");
    exit(1);
  }

  int label;
  while (fscanf(file_ptr, "%d", &label) == 1) {
    Image test_image;
    test_image.label = label;

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
      for (int j = 0; j < IMAGE_WIDTH; j++) {
        fscanf(file_ptr, "%f", &(test_image.pixels[i][j]));
      }
    }

    int predicted_label = -1;
    float max_prob = 0;
    for (int i = 0; i < MAX_LABELS; i++) {
      float prob = 1;
      for (int j = 0; j < IMAGE_HEIGHT; j++) {
        for (int k = 0; k < IMAGE_WIDTH; k++) {
          prob *= weights[i][j][k] * test_image.pixels[j][k];
        }
      }
      if (prob > max_prob) {
        max_prob = prob;
        predicted_label = i;
      }
    }

    if (test_image.label == predicted_label) {
      num_correct++;
    }
  }

  float accuracy = (float) num_correct / num_images;
  printf("Accuracy: %.2f\n", accuracy);

  return 0;
}