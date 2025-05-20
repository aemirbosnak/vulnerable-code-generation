//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct {
  float *data;
  int width;
  int height;
  int channels;
} Image;

typedef struct {
  char *name;
  int label;
} Label;

typedef struct {
  Image *image;
  Label *label;
} Dataset;

Dataset *load_dataset(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    return NULL;
  }

  int num_images, num_labels;
  fscanf(fp, "%d %d\n", &num_images, &num_labels);

  Dataset *dataset = malloc(sizeof(Dataset));
  dataset->image = malloc(sizeof(Image) * num_images);
  dataset->label = malloc(sizeof(Label) * num_images);

  for (int i = 0; i < num_images; i++) {
    fscanf(fp, "%d %d %d", &dataset->image[i].width, &dataset->image[i].height,
           &dataset->image[i].channels);
    dataset->image[i].data = malloc(sizeof(float) * dataset->image[i].width *
                                   dataset->image[i].height *
                                   dataset->image[i].channels);
    for (int j = 0; j < dataset->image[i].width * dataset->image[i].height *
                         dataset->image[i].channels;
         j++) {
      fscanf(fp, "%f", &dataset->image[i].data[j]);
    }
    fscanf(fp, "%d", &dataset->label[i].label);
  }

  fclose(fp);

  return dataset;
}

void free_dataset(Dataset *dataset) {
  for (int i = 0; i < ARRAY_SIZE(dataset->image); i++) {
    free(dataset->image[i].data);
  }
  free(dataset->image);
  free(dataset->label);
  free(dataset);
}

int main() {
  Dataset *dataset = load_dataset("dataset.txt");

  for (int i = 0; i < ARRAY_SIZE(dataset->image); i++) {
    printf("Image %d: %dx%d %d channels\n", i, dataset->image[i].width,
           dataset->image[i].height, dataset->image[i].channels);
    printf("Label: %s\n", dataset->label[i].name);
  }

  free_dataset(dataset);

  return 0;
}