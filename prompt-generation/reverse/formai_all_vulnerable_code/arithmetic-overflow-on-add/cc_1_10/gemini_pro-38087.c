//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main() {
  // Read the image file
  FILE *fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    perror("Error opening image file");
    return -1;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);

  // Read the image data
  unsigned char *data = malloc(size);
  if (data == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return -1;
  }
  fread(data, 1, size, fp);
  fclose(fp);

  // Read the secret message
  printf("Enter the secret message: ");
  char *message = malloc(MAX_SIZE);
  if (message == NULL) {
    perror("Error allocating memory");
    free(data);
    return -1;
  }
  fgets(message, MAX_SIZE, stdin);

  // Encode the secret message in the image data
  int i, j, k;
  for (i = 0, j = 0; i < size && j < strlen(message); i++) {
    if (data[i] % 2 == 0) {
      data[i] &= 0xFE;
    } else {
      data[i] |= 0x01;
    }
    data[i] |= (message[j] >> k) & 0x01;
    k++;
    if (k == 8) {
      k = 0;
      j++;
    }
  }

  // Write the steganographed image to a file
  fp = fopen("stego_image.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening stego image file");
    free(data);
    free(message);
    return -1;
  }
  fwrite(data, 1, size, fp);
  fclose(fp);

  // Free the allocated memory
  free(data);
  free(message);

  printf("Secret message successfully encoded in the image!\n");
  return 0;
}