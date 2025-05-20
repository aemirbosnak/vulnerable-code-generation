//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IMAGE_SIZE 1024 * 1024
#define MAX_STEGO_MSG_SIZE 1024

typedef struct {
  uint8_t r, g, b;
} pixel_t;

typedef struct {
  int width, height;
  pixel_t* pixels;
} image_t;

void encode_stego_msg(image_t* img, char* msg) {
  int i, j, k;
  int msg_len = strlen(msg);

  // Encode message into image
  for (i = 0; i < img->width; i++) {
    for (j = 0; j < img->height; j++) {
      pixel_t* p = &img->pixels[i * img->width + j];
      if (k < msg_len) {
        p->r = msg[k];
        k++;
      }
    }
  }
}

void decode_stego_msg(image_t* img, char* msg) {
  int i, j, k;
  int msg_len = strlen(msg);

  // Decode message from image
  for (i = 0; i < img->width; i++) {
    for (j = 0; j < img->height; j++) {
      pixel_t* p = &img->pixels[i * img->width + j];
      if (k < msg_len) {
        msg[k] = p->r;
        k++;
      }
    }
  }
}

int main() {
  image_t img;
  char msg[MAX_STEGO_MSG_SIZE];

  // Read image file
  FILE* img_file = fopen("image.bmp", "rb");
  if (img_file == NULL) {
    fprintf(stderr, "Failed to open image file\n");
    return 1;
  }
  fread(&img.width, sizeof(int), 1, img_file);
  fread(&img.height, sizeof(int), 1, img_file);
  img.pixels = malloc(img.width * img.height * sizeof(pixel_t));
  fread(img.pixels, sizeof(pixel_t), img.width * img.height, img_file);
  fclose(img_file);

  // Read message file
  FILE* msg_file = fopen("message.txt", "rb");
  if (msg_file == NULL) {
    fprintf(stderr, "Failed to open message file\n");
    return 1;
  }
  fread(msg, sizeof(char), MAX_STEGO_MSG_SIZE, msg_file);
  fclose(msg_file);

  // Encode message into image
  encode_stego_msg(&img, msg);

  // Save encoded image
  FILE* encoded_img_file = fopen("encoded_image.bmp", "wb");
  if (encoded_img_file == NULL) {
    fprintf(stderr, "Failed to open encoded image file\n");
    return 1;
  }
  fwrite(&img.width, sizeof(int), 1, encoded_img_file);
  fwrite(&img.height, sizeof(int), 1, encoded_img_file);
  fwrite(img.pixels, sizeof(pixel_t), img.width * img.height, encoded_img_file);
  fclose(encoded_img_file);

  // Decode message from image
  decode_stego_msg(&img, msg);

  // Print decoded message
  printf("Decoded message: %s\n", msg);

  // Clean up
  free(img.pixels);

  return 0;
}