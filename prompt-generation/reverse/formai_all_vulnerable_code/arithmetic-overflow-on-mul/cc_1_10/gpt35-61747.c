//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the global variables
int width, height;
char *pixels;

// The conversion function 
char* toAscii(char* img) {

  // Open the image file
  FILE *fptr;
  fptr = fopen(img, "rb");

  // Invalid file check
  if (fptr == NULL) {
    printf("Error opening image file!\n");
    exit(1);
  }

  // Get the dimensions of the image
  char buf[100];
  fgets(buf, sizeof buf, fptr);
  fgets(buf, sizeof buf, fptr);
  sscanf(buf, "%d %d", &width, &height);
  
  // Allocate memory for the pixel array
  pixels = (char*)malloc(width * height * sizeof(char));
  int i, j;
  int index;

  // Read in pixel values
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      index = i*width+j;
      pixels[index] = fgetc(fptr);
    }
  }

  // Close the image file
  fclose(fptr);

  // Convert the pixels into ASCII characters
  int pixelVal, asciiVal;
  char *asciiImage = (char *)malloc(height * width * sizeof(char));
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      index = i*width+j;
      pixelVal = pixels[index];
      asciiVal = (pixelVal * 10) / 255;
      asciiImage[index] = " .:-=+*#%@"[asciiVal];
    }
    asciiImage[index+1] = '\n';
  }

  // Free the allocated memory
  free(pixels);

  // Return the result
  return asciiImage;
}

int main() {
  // Test the conversion function
  char *asciiImage = toAscii("image.pgm");
  printf("%s\n", asciiImage);
  return 0;
}