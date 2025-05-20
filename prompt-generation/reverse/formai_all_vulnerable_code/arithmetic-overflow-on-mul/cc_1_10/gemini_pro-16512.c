//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  // Define the image and message files
  FILE *image_file = fopen("image.bmp", "rb");
  FILE *message_file = fopen("message.txt", "rb");

  // Check if the files opened successfully
  if (!image_file) {
    perror("Error opening image file");
    return EXIT_FAILURE;
  }
  if (!message_file) {
    perror("Error opening message file");
    return EXIT_FAILURE;
  }

  // Read the image header
  unsigned char header[54];
  fread(header, sizeof(header), 1, image_file);

  // Get the image dimensions
  int width = *(int *) &header[18];
  int height = *(int *) &header[22];

  // Allocate memory for the image data
  unsigned char *image_data = malloc(width * height * 3);

  // Read the image data
  fread(image_data, width * height * 3, 1, image_file);

  // Read the message
  unsigned char message[1024];
  fread(message, 1024, 1, message_file);

  // Embed the message in the image
  int message_index = 0;
  for (int i = 0; i < width * height * 3; i++) {
    if (message_index >= 1024) {
      break;
    }

    // Get the least significant bit of the image pixel
    unsigned char bit = image_data[i] & 1;

    // Replace the least significant bit with the message bit
    image_data[i] &= 0xFE;
    image_data[i] |= message[message_index] & 1;

    // Increment the message index
    message_index++;
  }

  // Write the modified image data to a new file
  FILE *output_file = fopen("output.bmp", "wb");
  fwrite(header, sizeof(header), 1, output_file);
  fwrite(image_data, width * height * 3, 1, output_file);

  // Free the allocated memory
  free(image_data);

  // Close the files
  fclose(image_file);
  fclose(message_file);
  fclose(output_file);

  return EXIT_SUCCESS;
}