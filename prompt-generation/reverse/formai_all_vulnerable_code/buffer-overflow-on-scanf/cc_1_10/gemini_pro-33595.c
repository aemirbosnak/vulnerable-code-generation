//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Get the image dimensions from the user.
  int width, height;
  printf("Enter the image width: ");
  scanf("%d", &width);
  printf("Enter the image height: ");
  scanf("%d", &height);

  // Allocate memory for the image data.
  float *data = malloc(width * height * sizeof(float));

  // Read the image data from the user.
  printf("Enter the image data: ");
  for (int i = 0; i < width * height; i++) {
    scanf("%f", &data[i]);
  }

  // Create a new image with the same dimensions.
  float *new_data = malloc(width * height * sizeof(float));

  // Apply a filter to the image.
  for (int i = 0; i < width * height; i++) {
    // Get the pixel coordinates.
    int x = i % width;
    int y = i / width;

    // Get the pixel value.
    float value = data[i];

    // Apply the filter.
    value = 0.5 * value + 0.25 * (data[i-1] + data[i+1]) + 0.125 * (data[i-width] + data[i+width]);

    // Set the new pixel value.
    new_data[i] = value;
  }

  // Write the new image to a file.
  FILE *fp = fopen("new_image.txt", "w");
  for (int i = 0; i < width * height; i++) {
    fprintf(fp, "%f\n", new_data[i]);
  }
  fclose(fp);

  // Free the memory.
  free(data);
  free(new_data);

  return 0;
}