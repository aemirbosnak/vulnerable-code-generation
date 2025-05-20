//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PIXEL_VALUE 255

typedef struct { 
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

typedef struct {
  int width;
  int height;
  Pixel *pixels;
} Image;

Image* createImage(int width, int height) {
  Image *img = (Image*)malloc(sizeof(Image));
  img->width = width;
  img->height = height;
  img->pixels = (Pixel*)malloc(width * height * sizeof(Pixel));
  return img;
}

void freeImage(Image *img) {
  free(img->pixels);
  free(img);
}

void loadImage(Image *img, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }
  char magic[2];
  fscanf(file, "%2s\n", magic);
  if (strcmp(magic, "P6") != 0) {
    printf("Error: file is not a P6 PPM file\n");
    exit(1);
  }
  fscanf(file, "%d %d\n", &img->width, &img->height);
  int max_value;
  fscanf(file, "%d\n", &max_value);
  if (max_value > MAX_PIXEL_VALUE) {
    printf("Error: file has pixel values above 255\n");
    exit(1);
  }
  img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
  fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
  fclose(file);
}

void saveImage(Image *img, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VALUE);
  fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
  fclose(file);
}

void invertColors(Image *img) {
  int i, j;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      Pixel *p = &img->pixels[i * img->width + j];
      p->red = MAX_PIXEL_VALUE - p->red;
      p->green = MAX_PIXEL_VALUE - p->green;
      p->blue = MAX_PIXEL_VALUE - p->blue;
    }
  }
}

int main() {
  char filename[MAX_FILENAME_LENGTH];
  printf("Enter filename: ");
  scanf("%s", filename);
  Image *img = createImage(0, 0);
  loadImage(img, filename);
  invertColors(img);
  char output_filename[MAX_FILENAME_LENGTH];
  printf("Enter output filename: ");
  scanf("%s", output_filename);
  saveImage(img, output_filename);
  freeImage(img);
  return 0;
}