//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
  // Get the message to be hidden
  char message[100];
  printf("Enter the message to be hidden: ");
  fgets(message, 100, stdin);

  // Get the image file
  char image_file[100];
  printf("Enter the name of the image file: ");
  fgets(image_file, 100, stdin);

  // Load the image
  FILE *image = fopen(image_file, "rb");
  if (image == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fscanf(image, "%d %d", &width, &height);

  // Allocate memory for the image pixels
  int *pixels = (int *)malloc(width * height * sizeof(int));
  if (pixels == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Load the image pixels
  for (int i = 0; i < width * height; i++) {
    fscanf(image, "%d", &pixels[i]);
  }

  // Hide the message in the pixels
  int message_length = strlen(message);
  int message_index = 0;
  for (int i = 0; i < width * height; i++) {
    if (message_index >= message_length) {
      break;
    }
    pixels[i] ^= message[message_index];
    message_index++;
  }

  // Save the modified image
  char output_file[100];
  printf("Enter the name of the output file: ");
  fgets(output_file, 100, stdin);
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  fprintf(output, "%d %d\n", width, height);
  for (int i = 0; i < width * height; i++) {
    fprintf(output, "%d ", pixels[i]);
  }
  fclose(output);

  // Clean up
  free(pixels);
  fclose(image);

  return 0;
}