//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char b;
  unsigned char g;
  unsigned char r;
} pixel;

typedef struct {
  int width;
  int height;
  pixel *data;
} image;

image *load_image(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  image *img = malloc(sizeof(image));
  if (img == NULL) {
    fprintf(stderr, "Error allocating memory for image\n");
    return NULL;
  }

  fread(&img->width, sizeof(int), 1, fp);
  fread(&img->height, sizeof(int), 1, fp);
  img->data = malloc(img->width * img->height * sizeof(pixel));
  if (img->data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    return NULL;
  }

  fread(img->data, sizeof(pixel), img->width * img->height, fp);
  fclose(fp);

  return img;
}

void save_image(image *img, char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  fwrite(&img->width, sizeof(int), 1, fp);
  fwrite(&img->height, sizeof(int), 1, fp);
  fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
  fclose(fp);
}

void hide_message(image *img, char *message) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (message[k] != '\0') {
    for (i = 0; i < 8; i++) {
      img->data[j].b = (img->data[j].b & 0xfe) | ((message[k] >> i) & 0x01);
      j++;
    }
    k++;
  }
}

char *extract_message(image *img) {
  int i = 0;
  int j = 0;
  int k = 0;
  char *message = malloc(img->width * img->height / 8 + 1);
  if (message == NULL) {
    fprintf(stderr, "Error allocating memory for message\n");
    return NULL;
  }

  for (i = 0; i < img->width * img->height / 8; i++) {
    for (j = 0; j < 8; j++) {
      message[k] |= (img->data[i].b & 0x01) << j;
      i++;
    }
    k++;
  }
  message[k] = '\0';

  return message;
}

int main() {
  image *img = load_image("image.bmp");
  if (img == NULL) {
    return 1;
  }

  char *message = "Hello, world!";
  hide_message(img, message);
  save_image(img, "image_with_message.bmp");

  char *extracted_message = extract_message(img);
  if (extracted_message == NULL) {
    return 1;
  }

  printf("Extracted message: %s\n", extracted_message);
  free(extracted_message);
  free(img->data);
  free(img);
  return 0;
}