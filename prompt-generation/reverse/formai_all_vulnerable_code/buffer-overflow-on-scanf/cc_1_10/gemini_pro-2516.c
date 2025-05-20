//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_IMAGE_SIZE 1000000

unsigned char *image;
unsigned char *message;
int imageSize;
int messageLength;

void embedMessage()
{
  int i, j;
  unsigned char currentByte;

  // Iterate over the image and embed the message
  for (i = 0, j = 0; i < imageSize && j < messageLength; i++)
  {
    currentByte = image[i];

    // Replace the least significant bit with the message bit
    if (message[j] & 1)
    {
      currentByte |= 1;
    }
    else
    {
      currentByte &= ~1;
    }

    image[i] = currentByte;

    // Move to the next bit in the message
    message[j] >>= 1;

    // If the message bit is 0, move to the next message byte
    if (message[j] == 0)
    {
      j++;
    }
  }
}

void extractMessage()
{
  int i, j;
  unsigned char currentByte;

  // Iterate over the image and extract the message
  for (i = 0, j = 0; i < imageSize && j < messageLength; i++)
  {
    currentByte = image[i];

    // Extract the least significant bit
    if (currentByte & 1)
    {
      message[j] |= 1;
    }

    // Move to the next bit in the message
    message[j] <<= 1;

    // If the message bit is 1, move to the next message byte
    if (message[j] & 128)
    {
      j++;
    }
  }
}

int main()
{
  char imageName[50];
  char messageFileName[50];
  char outputImageName[50];

  // Get the image name
  printf("Enter the name of the image: ");
  scanf("%s", imageName);

  // Get the message file name
  printf("Enter the name of the message file: ");
  scanf("%s", messageFileName);

  // Get the output image name
  printf("Enter the name of the output image: ");
  scanf("%s", outputImageName);

  // Load the image
  image = malloc(MAX_IMAGE_SIZE);
  if (image == NULL)
  {
    printf("Error: Could not allocate memory for the image.\n");
    return 1;
  }
  FILE *imageFile = fopen(imageName, "rb");
  if (imageFile == NULL)
  {
    printf("Error: Could not open the image file.\n");
    free(image);
    return 1;
  }
  imageSize = fread(image, 1, MAX_IMAGE_SIZE, imageFile);
  fclose(imageFile);

  // Load the message
  message = malloc(MAX_MESSAGE_LENGTH);
  if (message == NULL)
  {
    printf("Error: Could not allocate memory for the message.\n");
    free(image);
    return 1;
  }
  FILE *messageFile = fopen(messageFileName, "rb");
  if (messageFile == NULL)
  {
    printf("Error: Could not open the message file.\n");
    free(image);
    free(message);
    return 1;
  }
  messageLength = fread(message, 1, MAX_MESSAGE_LENGTH, messageFile);
  fclose(messageFile);

  // Embed the message in the image
  embedMessage();

  // Save the output image
  FILE *outputFile = fopen(outputImageName, "wb");
  if (outputFile == NULL)
  {
    printf("Error: Could not open the output image file.\n");
    free(image);
    free(message);
    return 1;
  }
  fwrite(image, 1, imageSize, outputFile);
  fclose(outputFile);

  // Free the memory
  free(image);
  free(message);

  printf("Message successfully embedded in the image!\n");

  return 0;
}