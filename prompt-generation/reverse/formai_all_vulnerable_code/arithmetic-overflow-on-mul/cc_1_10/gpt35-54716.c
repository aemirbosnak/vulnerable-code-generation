//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  // variable declaration
  FILE *inputFile, *outputFile;
  char inputFileName[100], outputFileName[100];
  unsigned char header[54];
  int width, height, padding, rowSize, totalSize;

  // get input image file name
  printf("Enter input image file name: ");
  scanf("%s", inputFileName);

  // open input image file
  inputFile = fopen(inputFileName, "rb");

  // read header
  fread(header, sizeof(unsigned char), 54, inputFile);

  // extract image width and height from header
  width = *(int*)&header[18];
  height = *(int*)&header[22];

  // calculate padding and row size
  padding = (4 - (width * 3) % 4) % 4;
  rowSize = width * 3 + padding;
  totalSize = rowSize * height;

  // allocate memory for image data
  unsigned char *imageData = (unsigned char*)malloc(totalSize);

  // read image data from file
  fread(imageData, sizeof(unsigned char), totalSize, inputFile);

  // close input file
  fclose(inputFile);

  // create output image file name
  printf("Enter output image file name: ");
  scanf("%s", outputFileName);

  // open output image file
  outputFile = fopen(outputFileName, "wb");

  // write header to output file
  fwrite(header, sizeof(unsigned char), 54, outputFile);

  // modify image data
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int index = i * rowSize + j * 3;
      unsigned char blue = imageData[index];
      unsigned char green = imageData[index + 1];
      unsigned char red = imageData[index + 2];
      imageData[index] = red;
      imageData[index + 1] = green;
      imageData[index + 2] = blue;
    }
  }

  // write image data to output file
  fwrite(imageData, sizeof(unsigned char), totalSize, outputFile);

  // close output file
  fclose(outputFile);

  // free memory allocated for image data
  free(imageData);

  printf("Image processing completed!\n");

  return 0;
}