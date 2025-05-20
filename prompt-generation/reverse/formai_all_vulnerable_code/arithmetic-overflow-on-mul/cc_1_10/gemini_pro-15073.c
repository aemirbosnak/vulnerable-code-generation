//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char *data;
  int width, height, channels;
} Image;

typedef struct {
  char *label;
  float probability;
} Classification;

Image read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error: Unable to open image file '%s'\n", filename);
    exit(1);
  }

  Image image;
  fread(&image.width, sizeof(int), 1, fp);
  fread(&image.height, sizeof(int), 1, fp);
  fread(&image.channels, sizeof(int), 1, fp);

  image.data = malloc(image.width * image.height * image.channels);
  fread(image.data, sizeof(unsigned char), image.width * image.height * image.channels, fp);
  fclose(fp);

  return image;
}

void free_image(Image image) {
  free(image.data);
}

Classification classify_image(Image image) {
  // Let's say this function uses a magical neural network to classify the image

  Classification classification;
  classification.label = "Curious Cat";
  classification.probability = 0.95;

  return classification;
}

void print_classification(Classification classification) {
  printf("Classification: %s (%f)\n", classification.label, classification.probability);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  Image image = read_image(argv[1]);

  Classification classification = classify_image(image);
  print_classification(classification);

  free_image(image);

  return 0;
}