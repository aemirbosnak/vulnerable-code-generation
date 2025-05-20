//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10

typedef struct Image {
  int width, height;
  char **pixels;
} Image;

Image *load_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  image->pixels = malloc(sizeof(char *) * image->height);
  for (int i = 0; i < image->height; i++) {
    image->pixels[i] = malloc(sizeof(char) * image->width);
  }

  FILE *file = fopen(filename, "r");
  fscanf(file, "%d %d", &image->width, &image->height);
  fread(image->pixels, image->width * image->height, 1, file);
  fclose(file);

  return image;
}

int classify_image(Image *image) {
  int features[MAX_CLASSES] = {0};
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int pixel_value = image->pixels[y][x];
      features[pixel_value]++;
    }
  }

  int class = 0;
  for (int i = 0; i < MAX_CLASSES; i++) {
    if (features[i] > features[class]) {
      class = i;
    }
  }

  return class;
}

int main() {
  Image *image = load_image("image.jpg");
  int class = classify_image(image);
  printf("Image class: %d\n", class);

  free(image->pixels);
  free(image);

  return 0;
}