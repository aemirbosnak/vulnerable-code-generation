//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    printf("Error: cannot open file '%s'\n", argv[1]);
    return 1;
  }

  // Read the BMP header
  byte header[54];
  fread(header, 54, 1, fp);

  // Check if the file is a valid BMP
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Error: file '%s' is not a valid BMP\n", argv[1]);
    fclose(fp);
    return 1;
  }

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Get the number of bits per pixel
  int bpp = *(int *)&header[28];

  // Read the image data
  byte *data = malloc(width * height * bpp / 8);
  fread(data, width * height * bpp / 8, 1, fp);

  // Flip the image
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < bpp / 8; k++) {
        byte temp = data[i * width * bpp / 8 + j * bpp / 8 + k];
        data[i * width * bpp / 8 + j * bpp / 8 + k] =
            data[(height - i - 1) * width * bpp / 8 + j * bpp / 8 + k];
        data[(height - i - 1) * width * bpp / 8 + j * bpp / 8 + k] = temp;
      }
    }
  }

  // Change the brightness and contrast
  float brightness = 0.5;
  float contrast = 1.2;

  for (int i = 0; i < width * height * bpp / 8; i++) {
    data[i] = (data[i] - 128) * contrast + 128 + brightness;
    if (data[i] < 0) {
      data[i] = 0;
    } else if (data[i] > 255) {
      data[i] = 255;
    }
  }

  // Write the modified image to a new file
  FILE *fp2 = fopen("output.bmp", "wb");
  if (fp2 == NULL) {
    printf("Error: cannot open file 'output.bmp'\n");
    fclose(fp);
    free(data);
    return 1;
  }

  fwrite(header, 54, 1, fp2);
  fwrite(data, width * height * bpp / 8, 1, fp2);

  fclose(fp);
  fclose(fp2);

  free(data);

  printf("Image flipped and brightness/contrast changed successfully!\n");
  return 0;
}