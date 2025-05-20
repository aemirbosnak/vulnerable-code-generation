//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint8_t r, g, b;
} pixel_t;

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input> <output> <operation>\n", argv[0]);
    fprintf(stderr, "Operation can be one of: flip, brightness, contrast\n");
    return 1;
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    perror("Could not open input file");
    return 1;
  }

  FILE *output = fopen(argv[2], "wb");
  if (!output) {
    perror("Could not open output file");
    return 1;
  }

  // Read the header from the input file
  uint16_t width, height;
  fread(&width, sizeof(width), 1, input);
  fread(&height, sizeof(height), 1, input);

  // Allocate memory for the image data
  pixel_t *image = malloc(width * height * sizeof(pixel_t));
  if (!image) {
    perror("Could not allocate memory for image");
    return 1;
  }

  // Read the image data from the input file
  fread(image, sizeof(pixel_t), width * height, input);

  // Flip the image
  if (!strcmp(argv[3], "flip")) {
    for (int y = 0; y < height / 2; y++) {
      for (int x = 0; x < width; x++) {
        pixel_t temp = image[y * width + x];
        image[y * width + x] = image[(height - y - 1) * width + x];
        image[(height - y - 1) * width + x] = temp;
      }
    }
  }

  // Change the brightness
  else if (!strcmp(argv[3], "brightness")) {
    int brightness = atoi(argv[4]);
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        image[y * width + x].r += brightness;
        image[y * width + x].g += brightness;
        image[y * width + x].b += brightness;
      }
    }
  }

  // Change the contrast
  else if (!strcmp(argv[3], "contrast")) {
    float contrast = atof(argv[4]);
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        image[y * width + x].r = (image[y * width + x].r - 128) * contrast + 128;
        image[y * width + x].g = (image[y * width + x].g - 128) * contrast + 128;
        image[y * width + x].b = (image[y * width + x].b - 128) * contrast + 128;
      }
    }
  }

  // Write the image data to the output file
  fwrite(&width, sizeof(width), 1, output);
  fwrite(&height, sizeof(height), 1, output);
  fwrite(image, sizeof(pixel_t), width * height, output);

  // Free the memory allocated for the image data
  free(image);

  // Close the input and output files
  fclose(input);
  fclose(output);

  return 0;
}