//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HEIGHT 512
#define WIDTH 512

typedef struct pixel {
  unsigned char r, g, b;
} pixel;

pixel image[HEIGHT][WIDTH];

void flip_horizontally() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH / 2; j++) {
      pixel temp = image[i][j];
      image[i][j] = image[i][WIDTH - j - 1];
      image[i][WIDTH - j - 1] = temp;
    }
  }
}

void flip_vertically() {
  for (int i = 0; i < HEIGHT / 2; i++) {
    for (int j = 0; j < WIDTH; j++) {
      pixel temp = image[i][j];
      image[i][j] = image[HEIGHT - i - 1][j];
      image[HEIGHT - i - 1][j] = temp;
    }
  }
}

void adjust_brightness(int brightness) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      image[i][j].r = fmax(0, fmin(255, image[i][j].r + brightness));
      image[i][j].g = fmax(0, fmin(255, image[i][j].g + brightness));
      image[i][j].b = fmax(0, fmin(255, image[i][j].b + brightness));
    }
  }
}

void adjust_contrast(float contrast) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      image[i][j].r = (image[i][j].r - 128) * contrast + 128;
      image[i][j].g = (image[i][j].g - 128) * contrast + 128;
      image[i][j].b = (image[i][j].b - 128) * contrast + 128;
    }
  }
}

void save_image(char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    printf("Error opening file %s\n", filename);
    return;
  }

  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      fputc(image[i][j].r, fp);
      fputc(image[i][j].g, fp);
      fputc(image[i][j].b, fp);
    }
  }

  fclose(fp);
}

int main() {
  // Load image from file
  FILE *fp = fopen("image.ppm", "rb");
  if (!fp) {
    printf("Error opening file image.ppm\n");
    return 1;
  }

  char magic_number[3];
  fscanf(fp, "%s", magic_number);
  if (strcmp(magic_number, "P6") != 0) {
    printf("Error: Invalid file format\n");
    fclose(fp);
    return 1;
  }

  int width, height;
  fscanf(fp, "%d %d", &width, &height);

  if (width != WIDTH || height != HEIGHT) {
    printf("Error: Image dimensions do not match\n");
    fclose(fp);
    return 1;
  }

  fscanf(fp, "%*s");  // Skip newline

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      fscanf(fp, "%hhu %hhu %hhu", &image[i][j].r, &image[i][j].g, &image[i][j].b);
    }
  }

  fclose(fp);

  // Flip image horizontally
  flip_horizontally();

  // Flip image vertically
  flip_vertically();

  // Adjust brightness
  adjust_brightness(50);

  // Adjust contrast
  adjust_contrast(1.5);

  // Save image to file
  save_image("output.ppm");

  return 0;
}