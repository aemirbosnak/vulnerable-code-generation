//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>

  #define MAX_HEIGHT 256
  #define MAX_WIDTH 256
  #define MAX_ASCII_CHARS 95

  int main(int argc, char *argv[]) {
    // Check if the input file name is provided
    if (argc < 2) {
      printf("Usage: %s <input_image_file>\n", argv[0]);
      return 1;
    }

    // Load the input image
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      printf("Error: Unable to open input file %s\n", argv[1]);
      return 1;
    }

    // Read the input image dimensions
    int width = 0, height = 0;
    fscanf(input_file, "%d %d", &width, &height);

    // Check if the image dimensions are valid
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
      printf("Error: Image dimensions (%dx%d) are too large\n", width, height);
      return 1;
    }

    // Allocate memory for the input image data
    unsigned char *image_data = malloc(width * height * sizeof(unsigned char));
    if (image_data == NULL) {
      printf("Error: Unable to allocate memory for input image data\n");
      return 1;
    }

    // Read the input image data
    fread(image_data, sizeof(unsigned char), width * height, input_file);

    // Close the input file
    fclose(input_file);

    // Initialize the ASCII art string
    char *ascii_art = malloc((width * height * 2) + 1);
    if (ascii_art == NULL) {
      printf("Error: Unable to allocate memory for ASCII art string\n");
      return 1;
    }

    // Convert the input image data to ASCII art
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        // Get the pixel value at (i, j)
        unsigned char pixel_value = image_data[i * width + j];

        // Calculate the ASCII art character
        int ascii_char_index = (int)(((float)pixel_value / 255.0) * MAX_ASCII_CHARS);
        char ascii_char = (char)(ascii_char_index + 33);

        // Add the ASCII character to the string
        ascii_art[i * width * 2 + j] = ascii_char;
        ascii_art[i * width * 2 + j + 1] = '\n';
      }
    }

    // Print the ASCII art
    printf("%s\n", ascii_art);

    // Free the memory
    free(image_data);
    free(ascii_art);

    return 0;
  }