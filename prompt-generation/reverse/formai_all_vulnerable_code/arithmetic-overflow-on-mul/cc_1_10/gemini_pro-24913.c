//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int width;
  int height;
  int channels;
  unsigned char *data;
} Image;

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    fclose(fp);
    return NULL;
  }

  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  fread(&image->channels, sizeof(int), 1, fp);

  image->data = malloc(image->width * image->height * image->channels);
  if (image->data == NULL) {
    free(image);
    fclose(fp);
    return NULL;
  }

  fread(image->data, image->width * image->height * image->channels, 1, fp);
  fclose(fp);

  return image;
}

void free_image(Image *image) {
  free(image->data);
  free(image);
}

void hide_message(Image *image, const char *message) {
  int message_length = strlen(message);
  int message_index = 0;

  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if (message_index < message_length) {
      image->data[i] &= 0xFE;
      image->data[i] |= (message[message_index] & 0x01);
      message_index++;
    }
  }
}

char *extract_message(Image *image) {
  int message_length = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if ((image->data[i] & 0x01) == 0x01) {
      message_length++;
    }
  }

  char *message = malloc(message_length + 1);
  if (message == NULL) {
    return NULL;
  }

  int message_index = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if ((image->data[i] & 0x01) == 0x01) {
      message[message_index] = (image->data[i] >> 1) & 0x7F;
      message_index++;
    }
  }

  message[message_length] = '\0';

  return message;
}

int main() {
  Image *image = load_image("image.bmp");
  if (image == NULL) {
    printf("Failed to load image.\n");
    return 1;
  }

  hide_message(image, "Hello, world!");

  char *message = extract_message(image);
  if (message == NULL) {
    printf("Failed to extract message.\n");
    free_image(image);
    return 1;
  }

  printf("Message: %s\n", message);

  free(message);
  free_image(image);

  return 0;
}