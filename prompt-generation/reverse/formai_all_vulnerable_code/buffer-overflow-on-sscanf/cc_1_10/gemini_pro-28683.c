//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 24

// Convert an image to ASCII art.
char *image_to_ascii(const unsigned char *image, int width, int height) {
  // Allocate memory for the ASCII art.
  char *ascii_art = malloc(ASCII_WIDTH * ASCII_HEIGHT);
  if (ascii_art == NULL) {
    return NULL;
  }

  // Clear the ASCII art.
  memset(ascii_art, ' ', ASCII_WIDTH * ASCII_HEIGHT);

  // Convert the image to ASCII art.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Get the pixel value.
      unsigned char pixel = image[y * width + x];

      // Convert the pixel value to an ASCII character.
      char character;
      if (pixel < 32) {
        character = '@';
      } else if (pixel < 64) {
        character = '%';
      } else if (pixel < 96) {
        character = '#';
      } else if (pixel < 128) {
        character = '+';
      } else if (pixel < 160) {
        character = ':';
      } else if (pixel < 192) {
        character = ',';
      } else if (pixel < 224) {
        character = '-';
      } else {
        character = ' ';
      }

      // Set the ASCII character in the ASCII art.
      ascii_art[y * ASCII_WIDTH + x] = character;
    }
  }

  // Return the ASCII art.
  return ascii_art;
}

// Print the ASCII art.
void print_ascii_art(const char *ascii_art) {
  for (int y = 0; y < ASCII_HEIGHT; y++) {
    for (int x = 0; x < ASCII_WIDTH; x++) {
      // Print the ASCII character.
      printf("%c", ascii_art[y * ASCII_WIDTH + x]);
    }

    // Go to the next line.
    printf("\n");
  }
}

// Free the ASCII art.
void free_ascii_art(char *ascii_art) {
  if (ascii_art != NULL) {
    free(ascii_art);
  }
}

// Main function.
int main(int argc, char *argv[]) {
  // Check if the user specified an image file.
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read the image file.
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  fseek(image_file, 0, SEEK_END);
  long file_size = ftell(image_file);
  rewind(image_file);

  unsigned char *image = malloc(file_size);
  if (image == NULL) {
    fprintf(stderr, "Error allocating memory for image.\n");
    fclose(image_file);
    return EXIT_FAILURE;
  }

  fread(image, 1, file_size, image_file);
  fclose(image_file);

  // Get the image width and height.
  int width, height;
  if (sscanf(argv[1], "P5 %d %d", &width, &height) != 2) {
    fprintf(stderr, "Error parsing image dimensions.\n");
    free(image);
    return EXIT_FAILURE;
  }

  // Convert the image to ASCII art.
  char *ascii_art = image_to_ascii(image, width, height);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error converting image to ASCII art.\n");
    free(image);
    return EXIT_FAILURE;
  }

  // Print the ASCII art.
  print_ascii_art(ascii_art);

  // Free the ASCII art and the image.
  free_ascii_art(ascii_art);
  free(image);

  return EXIT_SUCCESS;
}