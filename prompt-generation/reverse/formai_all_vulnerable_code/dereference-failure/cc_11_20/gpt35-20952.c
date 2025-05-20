//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  // Open input file
  FILE *input = fopen("input.ppm", "rb");
  if (!input) {
    perror("Error opening input file");
    return 1;
  }

  // Read magic number
  char magic[3];
  if (fread(magic, 1, 2, input) != 2) {
    perror("Error reading magic number");
    return 1;
  }
  magic[2] = '\0';

  // Read image dimensions
  int width, height, maxval;
  if (fscanf(input, "%d %d\n%d\n", &width, &height, &maxval) != 3) {
    perror("Error reading image header");
    return 1;
  }

  // Allocate memory for image data
  unsigned char *data = malloc(width * height * 3);
  if (!data) {
    perror("Error allocating memory");
    return 1;
  }

  // Read image data
  if (fread(data, 1, width * height * 3, input) != width * height * 3) {
    perror("Error reading image data");
    return 1;
  }

  // Close input file
  fclose(input);

  // Flip image horizontally
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      for (int c = 0; c < 3; c++) {
        unsigned char tmp = data[y * width * 3 + x * 3 + c];
        data[y * width * 3 + x * 3 + c] = data[y * width * 3 + (width - x - 1) * 3 + c];
        data[y * width * 3 + (width - x - 1) * 3 + c] = tmp;
      }
    }
  }

  // Adjust brightness and contrast
  float brightness = 0.5;
  float contrast = 1.5;
  for (int i = 0; i < width * height * 3; i++) {
    float value = data[i] / 255.0;
    value = (value - 0.5) * contrast + 0.5 + brightness;
    if (value < 0) value = 0;
    if (value > 1) value = 1;
    data[i] = (unsigned char)(value * 255 + 0.5);
  }

  // Write output file
  FILE *output = fopen("output.ppm", "wb");
  if (!output) {
    perror("Error opening output file");
    return 1;
  }
  fprintf(output, "P6\n%d %d\n%d\n", width, height, maxval);
  if (fwrite(data, 1, width * height * 3, output) != width * height * 3) {
    perror("Error writing image data");
    return 1;
  }
  fclose(output);

  // Free memory
  free(data);

  return 0;
}