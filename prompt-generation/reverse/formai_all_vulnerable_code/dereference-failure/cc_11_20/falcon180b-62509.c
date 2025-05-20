//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define watermark message and carrier image
  char watermark[] = "Ada Lovelace";
  int width = 512, height = 512;
  int watermark_size = strlen(watermark) * 8;
  int **carrier = malloc(height * sizeof(int*));
  for (int i = 0; i < height; i++) {
    carrier[i] = malloc(width * sizeof(int));
  }

  // Initialize carrier image with random values
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      carrier[i][j] = rand() % 256;
    }
  }

  // Embed watermark message into carrier image
  int **watermarked_carrier = malloc(height * sizeof(int*));
  for (int i = 0; i < height; i++) {
    watermarked_carrier[i] = malloc(width * sizeof(int));
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      watermarked_carrier[i][j] = carrier[i][j];
      if (j < watermark_size && watermark[(int) floor(j / 8)] == '1') {
        watermarked_carrier[i][j] += 1;
      }
    }
  }

  // Save watermarked carrier image as PNG file
  FILE *fp = fopen("watermarked_carrier.png", "wb");
  if (!fp) {
    printf("Error: Could not open output file.\n");
    exit(1);
  }
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fwrite(&watermarked_carrier[i][j], sizeof(int), 1, fp);
    }
  }
  fclose(fp);

  // Free memory
  for (int i = 0; i < height; i++) {
    free(carrier[i]);
  }
  free(carrier);
  for (int i = 0; i < height; i++) {
    free(watermarked_carrier[i]);
  }
  free(watermarked_carrier);

  return 0;
}