//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ImageData {
  unsigned char* pixels;
  int width;
  int height;
} ImageData;

ImageData* load_image(char* filename) {
  // Read image file and allocate memory for image data
  ImageData* image = malloc(sizeof(ImageData));
  image->pixels = malloc(MAX_BUFFER_SIZE);
  image->width = 0;
  image->height = 0;

  // Open image file
  FILE* file = fopen(filename, "r");

  // Get image width and height
  fscanf(file, "%d %d", &image->width, &image->height);

  // Read image pixels
  fread(image->pixels, image->width * image->height * 3, 1, file);

  // Close image file
  fclose(file);

  return image;
}

void save_image(ImageData* image, char* filename) {
  // Open image file
  FILE* file = fopen(filename, "w");

  // Write image width and height
  fprintf(file, "%d %d", image->width, image->height);

  // Write image pixels
  fwrite(image->pixels, image->width * image->height * 3, 1, file);

  // Close image file
  fclose(file);
}

int main() {
  // Load image
  ImageData* image = load_image("image.jpg");

  // Modify image pixels
  image->pixels[0] = 255;

  // Save image
  save_image(image, "image_edited.jpg");

  // Free memory
  free(image->pixels);
  free(image);

  return 0;
}