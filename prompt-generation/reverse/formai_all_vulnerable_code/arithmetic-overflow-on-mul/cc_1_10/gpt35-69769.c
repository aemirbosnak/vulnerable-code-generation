//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Ken Thompson style C Basic Image Processing Program */

void flip_vertical(int width, int height, unsigned char* image_data) {
  int i, j;
  unsigned char temp;
  
  for (i = 0; i < height / 2; i++) {
    for (j = 0; j < width; j++) {
      temp = image_data[i * width + j];
      image_data[i * width + j] = image_data[(height - 1 - i) * width + j];
      image_data[(height - 1 - i) * width + j] = temp;
    }
  }
}

void flip_horizontal(int width, int height, unsigned char* image_data) {
  int i, j;
  unsigned char temp;
  
  for (i = 0; i < height; i++) {
    for (j = 0; j < width / 2; j++) {
      temp = image_data[i * width + j];
      image_data[i * width + j] = image_data[i * width + (width - 1 - j)];
      image_data[i * width + (width - 1 - j)] = temp;
    }
  }
}

void adjust_contrast(int width, int height, unsigned char* image_data, int contrast) {
  int i, j;
  
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      image_data[i * width + j] = image_data[i * width + j] * contrast / 100;
    }
  }
}

void adjust_brightness(int width, int height, unsigned char* image_data, int brightness) {
  int i, j;
  
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      image_data[i * width + j] = image_data[i * width + j] + brightness;
    }
  }
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
    exit(1);
  }
  
  FILE* fp = fopen(argv[1], "rb");
  if (!fp) {
    fprintf(stderr, "Unable to open file %s\n", argv[1]);
    exit(1);
  }
  
  int width, height, bytes_per_pixel;
  unsigned char* image_data;
  char header[54];
  
  fread(header, sizeof(char), 54, fp);
  width = *(int*)&header[18];
  height = *(int*)&header[22];
  bytes_per_pixel = *(int*)&header[28] / 8;
  
  image_data = (unsigned char*)malloc(width * height * bytes_per_pixel);
  fread(image_data, sizeof(unsigned char), width * height * bytes_per_pixel, fp);
  fclose(fp);
  
  // Flip image vertically
  flip_vertical(width, height, image_data);
  
  // Flip image horizontally
  flip_horizontal(width, height, image_data);
  
  // Adjust contrast
  adjust_contrast(width, height, image_data, 125);
  
  // Adjust brightness
  adjust_brightness(width, height, image_data, 50);
  
  // Write modified image data to file
  fp = fopen("modified_image.bmp", "wb");
  fwrite(header, sizeof(char), 54, fp);
  fwrite(image_data, sizeof(unsigned char), width * height * bytes_per_pixel, fp);
  fclose(fp);
  
  free(image_data);
  
  return 0;
}