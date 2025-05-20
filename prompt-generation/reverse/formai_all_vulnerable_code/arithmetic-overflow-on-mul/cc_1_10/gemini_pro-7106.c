//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char *data;
  int width;
  int height;
  int depth;
} Image;

Image *read_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }
  fseek(fp, 10, SEEK_SET);
  fread(&image->width, 4, 1, fp);
  fread(&image->height, 4, 1, fp);
  fread(&image->depth, 1, 1, fp);
  fseek(fp, 54, SEEK_SET);
  image->data = malloc(image->width * image->height * image->depth);
  fread(image->data, image->width * image->height * image->depth, 1, fp);
  fclose(fp);
  return image;
}

void write_image(char *filename, Image *image) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }
  fwrite("BM", 2, 1, fp);
  fwrite(&image->width, 4, 1, fp);
  fwrite(&image->height, 4, 1, fp);
  fwrite(&image->depth, 1, 1, fp);
  fseek(fp, 54, SEEK_SET);
  fwrite(image->data, image->width * image->height * image->depth, 1, fp);
  fclose(fp);
}

void hide_watermark(Image *image, char *watermark) {
  int i, j, k;
  int watermark_length = strlen(watermark);
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      for (k = 0; k < image->depth; k++) {
        image->data[i * image->width * image->depth + j * image->depth + k] ^= watermark[i % watermark_length];
      }
    }
  }
}

char *extract_watermark(Image *image) {
  int i, j, k;
  int watermark_length = 100;
  char *watermark = malloc(watermark_length);
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      for (k = 0; k < image->depth; k++) {
        watermark[i % watermark_length] ^= image->data[i * image->width * image->depth + j * image->depth + k];
      }
    }
  }
  return watermark;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s image.bmp watermark.txt output.bmp\n", argv[0]);
    return 1;
  }
  Image *image = read_image(argv[1]);
  if (!image) {
    return 1;
  }
  FILE *fp = fopen(argv[2], "r");
  if (!fp) {
    fprintf(stderr, "Error opening file %s\n", argv[2]);
    return 1;
  }
  char *watermark = malloc(100);
  fscanf(fp, "%s", watermark);
  fclose(fp);
  hide_watermark(image, watermark);
  write_image(argv[3], image);
  free(image->data);
  free(image);
  free(watermark);
  return 0;
}