//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Ada Lovelace
// Ada Lovelace style digital watermarking

#include <stdio.h>
#include <stdlib.h>

// Constants
#define IMAGE_WIDTH   256
#define IMAGE_HEIGHT  256
#define WATERMARK_SIZE  32

// Function to embed watermark in image
void embedWatermark(unsigned char *image, unsigned char *watermark) {
  int i, j, k;
  for (i = 0; i < IMAGE_HEIGHT; i++) {
    for (j = 0; j < IMAGE_WIDTH; j++) {
      for (k = 0; k < WATERMARK_SIZE; k++) {
        image[i * IMAGE_WIDTH + j] |= watermark[k * WATERMARK_SIZE + k] << k;
      }
    }
  }
}

// Function to extract watermark from image
void extractWatermark(unsigned char *image, unsigned char *watermark) {
  int i, j, k;
  for (i = 0; i < IMAGE_HEIGHT; i++) {
    for (j = 0; j < IMAGE_WIDTH; j++) {
      for (k = 0; k < WATERMARK_SIZE; k++) {
        watermark[k * WATERMARK_SIZE + k] |= (image[i * IMAGE_WIDTH + j] >> k) & 1;
      }
    }
  }
}

// Main function
int main() {
  // Initialize image and watermark
  unsigned char image[IMAGE_HEIGHT * IMAGE_WIDTH];
  unsigned char watermark[WATERMARK_SIZE * WATERMARK_SIZE];

  // Read image from file
  FILE *file = fopen("image.bmp", "rb");
  fread(image, sizeof(unsigned char), IMAGE_HEIGHT * IMAGE_WIDTH, file);
  fclose(file);

  // Read watermark from file
  file = fopen("watermark.bmp", "rb");
  fread(watermark, sizeof(unsigned char), WATERMARK_SIZE * WATERMARK_SIZE, file);
  fclose(file);

  // Embed watermark in image
  embedWatermark(image, watermark);

  // Write watermarked image to file
  file = fopen("watermarkedImage.bmp", "wb");
  fwrite(image, sizeof(unsigned char), IMAGE_HEIGHT * IMAGE_WIDTH, file);
  fclose(file);

  // Extract watermark from image
  extractWatermark(image, watermark);

  // Write extracted watermark to file
  file = fopen("extractedWatermark.bmp", "wb");
  fwrite(watermark, sizeof(unsigned char), WATERMARK_SIZE * WATERMARK_SIZE, file);
  fclose(file);

  return 0;
}