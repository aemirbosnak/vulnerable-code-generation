//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

// Function to flip the image horizontally
void flipImageHorizontally(int *image, int rows, int columns) {
  int temp;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns / 2; j++) {
      temp = *(image + i * columns + j);
      *(image + i * columns + j) = *(image + i * columns + (columns - 1 - j));
      *(image + i * columns + (columns - 1 - j)) = temp;
    }
  }
}

// Function to change the brightness of the image
void changeBrightness(int *image, int rows, int columns, int brightness) {
  float brightnessFactor = (float)brightness / MAX_PIXEL_VALUE;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int pixelValue = *(image + i * columns + j);
      int newPixelValue = (int)(pixelValue * brightnessFactor);
      *(image + i * columns + j) = newPixelValue;
    }
  }
}

// Function to change the contrast of the image
void changeContrast(int *image, int rows, int columns, int contrast) {
  float contrastFactor = (259.0f * (float)(contrast + 255.0f)) / (255.0f * (259.0f - (float)contrast));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int pixelValue = *(image + i * columns + j);
      int newPixelValue = (int)(contrastFactor * (pixelValue - 128.0f) + 128.0f);
      if (newPixelValue < 0) newPixelValue = 0;
      if (newPixelValue > MAX_PIXEL_VALUE) newPixelValue = MAX_PIXEL_VALUE;
      *(image + i * columns + j) = newPixelValue;
    }
  }
}

int main() {
  int rows, columns, brightness, contrast;
  
  // Read input image from file
  FILE *inputImageFile = fopen("input_image.txt", "r");
  if (!inputImageFile) {
    printf("Error: Unable to read input image!\n");
    exit(-1);
  }
  fscanf(inputImageFile, "%d %d\n", &rows, &columns);
  int *image = (int *)malloc(rows * columns * sizeof(int));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      fscanf(inputImageFile, "%d", (image + i * columns + j));
    }
  }
  fclose(inputImageFile);
  
  // Flip the image horizontally
  flipImageHorizontally(image, rows, columns);
  
  // Change the brightness of the image
  printf("Enter the brightness (between -255 and 255): ");
  scanf("%d", &brightness);
  changeBrightness(image, rows, columns, brightness);
  
  // Change the contrast of the image
  printf("Enter the contrast (between -255 and 255): ");
  scanf("%d", &contrast);
  changeContrast(image, rows, columns, contrast);
  
  // Write output image to file
  FILE *outputImageFile = fopen("output_image.txt", "w");
  if (!outputImageFile) {
    printf("Error: Unable to write output image!\n");
    exit(-1);
  }
  fprintf(outputImageFile, "%d %d\n", rows, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      fprintf(outputImageFile, "%d ", *(image + i * columns + j));
    }
    fprintf(outputImageFile, "\n");
  }
  fclose(outputImageFile);
  
  free(image);
  return 0;
}