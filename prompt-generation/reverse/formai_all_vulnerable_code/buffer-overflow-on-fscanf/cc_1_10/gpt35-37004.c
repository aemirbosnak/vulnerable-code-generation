//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define ASCII_CHARACTERS " .,:;ox%#@"

struct Image {
  int width;
  int height;
  unsigned char data[MAX_HEIGHT][MAX_WIDTH][3];
};

char grayScaleToASCII(unsigned char grayScale) {
  int asciiIndex = round((grayScale / 255.0) * (strlen(ASCII_CHARACTERS) - 1));
  return ASCII_CHARACTERS[asciiIndex];
}

void convertToGrayScale(struct Image *image) {
  for(int i = 0; i < image->height; i++) {
    for(int j = 0; j < image->width; j++) {
      unsigned char R = image->data[i][j][0];
      unsigned char G = image->data[i][j][1];
      unsigned char B = image->data[i][j][2];
      unsigned char grayScale = 0.2989 * R + 0.5870 * G + 0.1140 * B;
      image->data[i][j][0] = grayScale;
      image->data[i][j][1] = grayScale;
      image->data[i][j][2] = grayScale;
    }
  }
}

void convertToASCII(struct Image *image) {
  for(int i = 0; i < image->height; i++) {
    for(int j = 0; j < image->width; j++) {
      unsigned char grayScale = image->data[i][j][0];
      char asciiChar = grayScaleToASCII(grayScale);
      printf("%c", asciiChar);
    }
    printf("\n");
  }
}

void readImage(FILE *file, struct Image *image) {
  char format[3];
  fscanf(file, "%s\n", format);
  if(strcmp(format, "P6") != 0) {
    printf("Error: Invalid PPM file format\n");
    exit(1);
  }

  fscanf(file, "%d %d\n", &image->width, &image->height);
  if(image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
    printf("Error: Image dimensions exceed maximum allowed size\n");
    exit(1);
  }

  int maxVal;
  fscanf(file, "%d\n", &maxVal);
  if(maxVal != 255) {
    printf("Error: Invalid maximum value (only 255 is supported)\n");
    exit(1);
  }

  fread(image->data, sizeof(unsigned char), image->width * image->height * 3, file);
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    exit(1);
  }

  FILE *inputFile = fopen(argv[1], "rb");
  if(inputFile == NULL) {
    printf("Error: Failed to open input file\n");
    exit(1);
  }

  struct Image image;
  readImage(inputFile, &image);
  fclose(inputFile);

  convertToGrayScale(&image);
  convertToASCII(&image);

  return 0;
}