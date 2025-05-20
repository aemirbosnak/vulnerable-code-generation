//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHARS " .:-=+*#%@"

void convert_image_to_ascii(const char *image_path, const char *output_path) {
  // Open the image file
  FILE *image_file = fopen(image_path, "rb");
  if (!image_file) {
    fprintf(stderr, "Error: Unable to open image file.\n");
    return;
  }

  // Read the image header
  unsigned char header[54];
  fread(header, sizeof(char), 54, image_file);

  // Get the image width and height
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  unsigned char *image_data = malloc(width * height * 3);
  if (!image_data) {
    fprintf(stderr, "Error: Unable to allocate memory for image data.\n");
    fclose(image_file);
    return;
  }

  // Read the image data
  fread(image_data, sizeof(char), width * height * 3, image_file);

  // Close the image file
  fclose(image_file);

  // Open the output file
  FILE *output_file = fopen(output_path, "w");
  if (!output_file) {
    fprintf(stderr, "Error: Unable to open output file.\n");
    return;
  }

  // Iterate over each pixel in the image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Get the pixel value
      int pixel_value = image_data[(y * width + x) * 3];

      // Get the ASCII character for the pixel value
      int index = (pixel_value / 255.0) * (sizeof(ASCII_CHARS) - 1);
      char ascii_char = ASCII_CHARS[index];

      // Write the ASCII character to the output file
      fprintf(output_file, "%c", ascii_char);
    }
    fprintf(output_file, "\n");
  }

  // Close the output file
  fclose(output_file);

  // Free the image data
  free(image_data);
}

int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <image_path> <output_path>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  convert_image_to_ascii(argv[1], argv[2]);

  return 0;
}