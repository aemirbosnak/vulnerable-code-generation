//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
  unsigned char r, g, b;
} pixel_t;

typedef struct {
  int width, height;
  pixel_t *pixels;
} image_t;

image_t *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return NULL;
  }

  image_t *image = malloc(sizeof(image_t));
  if (!image) {
    fprintf(stderr, "Error allocating memory for image\n");
    fclose(fp);
    return NULL;
  }

  fscanf(fp, "P6\n%d %d\n255\n", &image->width, &image->height);
  if (image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
    fprintf(stderr, "Error: Image is too large\n");
    fclose(fp);
    free(image);
    return NULL;
  }

  image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
  if (!image->pixels) {
    fprintf(stderr, "Error allocating memory for image pixels\n");
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
  fclose(fp);

  return image;
}

void free_image(image_t *image) {
  if (image) {
    free(image->pixels);
    free(image);
  }
}

char *ascii_art(image_t *image) {
  int char_width = 2;
  int char_height = 1;

  int total_width = image->width * char_width;
  int total_height = image->height * char_height;

  char *art = malloc(total_width * total_height + 1);
  if (!art) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    return NULL;
  }

  char *ptr = art;
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      pixel_t pixel = image->pixels[y * image->width + x];
      int luma = (pixel.r + pixel.g + pixel.b) / 3;
      char char_to_use = "#";
      if (luma < 64) {
        char_to_use = ' ';
      } else if (luma < 128) {
        char_to_use = ',';
      } else if (luma < 192) {
        char_to_use = 'o';
      }

      for (int i = 0; i < char_width; i++) {
        *ptr++ = char_to_use;
      }
    }
    for (int i = 0; i < char_height - 1; i++) {
      *ptr++ = '\n';
    }
  }

  *ptr = '\0';

  return art;
}

void print_ascii_art(char *art) {
  printf("%s", art);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  image_t *image = load_image(argv[1]);
  if (!image) {
    return 1;
  }

  char *art = ascii_art(image);
  if (!art) {
    free_image(image);
    return 1;
  }

  print_ascii_art(art);
  free(art);
  free_image(image);

  return 0;
}