//FormAI DATASET v1.0 Category: Image Classification system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

/* Function to classify an image */
void classifyImage(char* imageName) {
  
  // Open image
  FILE* img = fopen(imageName, "rb");
  
  if(!img) {
    printf("Unable to open image\n");
    exit(1);
  }
  
  // Read image header
  char header[54];
  fread(header, sizeof(char), 54, img);
  
  // Extract image dimensions
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];
  
  // Allocate memory for image data
  int size = width * height;
  unsigned char* data = (unsigned char*)malloc(size);
  
  // Read image data
  fread(data, sizeof(unsigned char), size, img);
  
  // Close image
  fclose(img);
  
  // Classify image based on intensity
  int sum = 0;
  
  for(int i = 0; i < size; i++) {
    sum += data[i];
  }
  
  int meanIntensity = sum / size;
  
  if(meanIntensity < 128) {
    printf("Image is dark\n");
  } else {
    printf("Image is bright\n");
  }
  
  // Free image data memory
  free(data);
}

/* Main function */
int main() {
  
  // Classify two images
  classifyImage("dark_image.jpg");
  classifyImage("bright_image.jpg");
  
  return 0;
}