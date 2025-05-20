//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIZE 512

typedef struct {
  unsigned char r, g, b;
} RGB;

void read_image(RGB input_image[IMAGE_SIZE][IMAGE_SIZE], char *input_file) {
  FILE *fp;
  int i, j;
  char buffer[IMAGE_SIZE];

  fp = fopen(input_file, "r");
  if (!fp) {
    printf("Unable to open file '%s'\n", input_file);
    exit(1);
  }

  fgets(buffer, IMAGE_SIZE, fp); /* P3 */
  fgets(buffer, IMAGE_SIZE, fp); /* image dimensions */

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      fscanf(fp, "%hhu%hhu%hhu", &input_image[i][j].r, &input_image[i][j].g, &input_image[i][j].b);
    }
  }

  fclose(fp);
}

void write_image(RGB output_image[IMAGE_SIZE][IMAGE_SIZE], char *output_file) {
  FILE *fp;
  int i, j;

  fp = fopen(output_file, "w");
  if (!fp) {
    printf("Unable to open file '%s'\n", output_file);
    exit(1);
  }

  fprintf(fp, "P3\n%d %d\n255\n", IMAGE_SIZE, IMAGE_SIZE);

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      fprintf(fp, "%d %d %d ", output_image[i][j].r, output_image[i][j].g, output_image[i][j].b);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

void flip_image_horizontally(RGB input_image[IMAGE_SIZE][IMAGE_SIZE], RGB output_image[IMAGE_SIZE][IMAGE_SIZE]) {
  int i, j;

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      output_image[i][j] = input_image[i][IMAGE_SIZE - j - 1];
    }
  }
}

void flip_image_vertically(RGB input_image[IMAGE_SIZE][IMAGE_SIZE], RGB output_image[IMAGE_SIZE][IMAGE_SIZE]) {
  int i, j;

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      output_image[i][j] = input_image[IMAGE_SIZE - i - 1][j];
    }
  }
}

void adjust_brightness(RGB input_image[IMAGE_SIZE][IMAGE_SIZE], RGB output_image[IMAGE_SIZE][IMAGE_SIZE], int brightness) {
  int i, j;
  double factor = (double)brightness / 255.0;

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      output_image[i][j].r = (unsigned char)floor(factor * input_image[i][j].r + 0.5);
      output_image[i][j].g = (unsigned char)floor(factor * input_image[i][j].g + 0.5);
      output_image[i][j].b = (unsigned char)floor(factor * input_image[i][j].b + 0.5);
    }
  }
}

void adjust_contrast(RGB input_image[IMAGE_SIZE][IMAGE_SIZE], RGB output_image[IMAGE_SIZE][IMAGE_SIZE], int contrast) {
  int i, j;
  double factor = (259.0 * (double)(contrast + 255.0)) / (255.0 * (259.0 - (double)contrast));

  for (i = 0; i < IMAGE_SIZE; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      output_image[i][j].r = (unsigned char)floor(factor * (double)(input_image[i][j].r - 128) + 128.0);
      output_image[i][j].g = (unsigned char)floor(factor * (double)(input_image[i][j].g - 128) + 128.0);
      output_image[i][j].b = (unsigned char)floor(factor * (double)(input_image[i][j].b - 128) + 128.0);
    }
  }
}

int main(int argc, char **argv) {
  RGB input_image[IMAGE_SIZE][IMAGE_SIZE];
  RGB output_image[IMAGE_SIZE][IMAGE_SIZE];
  char *input_file, *output_file;
  int brightness, contrast;
  int i, j;

  if (argc != 5) {
    printf("Usage: %s <input file> <output file> <brightness> <contrast>\n", argv[0]);
    exit(1);
  }

  input_file = argv[1];
  output_file = argv[2];
  brightness = atoi(argv[3]);
  contrast = atoi(argv[4]);

  read_image(input_image, input_file);

  /* Flip image horizontally */
  flip_image_horizontally(input_image, output_image);
  write_image(output_image, "result_flip_horizontal.ppm");

  /* Flip image vertically */
  flip_image_vertically(input_image, output_image);
  write_image(output_image, "result_flip_vertical.ppm");

  /* Adjust brightness */
  adjust_brightness(input_image, output_image, brightness);
  write_image(output_image, "result_brightness.ppm");

  /* Adjust contrast */
  adjust_contrast(input_image, output_image, contrast);
  write_image(output_image, "result_contrast.ppm");

  return 0;
}