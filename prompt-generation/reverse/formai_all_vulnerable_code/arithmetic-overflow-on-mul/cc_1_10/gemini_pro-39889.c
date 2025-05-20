//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

unsigned char image[MAX_SIZE][MAX_SIZE];
unsigned char watermark[MAX_SIZE][MAX_SIZE];
unsigned char watermarked[MAX_SIZE][MAX_SIZE];

void embedWatermark() {
  int i, j;

  for (i = 0; i < MAX_SIZE; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      watermarked[i][j] = image[i][j];
      if (watermark[i][j] == 1) {
        watermarked[i][j] |= 1;
      }
    }
  }
}

void extractWatermark() {
  int i, j;

  for (i = 0; i < MAX_SIZE; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      watermark[i][j] = watermarked[i][j] & 1;
    }
  }
}

int main() {
  int width, height;

  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error opening image file\n");
    return 1;
  }

  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  fread(image, sizeof(unsigned char), width * height, image_file);
  fclose(image_file);

  FILE *watermark_file = fopen("watermark.bmp", "rb");
  if (watermark_file == NULL) {
    printf("Error opening watermark file\n");
    return 1;
  }

  fread(&width, sizeof(int), 1, watermark_file);
  fread(&height, sizeof(int), 1, watermark_file);

  fread(watermark, sizeof(unsigned char), width * height, watermark_file);
  fclose(watermark_file);

  embedWatermark();

  FILE *watermarked_file = fopen("watermarked.bmp", "wb");
  if (watermarked_file == NULL) {
    printf("Error opening watermarked file\n");
    return 1;
  }

  fwrite(&width, sizeof(int), 1, watermarked_file);
  fwrite(&height, sizeof(int), 1, watermarked_file);

  fwrite(watermarked, sizeof(unsigned char), width * height, watermarked_file);
  fclose(watermarked_file);

  extractWatermark();

  FILE *extracted_watermark_file = fopen("extracted_watermark.bmp", "wb");
  if (extracted_watermark_file == NULL) {
    printf("Error opening extracted watermark file\n");
    return 1;
  }

  fwrite(&width, sizeof(int), 1, extracted_watermark_file);
  fwrite(&height, sizeof(int), 1, extracted_watermark_file);

  fwrite(watermark, sizeof(unsigned char), width * height, extracted_watermark_file);
  fclose(extracted_watermark_file);

  return 0;
}