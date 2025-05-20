//FormAI DATASET v1.0 Category: Image Classification system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure for holding RGB values
typedef struct {
  int r;
  int g;
  int b;
} Pixel;

// Function to compare two pixels
int comparePixels(Pixel pixel1, Pixel pixel2) {
  if (pixel1.r == pixel2.r && pixel1.g == pixel2.g && pixel1.b == pixel2.b) {
    return 1;
  } else {
    return 0;
  }
}

int main() {

  FILE *imgFile;
  char fileName[100];
  printf("Enter the image file name: ");
  scanf("%s", fileName);

  // Open the image file in binary mode
  imgFile = fopen(fileName, "rb");
  if (imgFile == NULL) {
    printf("Error opening image file\n");
    exit(1);
  }

  // Read image dimensions
  int width, height;
  fseek(imgFile, 18, SEEK_SET);
  fread(&width, sizeof(int), 1, imgFile);
  fread(&height, sizeof(int), 1, imgFile);

  // Allocate memory for image data
  Pixel **imageData;
  imageData = (Pixel **)malloc(height * sizeof(Pixel *));
  for (int i = 0; i < height; i++) {
    imageData[i] = (Pixel *)malloc(width * sizeof(Pixel));
  }

  // Read image data
  fseek(imgFile, 54, SEEK_SET);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fread(&imageData[i][j].b, sizeof(unsigned char), 1, imgFile);
      fread(&imageData[i][j].g, sizeof(unsigned char), 1, imgFile);
      fread(&imageData[i][j].r, sizeof(unsigned char), 1, imgFile);
    }
  }

  // Close image file
  fclose(imgFile);

  // Classify image based on pixel values
  int countRed = 0, countGreen = 0, countBlue = 0, countOther = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (comparePixels(imageData[i][j], (Pixel) {255, 0, 0})) {
        countRed++;
      } else if (comparePixels(imageData[i][j], (Pixel) {0, 255, 0})) {
        countGreen++;
      } else if (comparePixels(imageData[i][j], (Pixel) {0, 0, 255})) {
        countBlue++;
      } else {
        countOther++;
      }
    }
  }

  // Output classification results
  printf("Image classification report:\n");
  printf("Red pixels: %d\n", countRed);
  printf("Green pixels: %d\n", countGreen);
  printf("Blue pixels: %d\n", countBlue);
  printf("Other pixels: %d\n", countOther);

  // Free memory allocated for image data
  for (int i = 0; i < height; i++) {
    free(imageData[i]);
  }
  free(imageData);

  return 0;
}