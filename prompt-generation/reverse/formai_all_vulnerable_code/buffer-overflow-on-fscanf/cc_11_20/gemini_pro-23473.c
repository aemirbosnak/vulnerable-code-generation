//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LABELS 1000
#define MAX_IMAGES 10000

typedef struct {
  char label[10];
  float data[784];
} Image;

Image images[MAX_IMAGES];
int num_images;

int main() {
  // Read the MNIST dataset from disk
  FILE *f = fopen("mnist.data", "r");
  if (f == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < MAX_IMAGES; i++) {
    if (fscanf(f, "%s", images[i].label) != 1) {
      perror("fscanf");
      return EXIT_FAILURE;
    }

    for (int j = 0; j < 784; j++) {
      if (fscanf(f, "%f", &images[i].data[j]) != 1) {
        perror("fscanf");
        return EXIT_FAILURE;
      }
    }
  }

  fclose(f);

  // Train a simple linear classifier
  float weights[784];
  for (int i = 0; i < 784; i++) {
    weights[i] = 0.0;
  }

  for (int i = 0; i < MAX_IMAGES; i++) {
    for (int j = 0; j < 784; j++) {
      weights[j] += images[i].data[j] * (images[i].label[0] - '0');
    }
  }

  // Classify a new image
  char label[10];
  float data[784];

  printf("Enter the label of the new image: ");
  scanf("%s", label);

  printf("Enter the data of the new image: ");
  for (int i = 0; i < 784; i++) {
    scanf("%f", &data[i]);
  }

  float score = 0.0;
  for (int i = 0; i < 784; i++) {
    score += data[i] * weights[i];
  }

  printf("The predicted label is: %d\n", (int) round(score));

  return EXIT_SUCCESS;
}