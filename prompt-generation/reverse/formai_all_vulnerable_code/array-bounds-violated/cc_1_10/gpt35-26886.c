//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>

int main() {
  //open image file
  FILE *imageFile;
  imageFile = fopen("image.bmp", "r+");

  //retrieve image header information
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, imageFile);

  //retrieve image dimensions
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  //retrieve image data
  unsigned char image[width*height*3];
  fseek(imageFile, 54, SEEK_SET);
  fread(image, sizeof(unsigned char), width*height*3, imageFile);

  //flip image horizontally
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width/2; j++) {
      for(int k = 0; k < 3; k++) {
        int index1 = (i*width+j)*3+k;
        int index2 = (i*width+(width-j-1))*3+k;
        unsigned char temp = image[index1];
        image[index1] = image[index2];
        image[index2] = temp;
      }
    }
  }

  //adjust brightness and contrast
  int brightness = 50;
  float contrast = 1.5;
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      for(int k = 0; k < 3; k++) {
        int index = (i*width+j)*3+k;
        int pixel = image[index] + brightness;
        pixel = (pixel-128)*contrast + 128; //adjust contrast
        if(pixel > 255) {
          pixel = 255;
        } else if(pixel < 0) {
          pixel = 0;
        }
        image[index] = pixel;
      }
    }
  }

  //write updated image data to file
  fseek(imageFile, 54, SEEK_SET);
  fwrite(image, sizeof(unsigned char), width*height*3, imageFile);

  //close file
  fclose(imageFile);

  return 0;
}