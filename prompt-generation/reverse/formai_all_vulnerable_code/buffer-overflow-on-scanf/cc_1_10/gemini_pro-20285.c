//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// This program hides a secret message inside an image by replacing the least significant bit of each pixel with a bit from the message.

// Define the maximum size of the input image and the secret message.
#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Declare the input image, the secret message, and the output image.
unsigned char inputImage[MAX_IMAGE_SIZE];
unsigned char secretMessage[MAX_MESSAGE_SIZE];
unsigned char outputImage[MAX_IMAGE_SIZE];

// Declare the size of the input image and the secret message.
int imageSize;
int messageSize;

// Declare the function to hide the secret message in the input image.
void hideMessage(unsigned char *inputImage, unsigned char *secretMessage, unsigned char *outputImage, int imageSize, int messageSize);

// Declare the function to extract the secret message from the output image.
void extractMessage(unsigned char *outputImage, unsigned char *secretMessage, int imageSize, int messageSize);

// Main function.
int main() {
  // Get the input image from the user.
  printf("Enter the name of the input image: ");
  char inputImageFileName[100];
  scanf("%s", inputImageFileName);

  // Get the secret message from the user.
  printf("Enter the secret message: ");
  char secretMessageText[MAX_MESSAGE_SIZE];
  scanf("%s", secretMessageText);

  // Convert the secret message to a binary string.
  messageSize = strlen(secretMessageText);
  for (int i = 0; i < messageSize; i++) {
    secretMessage[i] = secretMessageText[i];
  }

  // Get the size of the input image.
  FILE *inputImageFile = fopen(inputImageFileName, "rb");
  fseek(inputImageFile, 0, SEEK_END);
  imageSize = ftell(inputImageFile);
  fseek(inputImageFile, 0, SEEK_SET);

  // Read the input image into memory.
  fread(inputImage, 1, imageSize, inputImageFile);
  fclose(inputImageFile);

  // Hide the secret message in the input image.
  hideMessage(inputImage, secretMessage, outputImage, imageSize, messageSize);

  // Write the output image to a file.
  printf("Enter the name of the output image: ");
  char outputImageFileName[100];
  scanf("%s", outputImageFileName);

  FILE *outputImageFile = fopen(outputImageFileName, "wb");
  fwrite(outputImage, 1, imageSize, outputImageFile);
  fclose(outputImageFile);

  // Extract the secret message from the output image.
  extractMessage(outputImage, secretMessage, imageSize, messageSize);

  // Print the secret message.
  printf("The secret message is: %s\n", secretMessage);

  return 0;
}

// Function to hide the secret message in the input image.
void hideMessage(unsigned char *inputImage, unsigned char *secretMessage, unsigned char *outputImage, int imageSize, int messageSize) {
  // Loop through each byte of the secret message.
  for (int i = 0; i < messageSize; i++) {
    // Get the binary representation of the byte.
    unsigned char byte = secretMessage[i];

    // Loop through each bit of the byte.
    for (int j = 0; j < 8; j++) {
      // Get the bit from the byte.
      unsigned char bit = (byte >> j) & 1;

      // Replace the least significant bit of the pixel with the bit.
      outputImage[i * 8 + j] = (inputImage[i * 8 + j] & 0xfe) | bit;
    }
  }
}

// Function to extract the secret message from the output image.
void extractMessage(unsigned char *outputImage, unsigned char *secretMessage, int imageSize, int messageSize) {
  // Loop through each byte of the secret message.
  for (int i = 0; i < messageSize; i++) {
    // Get the byte from the output image.
    unsigned char byte = 0;

    // Loop through each bit of the byte.
    for (int j = 0; j < 8; j++) {
      // Get the bit from the output image.
      unsigned char bit = outputImage[i * 8 + j] & 1;

      // Shift the byte to the left by one bit.
      byte = byte << 1;

      // Add the bit to the byte.
      byte = byte | bit;
    }

    // Store the byte in the secret message.
    secretMessage[i] = byte;
  }
}