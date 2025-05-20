//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed a secret message in an image
void embedMessage(char *srcImage, int srcImageSize, char *secretMessage, int secretMessageSize, char *dstImage) {
  // Check if the secret message can fit in the image
  if (secretMessageSize >= srcImageSize) {
    printf("Error: Secret message is too large to embed in image.\n");
    exit(1);
  }

  // Embed the secret message in the image
  for (int i = 0; i < secretMessageSize; i++) {
    // Convert the secret message character to binary
    char binaryMessage[8];
    for (int j = 0; j < 8; j++) {
      binaryMessage[j] = (secretMessage[i] >> j) & 1;
    }

    // Embed the binary message in the image
    for (int j = 0; j < 8; j++) {
      // Get the least significant bit of the image pixel
      unsigned char pixel = srcImage[i * 8 + j];
      unsigned char lsb = pixel & 1;

      // Replace the least significant bit of the image pixel with the binary message bit
      pixel &= ~1;
      pixel |= binaryMessage[j];

      // Update the image pixel
      srcImage[i * 8 + j] = pixel;
    }
  }

  // Save the watermarked image to a file
  FILE *dstFile = fopen(dstImage, "wb");
  fwrite(srcImage, srcImageSize, 1, dstFile);
  fclose(dstFile);
}

// Function to extract a secret message from an image
char *extractMessage(char *srcImage, int srcImageSize) {
  // Extract the binary message from the image
  char *binaryMessage = malloc(srcImageSize / 8);
  for (int i = 0; i < srcImageSize / 8; i++) {
    for (int j = 0; j < 8; j++) {
      // Get the least significant bit of the image pixel
      unsigned char pixel = srcImage[i * 8 + j];
      unsigned char lsb = pixel & 1;

      // Add the least significant bit to the binary message
      binaryMessage[i] |= lsb << j;
    }
  }

  // Convert the binary message to a text message
  char *textMessage = malloc(strlen(binaryMessage) + 1);
  for (int i = 0; i < strlen(binaryMessage); i++) {
    textMessage[i] = (char) strtol(binaryMessage + i * 8, NULL, 2);
  }
  textMessage[strlen(binaryMessage)] = '\0';

  // Return the secret message
  return textMessage;
}

int main() {
  // Get the source image file name
  char srcImageFileName[256];
  printf("Enter the source image file name: ");
  scanf("%s", srcImageFileName);

  // Get the secret message
  char secretMessage[256];
  printf("Enter the secret message: ");
  scanf(" %s", secretMessage);

  // Embed the secret message in the image
  embedMessage(srcImageFileName, 100, secretMessage, strlen(secretMessage), "watermarked.jpg");

  // Extract the secret message from the watermarked image
  char *extractedMessage = extractMessage("watermarked.jpg", 100);

  // Print the extracted message
  printf("Extracted message: %s\n", extractedMessage);

  return 0;
}