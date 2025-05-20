//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

// Define the ASCII characters to use for each shade of gray
char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Function to convert an image to ASCII art
void img_to_ascii(char* filename) {
  FILE* fp = fopen(filename, "rb");

  // Read the header information from the image file
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, fp);

  // Extract the width and height of the image
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Calculate the padding of the image
  int padding = (4 - ((width * 3) % 4)) % 4;

  // Allocate memory for the image data
  unsigned char* img_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
  fread(img_data, sizeof(unsigned char), width * height * 3, fp);

  // Close the image file
  fclose(fp);

  // Create a string to hold the ASCII art
  char ascii_art[HEIGHT][WIDTH];

  // Loop through each pixel in the image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the index of the pixel in the image data array
      int i = (y * width + x) * 3;

      // Determine the shade of gray for the current pixel
      int gray = (int)(0.21 * img_data[i] + 0.72 * img_data[i+1] + 0.07 * img_data[i+2]);

      // Determine the index of the corresponding ASCII character
      int char_index = (int)(gray / 25.5);

      // Set the corresponding ASCII character in the string
      ascii_art[y][x] = ascii_chars[char_index];
    }
  }

  // Print the ASCII art to the console
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", ascii_art[y][x]);
    }
    printf("\n");
  }

  // Free the memory allocated for the image data
  free(img_data);
}

int main(int argc, char* argv[]) {
  // Check that an image filename was provided
  if (argc != 2) {
    printf("Usage: %s <image_filename>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  img_to_ascii(argv[1]);

  return 0;
}