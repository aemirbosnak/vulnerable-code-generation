//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8

void hideMessage(char *image, char *message) {
  int imageSize = BYTES_PER_PIXEL * 100 * 100;
  int messageSize = strlen(message);

  // Check if the message is too large to fit in the image
  if (messageSize > imageSize) {
    printf("Error: Message is too large to fit in the image\n");
    return;
  }

  // Convert the message to binary
  char binaryMessage[messageSize * BITS_PER_BYTE];
  for (int i = 0; i < messageSize; i++) {
    for (int j = 0; j < BITS_PER_BYTE; j++) {
      binaryMessage[i * BITS_PER_BYTE + j] = (message[i] >> j) & 1;
    }
  }

  // Hide the message in the image
  for (int i = 0; i < messageSize * BITS_PER_BYTE; i++) {
    int pixelIndex = i / 3;
    int bitIndex = i % 3;
    image[pixelIndex * BYTES_PER_PIXEL + bitIndex] =
        (image[pixelIndex * BYTES_PER_PIXEL + bitIndex] & ~1) | binaryMessage[i];
  }
}

void revealMessage(char *image) {
  int imageSize = BYTES_PER_PIXEL * 100 * 100;
  char binaryMessage[imageSize * BITS_PER_BYTE];

  // Extract the message from the image
  for (int i = 0; i < imageSize * BITS_PER_BYTE; i++) {
    int pixelIndex = i / 3;
    int bitIndex = i % 3;
    binaryMessage[i] = image[pixelIndex * BYTES_PER_PIXEL + bitIndex] & 1;
  }

  // Convert the binary message to text
  char message[imageSize * BITS_PER_BYTE / 8];
  for (int i = 0; i < imageSize * BITS_PER_BYTE / 8; i++) {
    for (int j = 0; j < BITS_PER_BYTE; j++) {
      message[i] |= binaryMessage[i * BITS_PER_BYTE + j] << j;
    }
  }

  // Print the message
  printf("%s\n", message);
}

int main() {
  // Load the image
  char image[BYTES_PER_PIXEL * 100 * 100];
  FILE *imageFile = fopen("image.bmp", "rb");
  fread(image, sizeof(image), 1, imageFile);
  fclose(imageFile);

  // Load the message
  char message[1000];
  printf("Enter the message to hide: ");
  scanf("%s", message);

  // Hide the message in the image
  hideMessage(image, message);

  // Save the image
  FILE *outputImageFile = fopen("stego_image.bmp", "wb");
  fwrite(image, sizeof(image), 1, outputImageFile);
  fclose(outputImageFile);

  // Reveal the message from the image
  revealMessage(image);

  return 0;
}