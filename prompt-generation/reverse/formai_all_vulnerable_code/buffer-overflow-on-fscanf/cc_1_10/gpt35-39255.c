//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* inputFile;
  FILE* outputFile;
  char inputFileName[50];
  char outputFileName[50];
  int width, height, maxColorValue, colorValue;

  // Get input file name from user
  printf("Enter input file name: ");
  scanf("%s", inputFileName);

  // Open input file
  inputFile = fopen(inputFileName, "r");

  // Check if file is valid
  if (inputFile == NULL) {
    printf("Error: Could not open input file");
    return 1;
  }

  // Get width and height from input file
  fscanf(inputFile, "%d %d", &width, &height);

  // Get max color value from input file
  fscanf(inputFile, "%d", &maxColorValue);

  // Create output file
  strcpy(outputFileName, inputFileName);
  strcat(outputFileName, "_edited.ppm");
  outputFile = fopen(outputFileName, "w");

  // Write P3 magic number to output file
  fprintf(outputFile, "P3\n");

  // Write width and height to output file
  fprintf(outputFile, "%d %d\n", width, height);

  // Write max color value to output file
  fprintf(outputFile, "%d\n", maxColorValue);

  // Loop through each pixel in input file
  for (int i = 0; i < width * height; i++) {
    // Get color value from input file
    fscanf(inputFile, "%d", &colorValue);

    // Modify color value
    colorValue = colorValue * 1.5;

    // Write modified color value to output file
    fprintf(outputFile, "%d ", colorValue);
    fprintf(outputFile, "%d ", colorValue);
    fprintf(outputFile, "%d\n", colorValue);
  }

  // Close files
  fclose(inputFile);
  fclose(outputFile);

  printf("Image editing complete!");

  return 0;
}