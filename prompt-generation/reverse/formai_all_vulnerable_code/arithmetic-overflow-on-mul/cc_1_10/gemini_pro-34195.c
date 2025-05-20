//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image
#define MAX_SIZE 1024

// Define the watermark
#define WATERMARK "Copyright 2023"

// Embed the watermark into the image
void embed_watermark(unsigned char *image, int width, int height) {
  // Convert the watermark to a binary string
  char *binary_watermark = malloc(strlen(WATERMARK) * 8 + 1);
  for (int i = 0; i < strlen(WATERMARK); i++) {
    for (int j = 7; j >= 0; j--) {
      binary_watermark[(i * 8) + j] = (WATERMARK[i] >> j) & 1 ? '1' : '0';
    }
  }
  binary_watermark[strlen(WATERMARK) * 8] = '\0';

  // Embed the watermark into the image
  int watermark_index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the least significant bit of the pixel
      unsigned char lsb = image[(i * width) + j] & 1;

      // Set the least significant bit of the pixel to the next bit of the watermark
      image[(i * width) + j] = (image[(i * width) + j] & ~1) | (binary_watermark[watermark_index] - '0');

      // Increment the watermark index
      watermark_index++;
    }
  }

  // Free the memory allocated for the binary watermark
  free(binary_watermark);
}

// Extract the watermark from the image
char *extract_watermark(unsigned char *image, int width, int height) {
  // Create a buffer to store the extracted watermark
  char *extracted_watermark = malloc(strlen(WATERMARK) + 1);

  // Extract the watermark from the image
  int watermark_index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the least significant bit of the pixel
      unsigned char lsb = image[(i * width) + j] & 1;

      // Append the least significant bit of the pixel to the extracted watermark
      extracted_watermark[watermark_index] = lsb + '0';

      // Increment the watermark index
      watermark_index++;
    }
  }

  // Terminate the extracted watermark with a null character
  extracted_watermark[strlen(WATERMARK)] = '\0';

  // Return the extracted watermark
  return extracted_watermark;
}

// Main function
int main() {
  // Load the image from a file
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error opening image file");
    return 1;
  }

  // Get the width and height of the image
  int width, height;
  fscanf(image_file, "BM%d %d\n", &width, &height);

  // Read the image data into a buffer
  unsigned char *image = malloc(width * height);
  fread(image, 1, width * height, image_file);

  // Embed the watermark into the image
  embed_watermark(image, width, height);

  // Save the watermarked image to a file
  FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
  if (watermarked_image_file == NULL) {
    printf("Error opening watermarked image file");
    return 1;
  }

  // Write the header to the watermarked image file
  fprintf(watermarked_image_file, "BM%d %d\n", width, height);

  // Write the image data to the watermarked image file
  fwrite(image, 1, width * height, watermarked_image_file);

  // Close the image and watermarked image files
  fclose(image_file);
  fclose(watermarked_image_file);

  // Extract the watermark from the watermarked image
  char *extracted_watermark = extract_watermark(image, width, height);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extracted_watermark);

  // Free the memory allocated for the extracted watermark
  free(extracted_watermark);

  // Free the memory allocated for the image
  free(image);

  return 0;
}