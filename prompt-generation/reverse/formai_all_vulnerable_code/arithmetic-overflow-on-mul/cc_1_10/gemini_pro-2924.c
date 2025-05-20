//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image struct
typedef struct {
  int width;
  int height;
  int channels;
  unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error: could not open file '%s'\n", filename);
    return NULL;
  }

  // Read the header
  unsigned char header[14];
  fread(header, 1, 14, fp);

  // Check if the file is a BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: not a BMP file\n");
    fclose(fp);
    return NULL;
  }

  // Read the image dimensions
  int width = *(int *)(header + 18);
  int height = *(int *)(header + 22);

  // Read the number of channels
  int channels = *(int *)(header + 28) / 8;

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * channels);

  // Read the image data
  fread(data, 1, width * height * channels, fp);

  // Close the file
  fclose(fp);

  // Create the image struct
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->channels = channels;
  image->data = data;

  return image;
}

// Free the memory allocated for an image
void free_image(Image *image) {
  free(image->data);
  free(image);
}

// Get the pixel at the specified coordinates
unsigned char *get_pixel(Image *image, int x, int y) {
  return &image->data[(x + y * image->width) * image->channels];
}

// Set the pixel at the specified coordinates
void set_pixel(Image *image, int x, int y, unsigned char *color) {
  memcpy(get_pixel(image, x, y), color, image->channels);
}

// Invert the colors in an image
void invert_colors(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      unsigned char *pixel = get_pixel(image, x, y);
      for (int i = 0; i < image->channels; i++) {
        pixel[i] = 255 - pixel[i];
      }
    }
  }
}

// Grayscale an image
void grayscale(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      unsigned char *pixel = get_pixel(image, x, y);
      unsigned char gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
      for (int i = 0; i < image->channels; i++) {
        pixel[i] = gray;
      }
    }
  }
}

// Save an image to a file
void save_image(Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Error: could not open file '%s'\n", filename);
    return;
  }

  // Write the header
  unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
  *(int *)(header + 2) = image->width * image->height * image->channels + 14;
  *(int *)(header + 18) = image->width;
  *(int *)(header + 22) = image->height;
  *(int *)(header + 28) = image->channels * 8;
  fwrite(header, 1, 14, fp);

  // Write the image data
  fwrite(image->data, 1, image->width * image->height * image->channels, fp);

  // Close the file
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s input_image output_image\n", argv[0]);
    return 1;
  }

  // Load the input image
  Image *image = load_image(argv[1]);
  if (!image) {
    return 1;
  }

  // Invert the colors in the image
  invert_colors(image);

  // Grayscale the image
  grayscale(image);

  // Save the output image
  save_image(image, argv[2]);

  // Free the memory allocated for the image
  free_image(image);

  return 0;
}