//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ubyte;

typedef struct {
  int width;
  int height;
  ubyte *data;
} Image;

Image *load_image(const char *filename) {
  FILE *file;
  Image *image;
  unsigned char header[54];

  file = fopen(filename, "rb");
  if (!file) {
    return NULL;
  }

  fread(header, sizeof(header), 1, file);
  if (header[0] != 'B' || header[1] != 'M') {
    fclose(file);
    return NULL;
  }

  image = malloc(sizeof(Image));
  if (!image) {
    fclose(file);
    return NULL;
  }

  image->width = *(int *)&header[18];
  image->height = *(int *)&header[22];
  image->data = malloc(image->width * image->height);
  if (!image->data) {
    free(image);
    fclose(file);
    return NULL;
  }

  fread(image->data, image->width * image->height, 1, file);
  fclose(file);

  return image;
}

void free_image(Image *image) {
  if (image) {
    free(image->data);
    free(image);
  }
}

char *convert_image_to_ascii_art(Image *image) {
  char *ascii_art;
  int i, j;
  int brightness;
  char *chars = "@%#*+=-:. ";

  ascii_art = malloc(image->width * image->height + 1);
  if (!ascii_art) {
    return NULL;
  }

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      brightness = (int)image->data[i * image->width + j];
      *ascii_art++ = chars[brightness / 32];
    }
    *ascii_art++ = '\n';
  }
  *ascii_art = '\0';

  return ascii_art;
}

int main(int argc, char **argv) {
  Image *image;
  char *ascii_art;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s image.bmp\n", argv[0]);
    return 1;
  }

  image = load_image(argv[1]);
  if (!image) {
    fprintf(stderr, "Error loading image: %s\n", argv[1]);
    return 1;
  }

  ascii_art = convert_image_to_ascii_art(image);
  if (!ascii_art) {
    fprintf(stderr, "Error converting image to ASCII art\n");
    free_image(image);
    return 1;
  }

  printf("%s", ascii_art);
  free(ascii_art);
  free_image(image);

  return 0;
}