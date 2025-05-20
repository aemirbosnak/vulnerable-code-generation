//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random color values
int random_color() {
  return rand() % 256; // Generates a random color value between 0-255
}

int main() {
  srand(time(0)); // Seed the random function with current time

  printf("Welcome to the C Pixel Art Generator!\n\n");

  int width, height;
  printf("Enter the width of the image (in pixels): ");
  scanf("%d", &width);
  printf("Enter the height of the image (in pixels): ");
  scanf("%d", &height);

  // Create a dynamic 2D array to store the pixel values
  int **pixels = (int **) malloc(height * sizeof(int *));
  for (int i = 0; i < height; i++) {
    pixels[i] = (int *) malloc(width * sizeof(int));
  }

  printf("Generating image...\n");

  // Iterate through each pixel and assign a random color value
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int red = random_color();
      int green = random_color();
      int blue = random_color();
      pixels[row][col] = (red << 16) | (green << 8) | blue; // Combine RGB values into a single integer value
    }
  }

  // Write the pixel data into a PPM image file
  FILE *fp = fopen("output.ppm", "w");
  fprintf(fp, "P3\n%d %d\n255\n", width, height);
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      fprintf(fp, "%d %d %d ", (pixels[row][col] >> 16) & 0xFF, (pixels[row][col] >> 8) & 0xFF, pixels[row][col] & 0xFF);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  printf("Image generated successfully and saved as output.ppm!\n");

  // Free the dynamically allocated memory
  for (int i = 0; i < height; i++) {
    free(pixels[i]);
  }
  free(pixels);

  return 0;
}