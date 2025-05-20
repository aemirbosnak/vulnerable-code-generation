//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fpIn, *fpOut;
  char *fileIn = "input.bmp";
  char *fileOut = "output.bmp";
  unsigned char header[54];
  signed char pixel[3];
  int padding = 0;
  int width, height;
  int brightness = 50;
  double contrast = 1.5;

  fpIn = fopen(fileIn, "rb");
  if (fpIn == NULL) {
    printf("Unable to open the file.\n");
    return 0;
  }

  fpOut = fopen(fileOut, "wb");

  fseek(fpIn, 0L, SEEK_END);
  int fileSize = ftell(fpIn);
  rewind(fpIn);

  fread(header, sizeof(unsigned char), 54, fpIn);
  fwrite(header, sizeof(unsigned char), 54, fpOut);

  width = *(int *)&header[18];
  height = *(int *)&header[22];

  if ((width * 3) % 4 != 0) {
    padding = 4 - (width * 3) % 4;
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fread(pixel, sizeof(signed char), 3, fpIn);
      signed char B = (int)pixel[0];
      signed char G = (int)pixel[1];
      signed char R = (int)pixel[2];

      // Brightness
      B = B + brightness;
      G = G + brightness;
      R = R + brightness;
      if (B > 255) {
        B = 255;
      }
      if (G > 255) {
        G = 255;
      }
      if (R > 255) {
        R = 255;
      }
      if (B < 0) {
        B = 0;
      }
      if (G < 0) {
        G = 0;
      }
      if (R < 0) {
        R = 0;
      }

      // Contrast
      B = (int)((B - 128) * contrast + 128);
      G = (int)((G - 128) * contrast + 128);
      R = (int)((R - 128) * contrast + 128);
      if (B > 255) {
        B = 255;
      }
      if (G > 255) {
        G = 255;
      }
      if (R > 255) {
        R = 255;
      }
      if (B < 0) {
        B = 0;
      }
      if (G < 0) {
        G = 0;
      }
      if (R < 0) {
        R = 0;
      }

      // Flip
      fwrite(&B, sizeof(signed char), 1, fpOut);
      fwrite(&G, sizeof(signed char), 1, fpOut);
      fwrite(&R, sizeof(signed char), 1, fpOut);
    }
    int paddingValue = 0;
    while (paddingValue < padding) {
      fwrite(&paddingValue, sizeof(signed char), 1, fpOut);
      paddingValue++;
    }
  }

  fclose(fpIn);
  fclose(fpOut);

  return 0;
}