//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <omp.h>
#include <time.h>

#define PI 3.14159265358979323846

int main() {
  // Read the original image
  FILE *f = fopen("lena.bmp", "rb");
  if (f == NULL) {
    perror("Error opening the original image");
    return EXIT_FAILURE;
  }
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, f);
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];
  unsigned char *original = malloc(width * height);
  fread(original, sizeof(unsigned char), width * height, f);
  fclose(f);

  // Generate the watermark
  int watermark_size = 64;
  int watermark_bits = 8;
  unsigned char watermark[watermark_size][watermark_size];
  for (int i = 0; i < watermark_size; i++) {
    for (int j = 0; j < watermark_size; j++) {
      watermark[i][j] = (rand() % (1 << watermark_bits)) << (8 - watermark_bits);
    }
  }

  // Embed the watermark in the original image
  double alpha = 0.05;
  for (int i = 0; i < watermark_size; i++) {
    for (int j = 0; j < watermark_size; j++) {
      int x = i * width / watermark_size;
      int y = j * height / watermark_size;
      int r = (int)original[y * width + x];
      int g = (int)original[y * width + x + 1];
      int b = (int)original[y * width + x + 2];
      int m = (int)watermark[i][j];
      original[y * width + x] = r + alpha * (m - r);
      original[y * width + x + 1] = g + alpha * (m - g);
      original[y * width + x + 2] = b + alpha * (m - b);
    }
  }

  // Save the watermarked image
  f = fopen("lena_watermarked.bmp", "wb");
  if (f == NULL) {
    perror("Error opening the watermarked image");
    return EXIT_FAILURE;
  }
  fwrite(header, sizeof(unsigned char), 54, f);
  fwrite(original, sizeof(unsigned char), width * height, f);
  fclose(f);

  // Extract the watermark from the watermarked image
  unsigned char extracted_watermark[watermark_size][watermark_size];
  for (int i = 0; i < watermark_size; i++) {
    for (int j = 0; j < watermark_size; j++) {
      int x = i * width / watermark_size;
      int y = j * height / watermark_size;
      int r = (int)original[y * width + x];
      int g = (int)original[y * width + x + 1];
      int b = (int)original[y * width + x + 2];
      extracted_watermark[i][j] = (r + g + b) / 3;
    }
  }

  // Compute the bit error rate
  int bit_errors = 0;
  for (int i = 0; i < watermark_size; i++) {
    for (int j = 0; j < watermark_size; j++) {
      if (extracted_watermark[i][j] != watermark[i][j]) {
        bit_errors++;
      }
    }
  }
  double bit_error_rate = (double)bit_errors / (watermark_size * watermark_size * watermark_bits);

  // Print the bit error rate
  printf("Bit error rate: %f\n", bit_error_rate);

  // Free the memory
  free(original);

  return EXIT_SUCCESS;
}