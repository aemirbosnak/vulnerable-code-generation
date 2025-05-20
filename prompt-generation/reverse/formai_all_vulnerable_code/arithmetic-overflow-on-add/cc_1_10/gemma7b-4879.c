//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  char *img = "image.jpg";
  char *msg = "This is a secret message";
  int watermarked_size = watermark(img, msg);

  if (watermarked_size) {
    printf("Watermarked image size: %d bytes\n", watermarked_size);
  } else {
    printf("Error watermarking image\n");
  }

  return 0;
}

int watermark(char *img, char *msg) {
  // Calculate hash of the message
  int msg_hash = hash(msg);

  // Open the image file
  FILE *fp = fopen(img, "rb");

  // Get the image size
  int size = fileSize(fp);

  // Allocate memory for the watermark
  char *watermarked_img = malloc(size);

  // Read the image data
  fread(watermarked_img, size, 1, fp);

  // Insert the hash into the watermark
  watermarked_img[size - 1] = (msg_hash & 0xFF) + 1;
  watermarked_img[size - 2] = (msg_hash >> 8) & 0xFF;

  // Close the image file
  fclose(fp);

  // Return the watermark size
  return size + 2;
}

int hash(char *str) {
  int hash = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    hash += str[i] * i;
  }
  return hash;
}

int fileSize(FILE *fp) {
  fseek(fp, 0, SEEK_END);
  int size = ftell(fp);
  rewind(fp);
  return size;
}