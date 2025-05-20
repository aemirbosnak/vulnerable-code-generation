//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

void hide_message(pixel *image, char *message, int length) {
  int i, j, k;
  for (i = 0; i < length; i++) {
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 3; k++) {
        image[i * 8 * 3 + j * 3 + k].r = (image[i * 8 * 3 + j * 3 + k].r & 0xfe) | ((message[i] >> j) & 1);
        image[i * 8 * 3 + j * 3 + k].g = (image[i * 8 * 3 + j * 3 + k].g & 0xfe) | ((message[i] >> j) & 1);
        image[i * 8 * 3 + j * 3 + k].b = (image[i * 8 * 3 + j * 3 + k].b & 0xfe) | ((message[i] >> j) & 1);
      }
    }
  }
}

void extract_message(pixel *image, char *message, int length) {
  int i, j, k;
  for (i = 0; i < length; i++) {
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 3; k++) {
        message[i] |= (image[i * 8 * 3 + j * 3 + k].r & 1) << j;
        message[i] |= (image[i * 8 * 3 + j * 3 + k].g & 1) << j;
        message[i] |= (image[i * 8 * 3 + j * 3 + k].b & 1) << j;
      }
    }
  }
}

int main() {
  int width, height;
  FILE *fp;
  pixel *image;
  char message[1024];

  // Open the image file
  fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    printf("Error opening image file\n");
    return 1;
  }

  // Read the image header
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for the image data
  image = (pixel *)malloc(width * height * 3);
  if (image == NULL) {
    printf("Error allocating memory for image data\n");
    fclose(fp);
    return 1;
  }

  // Read the image data
  fread(image, sizeof(pixel), width * height, fp);

  // Close the image file
  fclose(fp);

  // Get the message to hide
  printf("Enter the message to hide: ");
  fgets(message, sizeof(message), stdin);

  // Hide the message in the image
  hide_message(image, message, strlen(message));

  // Open the output image file
  fp = fopen("output.bmp", "wb");
  if (fp == NULL) {
    printf("Error opening output image file\n");
    free(image);
    return 1;
  }

  // Write the image header
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);

  // Write the image data
  fwrite(image, sizeof(pixel), width * height, fp);

  // Close the output image file
  fclose(fp);

  // Free the memory allocated for the image data
  free(image);

  return 0;
}