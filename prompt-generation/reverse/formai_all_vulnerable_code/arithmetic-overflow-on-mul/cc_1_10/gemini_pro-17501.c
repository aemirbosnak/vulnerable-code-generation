//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Variables to store image dimensions and data
int width, height;
unsigned char *data;

// Function to flip an image horizontally
void flip_horizontal() {
  // Iterate over each row of the image
  for (int i = 0; i < height; i++) {
    // Iterate over each column of the row
    for (int j = 0; j < width / 2; j++) {
      // Swap the pixels at (j, i) and (width - j - 1, i)
      unsigned char temp = data[i * width + j];
      data[i * width + j] = data[i * width + width - j - 1];
      data[i * width + width - j - 1] = temp;
    }
  }
}

// Function to flip an image vertically
void flip_vertical() {
  // Iterate over each row of the image
  for (int i = 0; i < height / 2; i++) {
    // Iterate over each column of the row
    for (int j = 0; j < width; j++) {
      // Swap the pixels at (j, i) and (j, height - i - 1)
      unsigned char temp = data[i * width + j];
      data[i * width + j] = data[(height - i - 1) * width + j];
      data[(height - i - 1) * width + j] = temp;
    }
  }
}

// Function to change the brightness of an image
void adjust_brightness(int brightness) {
  // Iterate over each pixel in the image
  for (int i = 0; i < width * height; i++) {
    // Add the brightness value to the pixel data
    data[i] += brightness;
    
    // Clamp the pixel data to 0-255
    if (data[i] < 0) data[i] = 0;
    if (data[i] > 255) data[i] = 255;
  }
}

// Function to change the contrast of an image
void adjust_contrast(int contrast) {
  // Iterate over each pixel in the image
  for (int i = 0; i < width * height; i++) {
    // Calculate the difference between the pixel data and 128
    int diff = data[i] - 128;
    
    // Multiply the difference by the contrast value
    diff *= contrast;
    
    // Add the difference back to the pixel data
    data[i] = 128 + diff;
    
    // Clamp the pixel data to 0-255
    if (data[i] < 0) data[i] = 0;
    if (data[i] > 255) data[i] = 255;
  }
}

// Main function
int main() {
  // Open the input image file
  FILE *input = fopen("input.bmp", "rb");
  if (input == NULL) {
    fprintf(stderr, "Error opening input image file.\n");
    return 1;
  }
  
  // Read the image header
  unsigned char header[54];
  fread(header, 54, 1, input);
  
  // Get the image dimensions
  width = *(int *)&header[18];
  height = *(int *)&header[22];
  
  // Allocate memory for the image data
  data = malloc(width * height);
  
  // Read the image data
  fread(data, width * height, 1, input);
  
  // Close the input image file
  fclose(input);
  
  // Flip the image horizontally
  flip_horizontal();

  // Flip the image vertically
  flip_vertical();
  
  // Adjust the image brightness
  adjust_brightness(50);
  
  // Adjust the image contrast
  adjust_contrast(20);
  
  // Open the output image file
  FILE *output = fopen("output.bmp", "wb");
  if (output == NULL) {
    fprintf(stderr, "Error opening output image file.\n");
    return 1;
  }
  
  // Write the image header
  fwrite(header, 54, 1, output);
  
  // Write the image data
  fwrite(data, width * height, 1, output);
  
  // Close the output image file
  fclose(output);
  
  // Free the memory for the image data
  free(data);
  
  return 0;
}