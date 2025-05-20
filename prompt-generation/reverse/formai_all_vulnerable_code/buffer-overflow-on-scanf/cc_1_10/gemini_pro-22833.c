//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
  // Introspection: Why are we even doing this?
  printf("Behold, the humble beginnings of an image to ASCII converter!\n");
  printf("I'm sure there are better ways to do this, but hey, it's a start.\n\n");

  // Get the image file name from the user.
  char filename[100];
  printf("Enter the image file name: ");
  scanf("%s", filename);

  // Open the image file.
  FILE *image = fopen(filename, "rb");
  if (image == NULL) {
    printf("Error opening the image file.\n");
    return 1;
  }

  // Get the image dimensions.
  int width, height;
  fread(&width, sizeof(int), 1, image);
  fread(&height, sizeof(int), 1, image);

  // Create a 2D array to store the pixel values.
  int pixels[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fread(&pixels[i][j], sizeof(int), 1, image);
    }
  }

  // Close the image file.
  fclose(image);

  // Convert the pixel values to ASCII characters.
  char ascii[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Calculate the brightness of the pixel.
      int brightness = pixels[i][j] & 0xFF;

      // Convert the brightness to an ASCII character.
      ascii[i][j] = " .:-=+*#%@";
      int index = (brightness * 10) / 255;
      ascii[i][j] = index;
    }
  }

  // Print the ASCII art to the console.
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii[i][j]);
    }
    printf("\n");
  }

  // Exit the program.
  return 0;
}