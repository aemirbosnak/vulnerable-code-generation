//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

typedef struct {
  int width;
  int height;
  Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

void read_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  fread(&image->width, sizeof(int), 1, file);
  fread(&image->height, sizeof(int), 1, file);

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fread(&image->pixels[i][j].red, sizeof(unsigned char), 1, file);
      fread(&image->pixels[i][j].green, sizeof(unsigned char), 1, file);
      fread(&image->pixels[i][j].blue, sizeof(unsigned char), 1, file);
    }
  }

  fclose(file);
}

void write_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  fwrite(&image->width, sizeof(int), 1, file);
  fwrite(&image->height, sizeof(int), 1, file);

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fwrite(&image->pixels[i][j].red, sizeof(unsigned char), 1, file);
      fwrite(&image->pixels[i][j].green, sizeof(unsigned char), 1, file);
      fwrite(&image->pixels[i][j].blue, sizeof(unsigned char), 1, file);
    }
  }

  fclose(file);
}

void embed_watermark(Image *image, char *watermark) {
  int watermark_length = strlen(watermark);

  for (int i = 0; i < watermark_length; i++) {
    int bit = (watermark[i] >> 7) & 1;
    image->pixels[i / 8][i % 8].red = (image->pixels[i / 8][i % 8].red & 0xFE) | bit;
  }
}

char *extract_watermark(Image *image) {
  int watermark_length = 8 * image->width * image->height;
  char *watermark = malloc(watermark_length + 1);

  for (int i = 0; i < watermark_length; i++) {
    int bit = image->pixels[i / 8][i % 8].red & 1;
    watermark[i] = (watermark[i] << 1) | bit;
  }

  watermark[watermark_length] = '\0';

  return watermark;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
    exit(1);
  }

  Image image;
  read_image(&image, argv[1]);

  embed_watermark(&image, argv[2]);

  write_image(&image, argv[3]);

  char *watermark = extract_watermark(&image);
  printf("Watermark: %s\n", watermark);

  free(watermark);

  return 0;
}