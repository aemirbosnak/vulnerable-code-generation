//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CLASS 10

typedef struct ImageData {
  int label;
  char **pixels;
  int width;
  int height;
} ImageData;

ImageData **loadData(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char **pixels = (char **)malloc(1024);
  for (int i = 0; i < 1024; i++) {
    pixels[i] = (char *)malloc(256);
  }

  int width = 0;
  int height = 0;
  fscanf(fp, "Width: %d, Height: %d\n", &width, &height);

  ImageData *image = (ImageData *)malloc(sizeof(ImageData));
  image->label = 0;
  image->pixels = pixels;
  image->width = width;
  image->height = height;

  fclose(fp);
  return image;
}

int classifyImage(ImageData *image) {
  int features[MAX_CLASS] = {0};

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      int pixelValue = image->pixels[i][j];
      features[pixelValue]++;
    }
  }

  int maxScore = 0;
  for (int i = 0; i < MAX_CLASS; i++) {
    if (features[i] > maxScore) {
      maxScore = features[i];
    }
  }

  return maxScore;
}

int main() {
  ImageData *image = loadData("image.txt");
  int label = classifyImage(image);

  printf("Label: %d\n", label);

  return 0;
}