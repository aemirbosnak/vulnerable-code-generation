//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow, I can't believe I just created a digital watermarking program using C!\n\n");

  // Prompt user for input image path
  char inputImagePath[100];
  printf("Please enter the path to the image you want to watermark:\n");
  scanf("%s", inputImagePath);
  printf("\n");

  // Prompt user for watermark text
  char watermarkText[100];
  printf("Please enter the text you want to use as the watermark:\n");
  scanf("%s", watermarkText);
  printf("\n");

  // Open input image in binary mode for reading
  FILE *inputImageFile = fopen(inputImagePath, "rb");
  if (inputImageFile == NULL) {
    printf("Error: Could not open input image file\n");
    return 1;
  }

  // Create output image file with "_watermarked" appended to the file name
  char outputImagePath[100];
  sprintf(outputImagePath, "%s_watermarked", inputImagePath);
  FILE *outputImageFile = fopen(outputImagePath, "wb");
  if (outputImageFile == NULL) {
    printf("Error: Could not create output image file\n");
    return 1;
  }

  // Write watermark text size to output image file
  int watermarkTextSize = strlen(watermarkText);
  fwrite(&watermarkTextSize, sizeof(int), 1, outputImageFile);

  // Write watermark text to output image file
  fwrite(watermarkText, sizeof(char), watermarkTextSize, outputImageFile);

  // Copy input image data to output image file
  int bufferSize = 1024;
  char buffer[bufferSize];
  int bytesRead;
  do {
    bytesRead = fread(buffer, sizeof(char), bufferSize, inputImageFile);
    fwrite(buffer, sizeof(char), bytesRead, outputImageFile);
  } while (bytesRead == bufferSize);

  // Close input and output image files
  fclose(inputImageFile);
  fclose(outputImageFile);

  printf("Success! Watermark added to image at path: %s\n", outputImagePath);

  return 0;
}