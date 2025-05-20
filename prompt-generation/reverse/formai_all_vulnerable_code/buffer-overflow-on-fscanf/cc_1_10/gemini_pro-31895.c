//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

typedef struct {
  int width;
  int height;
  Pixel *data;
} Image;

Image *read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", filename);
    return NULL;
  }

  // Read the header information
  int width, height;
  if (fscanf(fp, "P3\n%d %d\n255\n", &width, &height) != 3) {
    fprintf(stderr, "Error reading image header from file: %s\n", filename);
    fclose(fp);
    return NULL;
  }

  // Allocate memory for the image data
  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    fclose(fp);
    return NULL;
  }

  image->width = width;
  image->height = height;
  image->data = malloc(width * height * sizeof(Pixel));
  if (image->data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    free(image);
    fclose(fp);
    return NULL;
  }

  // Read the image data
  for (int i = 0; i < width * height; i++) {
    if (fscanf(fp, "%hhu %hhu %hhu\n", &image->data[i].red, &image->data[i].green, &image->data[i].blue) != 3) {
      fprintf(stderr, "Error reading image data from file: %s\n", filename);
      free(image->data);
      free(image);
      fclose(fp);
      return NULL;
    }
  }

  fclose(fp);

  return image;
}

void write_image(const char *filename, const Image *image) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening image file for writing: %s\n", filename);
    return;
  }

  // Write the header information
  fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);

  // Write the image data
  for (int i = 0; i < image->width * image->height; i++) {
    fprintf(fp, "%hhu %hhu %hhu\n", image->data[i].red, image->data[i].green, image->data[i].blue);
  }

  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_image> <output_image> <watermark>\n", argv[0]);
    return 1;
  }

  // Read the input image
  Image *image = read_image(argv[1]);
  if (image == NULL) {
    return 1;
  }

  // Create a watermark image
  Image *watermark = read_image(argv[3]);
  if (watermark == NULL) {
    free(image);
    return 1;
  }

  // Embed the watermark in the input image
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      // Get the watermark pixel value
      unsigned char watermark_pixel = watermark->data[y * watermark->width + x].red;

      // Embed the watermark pixel value in the input image pixel value
      image->data[y * image->width + x].red = (image->data[y * image->width + x].red & 0xFE) | (watermark_pixel & 0x01);
      image->data[y * image->width + x].green = (image->data[y * image->width + x].green & 0xFE) | ((watermark_pixel >> 1) & 0x01);
      image->data[y * image->width + x].blue = (image->data[y * image->width + x].blue & 0xFE) | ((watermark_pixel >> 2) & 0x01);
    }
  }

  // Write the watermarked image to a file
  write_image(argv[2], image);

  // Free the memory allocated for the images
  free(image->data);
  free(image);
  free(watermark->data);
  free(watermark);

  return 0;
}