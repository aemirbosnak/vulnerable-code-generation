//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Read the image file
  FILE* image_file = fopen("image.bmp", "rb");

  if (image_file == NULL) {
    printf("Cannot open image file.");
    return -1;
  }

  // Get image dimensions from header
  fseek(image_file, 0x12, SEEK_SET);
  int width = getc(image_file) + getc(image_file) * 256 + getc(image_file) * 256 * 256 + getc(image_file) * 256 * 256 * 256;
  int height = getc(image_file) + getc(image_file) * 256 + getc(image_file) * 256 * 256 + getc(image_file) * 256 * 256 * 256;

  // Allocate memory for the image data
  int* image_data = malloc(width * height * sizeof(int));

  // Read the image data
  fseek(image_file, 0x36, SEEK_SET);
  for (int i = 0; i < width * height; i++) {
    image_data[i] = getc(image_file);
  }

  // Close the image file
  fclose(image_file);

  // Convert the image to ASCII art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel = image_data[y * width + x];
      int intensity = round(pixel / 255.0 * 10);
      char* character = " ";

      switch (intensity) {
        case 0:
          character = " ";
          break;
        case 1:
          character = ".";
          break;
        case 2:
          character = ":";
          break;
        case 3:
          character = "-";
          break;
        case 4:
          character = "=";
          break;
        case 5:
          character = "+";
          break;
        case 6:
          character = "*";
          break;
        case 7:
          character = "#";
          break;
        case 8:
          character = "%";
          break;
        case 9:
          character = "@";
          break;
      }

      // Print the ASCII character
      printf("%s", character);
    }

    // Print a new line for the next row
    printf("\n");
  }

  // Free the memory used by the image data
  free(image_data);

  return 0;
}