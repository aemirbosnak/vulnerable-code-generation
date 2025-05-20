//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define LSB_MASK 0x1

typedef struct {
  int width;
  int height;
  int channels;
  unsigned char *data;
} Image;

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp)
    return NULL;

  Image *image = malloc(sizeof(Image));
  if (!image) {
    fclose(fp);
    return NULL;
  }

  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  fread(&image->channels, sizeof(int), 1, fp);

  image->data = malloc(image->width * image->height * image->channels);
  if (!image->data) {
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->data, image->width * image->height * image->channels, 1, fp);
  fclose(fp);

  return image;
}

void free_image(Image *image) {
  if (!image)
    return;

  free(image->data);
  free(image);
}

int hide_message(Image *image, const char *message) {
  int message_length = strlen(message);
  if (message_length > image->width * image->height * image->channels)
    return -1;

  int i, j, k, l;
  for (i = 0, l = 0; i < image->width * image->height * image->channels; i++) {
    if (l == message_length)
      break;

    for (j = 0; j < image->channels; j++) {
      if (l == message_length)
        break;

      int bit = message[l++] & LSB_MASK;
      image->data[i * image->channels + j] &= ~LSB_MASK;
      image->data[i * image->channels + j] |= bit;
    }
  }

  return 0;
}

char *extract_message(Image *image) {
  int message_length = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if ((image->data[i] & LSB_MASK) == 0)
      break;
    message_length++;
  }

  if (message_length == 0)
    return NULL;

  char *message = malloc(message_length + 1);
  if (!message)
    return NULL;

  int i, j, k, l;
  for (i = 0, l = 0; i < image->width * image->height * image->channels; i++) {
    if (l == message_length)
      break;

    for (j = 0; j < image->channels; j++) {
      if (l == message_length)
        break;

      message[l++] = (image->data[i * image->channels + j] & LSB_MASK) + '0';
    }
  }

  message[message_length] = '\0';
  return message;
}

int main() {
  char *filename = "image.bmp";
  Image *image = load_image(filename);
  if (!image) {
    printf("Error loading image.\n");
    return 1;
  }

  char *message = "The secret message";
  if (hide_message(image, message) == -1) {
    printf("Error hiding message.\n");
    free_image(image);
    return 1;
  }

  char *extracted_message = extract_message(image);
  if (!extracted_message) {
    printf("Error extracting message.\n");
    free_image(image);
    return 1;
  }

  printf("Extracted message: %s\n", extracted_message);
  free(extracted_message);
  free_image(image);
  return 0;
}