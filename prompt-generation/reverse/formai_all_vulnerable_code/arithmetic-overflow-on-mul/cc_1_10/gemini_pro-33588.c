//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

void print_image(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      printf("%02x", image->data[y * image->width + x]);
    }
    printf("\n");
  }
}

void shift_image(Image *image, int dx, int dy) {
  unsigned char *new_data = malloc(image->width * image->height);

  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int new_x = (x + dx) % image->width;
      int new_y = (y + dy) % image->height;
      new_data[new_y * image->width + new_x] = image->data[y * image->width + x];
    }
  }

  free(image->data);
  image->data = new_data;
}

int main() {
  Image image;

  // Read an image from a file
  FILE *file = fopen("image.bmp", "rb");
  fread(&image.width, sizeof(int), 1, file);
  fread(&image.height, sizeof(int), 1, file);
  image.data = malloc(image.width * image.height);
  fread(image.data, 1, image.width * image.height, file);
  fclose(file);

  // Print the original image
  printf("Original image:\n");
  print_image(&image);

  // Shift the image
  int dx = 10;
  int dy = 20;
  shift_image(&image, dx, dy);

  // Print the shifted image
  printf("Shifted image:\n");
  print_image(&image);

  // Free the memory used by the image
  free(image.data);

  return 0;
}