//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define custom struct for pixel data
typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

//function to read image from file
Pixel* readImage(FILE* filePointer, int* widthPointer, int* heightPointer) {
  //read and skip bmp header
  fseek(filePointer, 54, SEEK_SET);
  
  //read width and height
  fread(widthPointer, sizeof(int), 1, filePointer);
  fread(heightPointer, sizeof(int), 1, filePointer);
  
  //calculate padding for each row
  int padding = (*widthPointer * 3) % 4;
  if(padding != 0) padding = 4 - padding;
  
  //allocate memory for pixel data
  Pixel* imageData = malloc(*widthPointer * (*heightPointer) * sizeof(Pixel));
  
  //read pixel data
  for(int i = 0; i < (*heightPointer); i++) {
    for(int j = 0; j < (*widthPointer); j++) {
      Pixel* pixelPointer = imageData + i * (*widthPointer) + j;
      fread(&(pixelPointer->blue), sizeof(unsigned char), 1, filePointer); 
      fread(&(pixelPointer->green), sizeof(unsigned char), 1, filePointer);
      fread(&(pixelPointer->red), sizeof(unsigned char), 1, filePointer);
    }
    
    //skip padding at end of row
    fseek(filePointer, padding, SEEK_CUR);
  }
  
  return imageData;
}

//function to write image to file
void writeImage(FILE* filePointer, Pixel* imageData, int width, int height) {
  //write bmp header
  unsigned char bmpHeader[54] = {
    'B', 'M', //file type
    0, 0, 0, 0, //file size
    0, 0, //reserved
    0, 0, //reserved
    54, 0, 0, 0, //offset to pixel data
    40, 0, 0, 0, //size of DIB header
    0, 0, 0, 0, //width
    0, 0, 0, 0, //height (negative indicates top-to-bottom order)
    1, 0, //number of color planes
    24, 0, //bits per pixel
    0, 0, 0, 0, //compression method
    0, 0, 0, 0, //image size
    0, 0, 0, 0, //horizontal resolution
    0, 0, 0, 0, //vertical resolution
    0, 0, 0, 0, //number of colors in palette
    0, 0, 0, 0 //number of important colors
  };
  
  //set width and height in header
  *((int*) &(bmpHeader[18])) = width;
  *((int*) &(bmpHeader[22])) = height;
  
  //write bmp header
  fwrite(bmpHeader, sizeof(unsigned char), 54, filePointer);
  
  //calculate padding for each row
  int padding = (width * 3) % 4;
  if(padding != 0) padding = 4 - padding;
  
  //write pixel data
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      Pixel* pixelPointer = imageData + i * width + j;
      fwrite(&(pixelPointer->blue), sizeof(unsigned char), 1, filePointer);
      fwrite(&(pixelPointer->green), sizeof(unsigned char), 1, filePointer);
      fwrite(&(pixelPointer->red), sizeof(unsigned char), 1, filePointer);
    }
    
    //pad end of row
    unsigned char paddingData[4] = {0, 0, 0, 0};
    fwrite(paddingData, sizeof(unsigned char), padding, filePointer);
  }
}

int main(int argc, char* argv[]) {
  //check for filename argument
  if(argc < 2) {
    printf("Usage: ./imageEditor input_file.bmp [output_file.bmp]\n");
    return 1;
  }
  
  //open input file
  FILE* inputFile = fopen(argv[1], "rb");
  if(!inputFile) {
    printf("Error: could not open input file %s\n", argv[1]);
    return 1;
  }
  
  //read image from file
  int width, height;
  Pixel* imageData = readImage(inputFile, &width, &height);
  
  //close input file
  fclose(inputFile);
  
  //apply some image processing techniques
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      Pixel* pixelPointer = imageData + i * width + j;
      
      //do some processing on each pixel
      //for example, invert the color
      pixelPointer->red = 255 - pixelPointer->red;
      pixelPointer->green = 255 - pixelPointer->green;
      pixelPointer->blue = 255 - pixelPointer->blue;
    }
  }
  
  //check for output filename argument
  char* outputFilename = "output.bmp";
  if(argc >= 3) {
    outputFilename = argv[2];
  }
  
  //open output file
  FILE* outputFile = fopen(outputFilename, "wb");
  if(!outputFile) {
    printf("Error: could not open output file %s\n", outputFilename);
    return 1;
  }
  
  //write image to file
  writeImage(outputFile, imageData, width, height);
  
  //free memory for pixel data
  free(imageData);
  
  //close output file
  fclose(outputFile);
  
  printf("Image processing completed successfully!\n");
  
  return 0;
}