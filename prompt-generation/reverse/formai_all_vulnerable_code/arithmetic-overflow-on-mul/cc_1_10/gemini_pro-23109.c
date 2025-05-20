//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  unsigned char *image;
  int width;
  int height;
  int channels;
} Image;

typedef struct {
  unsigned char *watermark;
  int width;
  int height;
  int channels;
} Watermark;

Image *read_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  if (!image) {
    return NULL;
  }

  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    free(image);
    return NULL;
  }

  // Read the header
  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  fread(&image->channels, sizeof(int), 1, fp);

  // Allocate memory for the image data
  image->image = malloc(image->width * image->height * image->channels);
  if (!image->image) {
    fclose(fp);
    free(image);
    return NULL;
  }

  // Read the image data
  fread(image->image, 1, image->width * image->height * image->channels, fp);

  fclose(fp);

  return image;
}

Watermark *read_watermark(char *filename) {
  Watermark *watermark = malloc(sizeof(Watermark));
  if (!watermark) {
    return NULL;
  }

  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    free(watermark);
    return NULL;
  }

  // Read the header
  fread(&watermark->width, sizeof(int), 1, fp);
  fread(&watermark->height, sizeof(int), 1, fp);
  fread(&watermark->channels, sizeof(int), 1, fp);

  // Allocate memory for the watermark data
  watermark->watermark = malloc(watermark->width * watermark->height * watermark->channels);
  if (!watermark->watermark) {
    fclose(fp);
    free(watermark);
    return NULL;
  }

  // Read the watermark data
  fread(watermark->watermark, 1, watermark->width * watermark->height * watermark->channels, fp);

  fclose(fp);

  return watermark;
}

void write_image(Image *image, char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    return;
  }

  // Write the header
  fwrite(&image->width, sizeof(int), 1, fp);
  fwrite(&image->height, sizeof(int), 1, fp);
  fwrite(&image->channels, sizeof(int), 1, fp);

  // Write the image data
  fwrite(image->image, 1, image->width * image->height * image->channels, fp);

  fclose(fp);
}

void embed_watermark(Image *image, Watermark *watermark) {
  int x, y, c;
  for (y = 0; y < watermark->height; y++) {
    for (x = 0; x < watermark->width; x++) {
      for (c = 0; c < watermark->channels; c++) {
        image->image[(y * image->width + x) * image->channels + c] =
            image->image[(y * image->width + x) * image->channels + c] & ~1 |
            watermark->watermark[(y * watermark->width + x) * watermark->channels + c] & 1;
      }
    }
  }
}

Watermark *extract_watermark(Image *image, Watermark *watermark) {
  int x, y, c;
  for (y = 0; y < watermark->height; y++) {
    for (x = 0; x < watermark->width; x++) {
      for (c = 0; c < watermark->channels; c++) {
        watermark->watermark[(y * watermark->width + x) * watermark->channels + c] =
            image->image[(y * image->width + x) * image->channels + c] & 1;
      }
    }
  }

  return watermark;
}

int main() {
  Image *image = read_image("image.png");
  if (!image) {
    printf("Error reading image\n");
    return 1;
  }

  Watermark *watermark = read_watermark("watermark.png");
  if (!watermark) {
    printf("Error reading watermark\n");
    return 1;
  }

  if (image->width < watermark->width || image->height < watermark->height) {
    printf("Watermark is too large for image\n");
    return 1;
  }

  embed_watermark(image, watermark);

  write_image(image, "watermarked_image.png");

  Watermark *extracted_watermark = extract_watermark(image, watermark);
  if (!extracted_watermark) {
    printf("Error extracting watermark\n");
    return 1;
  }

  write_image(extracted_watermark, "extracted_watermark.png");

  free(image);
  free(watermark);
  free(extracted_watermark);

  return 0;
}