//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>

#define MAX_PIXEL_VAL 255

int main(int argc, char** argv) {

  if (argc < 4) {
    printf("Usage: Image_Processing image.pgm new_image.pgm option\n");
    printf("Options:\n");
    printf("-f Flip the image\n");
    printf("-b Increase brightness by 50\n");
    printf("-c Increase contrast by 50\n");
    return 1;
  }

  char* image_filename = argv[1];
  char* new_image_filename = argv[2];
  char* option = argv[3];

  FILE *image_file, *new_image_file;
  unsigned char *image_data, *new_image_data;
  char p;
  int rows, cols, max_val;
  long i, j, pixel;
  int brightness, contrast;

  image_file = fopen(image_filename, "rb");
  new_image_file = fopen(new_image_filename, "wb");

  if (image_file == NULL || new_image_file == NULL) {
    printf("Error opening files\n");
    return 1;
  }

  fscanf(image_file, "%c\n", &p);

  if (p != 'P' && p != 'p') {
    printf("Error: Invalid image format\n");
    return 1;
  }

  char c = fgetc(image_file);

  if (c == '#') {
    while (c != '\n') {
      c = fgetc(image_file);
    }
  } else {
    ungetc(c, image_file);
  }

  fscanf(image_file, "%d %d %d\n", &cols, &rows, &max_val);

  image_data = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));
  new_image_data = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));

  if (p == 'P5') {
    fread(image_data, sizeof(unsigned char), rows * cols, image_file);
  } else if (p == 'P6') {
    for (i = 0; i < rows * cols; i++) {
      image_data[i] = fgetc(image_file);
      image_data[i] = fgetc(image_file);
      image_data[i] = fgetc(image_file);
    }
  } else {
    printf("Error: Invalid image type\n");
    return 1;
  }

  if (*option == 'f') {
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        pixel = i * cols + j;
        new_image_data[pixel] = image_data[(rows - i - 1) * cols + j];
      }
    }
  } else if (*option == 'b') {
    brightness = 50;
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        pixel = i * cols + j;
        new_image_data[pixel] = image_data[pixel] + brightness;
        if (new_image_data[pixel] > MAX_PIXEL_VAL) {
          new_image_data[pixel] = MAX_PIXEL_VAL;
        }
      }
    }
  } else if (*option == 'c') {
    contrast = 50;
    double factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        pixel = i * cols + j;
        new_image_data[pixel] = (unsigned char)(factor * (image_data[pixel] - 128) + 128);
        if (new_image_data[pixel] > MAX_PIXEL_VAL) {
          new_image_data[pixel] = MAX_PIXEL_VAL;
        } else if (new_image_data[pixel] < 0) {
          new_image_data[pixel] = 0;
        }
      }
    }
  } else {
    printf("Error: Invalid option\n");
    return 1;
  }

  fprintf(new_image_file, "%c%d %d\n%d\n", p, cols, rows, max_val);
  fwrite(new_image_data, sizeof(unsigned char), rows * cols, new_image_file);

  fclose(image_file);
  fclose(new_image_file);
  free(image_data);
  free(new_image_data);

  printf("Image processing complete\n");

  return 0;
}