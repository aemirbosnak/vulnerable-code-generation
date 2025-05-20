//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("=== C Image Steganography Example ===\n");

  // Instructions
  printf("Please enter the name of the image file you want to modify: ");
  char filename[25];
  scanf("%s", filename);

  printf("Please enter the name of the file you want to hide: ");
  char secFilename[25];
  scanf("%s", secFilename);

  // Image file handler
  FILE* imageFile;
  imageFile = fopen(filename, "r+b");
  if (imageFile == NULL) {
    printf("Error: Could not open %s\n", filename);
    exit(1);
  }

  // Secondary file handler
  FILE* secFile;
  secFile = fopen(secFilename, "rb");
  if (secFile == NULL) {
    printf("Error: Could not open %s\n", secFilename);
    exit(1);
  }

  // Get size of secondary file
  fseek(secFile, 0, SEEK_END);
  int fileSize = ftell(secFile);
  rewind(secFile);

  // Check image file size
  fseek(imageFile, 0, SEEK_END);
  int imageSize = ftell(imageFile);
  rewind(imageFile);

  if (fileSize >= imageSize) {
    printf("Error: File too large to hide in %s\n", filename);
    exit(1);
  }

  // User prompt
  printf("\nAre you sure you want to hide '%s' in '%s'? (Y/N)\n", secFilename, filename);
  char choice;
  scanf(" %c", &choice);

  if (choice != 'Y' && choice != 'y') {
    printf("\nExiting program.\n");
    exit(0);
  }

  // Write hidden message size in image
  unsigned char fileSizeArray[4];
  for (int i = 3; i >= 0; i--) {
    fileSizeArray[i] = (fileSize >> (i*8)) & 0xFF;
  }

  for (int i = 0; i < 4; i++) {
    fputc(fileSizeArray[i], imageFile);
  }

  // Write hidden message in image
  unsigned char pixel[3];
  int byteCount = 0;

  while (fread(pixel, 1, 3, imageFile) == 3) {
    if (byteCount < fileSize) {
      int bit = 7;
      while (bit >= 0 && byteCount < fileSize) {
        unsigned char bitMask = 1 << bit;
        unsigned char bitValue = (fgetc(secFile) >> bit) & 1;

        if (bitValue == 1) {
          pixel[0] = (pixel[0] & ~1) | 1;
        } else {
          pixel[0] = (pixel[0] & ~1) | 0;
        }

        byteCount++;
        bit--;

        if (bit >= 0 && byteCount < fileSize) {
          bitValue = (fgetc(secFile) >> bit) & 1;

          if (bitValue == 1) {
            pixel[1] = (pixel[1] & ~1) | 1;
          } else {
            pixel[1] = (pixel[1] & ~1) | 0;
          }

          byteCount++;
          bit--;
        }

        if (bit >= 0 && byteCount < fileSize) {
          bitValue = (fgetc(secFile) >> bit) & 1;

          if (bitValue == 1) {
            pixel[2] = (pixel[2] & ~1) | 1;
          } else {
            pixel[2] = (pixel[2] & ~1) | 0;
          }

          byteCount++;
          bit--;
        }
      }
    }

    fwrite(pixel, 1, 3, imageFile);
  }

  // Clean up
  fclose(imageFile);
  fclose(secFile);
  printf("\nDone!\n");

  return 0;
}