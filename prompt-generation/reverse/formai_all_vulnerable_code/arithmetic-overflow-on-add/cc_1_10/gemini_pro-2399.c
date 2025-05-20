//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
  int width;
  int height;
  char *data;
} Image;

typedef struct {
  int num_classes;
  char **class_names;
  float *class_weights;
} Classifier;

Image load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  Image img;

  fread(&img.width, sizeof(int), 1, fp);
  fread(&img.height, sizeof(int), 1, fp);

  int size = img.width * img.height;
  img.data = malloc(size);
  fread(img.data, sizeof(char), size, fp);

  fclose(fp);

  return img;
}

Classifier load_classifier(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  Classifier cls;

  fread(&cls.num_classes, sizeof(int), 1, fp);

  cls.class_names = malloc(cls.num_classes * sizeof(char *));
  cls.class_weights = malloc(cls.num_classes * sizeof(float));

  for (int i = 0; i < cls.num_classes; i++) {
    int len;
    fread(&len, sizeof(int), 1, fp);
    cls.class_names[i] = malloc(len + 1);
    fread(cls.class_names[i], sizeof(char), len, fp);
    cls.class_names[i][len] = '\0';

    fread(&cls.class_weights[i], sizeof(float), 1, fp);
  }

  fclose(fp);

  return cls;
}

void classify_image(Image img, Classifier cls) {
  int size = img.width * img.height;
  float *scores = malloc(cls.num_classes * sizeof(float));

  for (int i = 0; i < cls.num_classes; i++) {
    scores[i] = 0.0f;
    for (int j = 0; j < size; j++) {
      scores[i] += img.data[j] * cls.class_weights[i];
    }
  }

  int max_idx = 0;
  float max_score = scores[0];
  for (int i = 1; i < cls.num_classes; i++) {
    if (scores[i] > max_score) {
      max_idx = i;
      max_score = scores[i];
    }
  }

  printf("Image category: %s\n", cls.class_names[max_idx]);
  printf("Confidence: %.2f%%\n", max_score * 100);

  free(scores);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <image_filename> <classifier_filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  Image img = load_image(argv[1]);
  Classifier cls = load_classifier(argv[2]);

  classify_image(img, cls);

  free(img.data);
  for (int i = 0; i < cls.num_classes; i++) {
    free(cls.class_names[i]);
  }
  free(cls.class_names);
  free(cls.class_weights);

  return EXIT_SUCCESS;
}