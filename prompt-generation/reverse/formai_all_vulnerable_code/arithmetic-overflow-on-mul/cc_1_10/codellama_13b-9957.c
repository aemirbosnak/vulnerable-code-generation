//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
// Image Steganography in C
// Enthusiastic Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to hide the message in an image
void hideMessage(char *message, char *imageFile) {
  // Open the image file
  FILE *image = fopen(imageFile, "rb");
  if (!image) {
    printf("Error opening image file\n");
    return;
  }

  // Get the image dimensions
  int width, height;
  fscanf(image, "%d %d", &width, &height);

  // Create a new image file with the hidden message
  char *newImageFile = "new_image.pgm";
  FILE *newImage = fopen(newImageFile, "wb");
  if (!newImage) {
    printf("Error creating new image file\n");
    return;
  }

  // Hide the message in the image
  int i, j;
  for (i = 0; i < strlen(message); i++) {
    // Get the ASCII value of the character
    int value = (int) message[i];

    // Hide the value in the image
    for (j = 0; j < 8; j++) {
      // Get the current pixel value
      int pixel = fgetc(image);

      // Replace the least significant bit with the next bit of the message
      int newPixel = pixel & 0xFE;
      if (value & 1) {
        newPixel |= 1;
      }

      // Write the new pixel value to the new image file
      fputc(newPixel, newImage);

      // Shift the message to the next bit
      value >>= 1;
    }
  }

  // Close the image file
  fclose(image);

  // Close the new image file
  fclose(newImage);

  printf("Image steganography successful!\n");
}

// Function to extract the hidden message from an image
void extractMessage(char *imageFile) {
  // Open the image file
  FILE *image = fopen(imageFile, "rb");
  if (!image) {
    printf("Error opening image file\n");
    return;
  }

  // Get the image dimensions
  int width, height;
  fscanf(image, "%d %d", &width, &height);

  // Extract the hidden message
  int i, j;
  char message[width * height];
  for (i = 0; i < width * height; i++) {
    // Get the current pixel value
    int pixel = fgetc(image);

    // Extract the least significant bit of the pixel
    int value = pixel & 1;

    // Append the bit to the message
    message[i] = value;
  }

  // Close the image file
  fclose(image);

  // Print the hidden message
  printf("Hidden message: %s\n", message);
}

int main() {
  // Hide a message in an image
  char *message = "Hello, world!";
  char *imageFile = "image.pgm";
  hideMessage(message, imageFile);

  // Extract the hidden message from the image
  extractMessage(imageFile);

  return 0;
}