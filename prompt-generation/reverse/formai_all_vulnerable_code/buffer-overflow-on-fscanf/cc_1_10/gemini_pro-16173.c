//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100
#define MAX_IMAGES 1000

typedef struct {
  int class;
  int features[MAX_FEATURES];
} Image;

int main() {
  // Load the images from a file.
  Image images[MAX_IMAGES];
  FILE *fp = fopen("images.txt", "r");
  for (int i = 0; i < MAX_IMAGES; i++) {
    fscanf(fp, "%d", &images[i].class);
    for (int j = 0; j < MAX_FEATURES; j++) {
      fscanf(fp, "%d", &images[i].features[j]);
    }
  }

  // Train a classifier.
  int classes[MAX_CLASSES];
  for (int i = 0; i < MAX_CLASSES; i++) {
    classes[i] = 0;
  }
  for (int i = 0; i < MAX_IMAGES; i++) {
    classes[images[i].class]++;
  }

  // Classify a new image.
  Image new_image;
  printf("Enter the features of the new image:\n");
  for (int i = 0; i < MAX_FEATURES; i++) {
    scanf("%d", &new_image.features[i]);
  }

  // Compute the distance from the new image to each class.
  int distances[MAX_CLASSES];
  for (int i = 0; i < MAX_CLASSES; i++) {
    distances[i] = 0;
    for (int j = 0; j < MAX_FEATURES; j++) {
      distances[i] += abs(new_image.features[j] - images[i].features[j]);
    }
  }

  // Find the class with the smallest distance.
  int min_distance = distances[0];
  int min_class = 0;
  for (int i = 1; i < MAX_CLASSES; i++) {
    if (distances[i] < min_distance) {
      min_distance = distances[i];
      min_class = i;
    }
  }

  // Print the classification.
  printf("The new image belongs to class %d.\n", min_class);

  return 0;
}