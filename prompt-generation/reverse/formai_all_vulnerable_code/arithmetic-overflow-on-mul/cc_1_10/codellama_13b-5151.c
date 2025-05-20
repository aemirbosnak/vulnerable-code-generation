//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
  int width;
  int height;
  int channels;
  unsigned char* data;
} Image;

void read_image(Image* image, char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: unable to open file %s\n", filename);
    exit(1);
  }
  fread(&image->width, sizeof(int), 1, file);
  fread(&image->height, sizeof(int), 1, file);
  fread(&image->channels, sizeof(int), 1, file);
  image->data = malloc(image->width * image->height * image->channels);
  fread(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);
}

void write_image(Image* image, char* filename) {
  FILE* file = fopen(filename, "w");
  if (!file) {
    fprintf(stderr, "Error: unable to open file %s\n", filename);
    exit(1);
  }
  fwrite(&image->width, sizeof(int), 1, file);
  fwrite(&image->height, sizeof(int), 1, file);
  fwrite(&image->channels, sizeof(int), 1, file);
  fwrite(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);
}

void display_image(Image* image) {
  int i, j;
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      unsigned char* pixel = &image->data[i * image->width * image->channels + j * image->channels];
      if (image->channels == 1) {
        printf("%d ", *pixel);
      } else if (image->channels == 3) {
        printf("%d %d %d ", pixel[0], pixel[1], pixel[2]);
      } else {
        fprintf(stderr, "Error: unsupported image format\n");
        exit(1);
      }
    }
    printf("\n");
  }
}

void invert_image(Image* image) {
  int i, j;
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      unsigned char* pixel = &image->data[i * image->width * image->channels + j * image->channels];
      if (image->channels == 1) {
        *pixel = 255 - *pixel;
      } else if (image->channels == 3) {
        pixel[0] = 255 - pixel[0];
        pixel[1] = 255 - pixel[1];
        pixel[2] = 255 - pixel[2];
      } else {
        fprintf(stderr, "Error: unsupported image format\n");
        exit(1);
      }
    }
  }
}

void grayscale_image(Image* image) {
  int i, j;
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      unsigned char* pixel = &image->data[i * image->width * image->channels + j * image->channels];
      if (image->channels == 3) {
        int avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
        pixel[0] = avg;
        pixel[1] = avg;
        pixel[2] = avg;
      } else {
        fprintf(stderr, "Error: unsupported image format\n");
        exit(1);
      }
    }
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }
  Image image;
  read_image(&image, argv[1]);
  invert_image(&image);
  grayscale_image(&image);
  write_image(&image, argv[2]);
  free(image.data);
  return 0;
}