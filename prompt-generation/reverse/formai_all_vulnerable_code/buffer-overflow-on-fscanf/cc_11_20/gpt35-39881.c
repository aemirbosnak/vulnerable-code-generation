//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fIn = fopen("input_image.ppm", "r");
  FILE *fOut = fopen("output_image.ppm", "w");
  
  if(!fIn || !fOut) {
    printf("Error! Cannot open file.");
    exit(1);
  }
  
  //Reading the dimensions of the image
  int width, height, maxval;
  char pType[3];
  
  fscanf(fIn, "%s\n", pType);
  fscanf(fIn, "%d %d\n", &width, &height);
  fscanf(fIn, "%d\n", &maxval);
  
  //Writing the header of the output image
  fprintf(fOut, "%s\n", pType);
  fprintf(fOut, "%d %d\n", width, height);
  fprintf(fOut, "%d\n", maxval);
  
  //Creating the matrix to store the pixel values
  int **imageMatrix = (int **) malloc(height * sizeof(int *));
  for(int i = 0; i < height; i++)
    imageMatrix[i] = (int *) malloc(width * sizeof(int));
  
  //Reading the pixel values from the input image
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      fscanf(fIn, "%d", &imageMatrix[i][j]);
  
  //Flipping the image horizontally
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width/2; j++)
      {
        int temp = imageMatrix[i][j];
        imageMatrix[i][j] = imageMatrix[i][width-1-j];
        imageMatrix[i][width-1-j] = temp;
      }
  
  //Increasing the brightness of the image
  int brightnessValue = 50;
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      imageMatrix[i][j] += brightnessValue;
  
  //Adjusting the contrast of the image
  float contrastPercentage = 60; //Assuming a percentage value between 0 and 100
  float contrastFactor = (100 + contrastPercentage) / 100;
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      {
        int temp = imageMatrix[i][j];
        temp = (temp - maxval / 2) * contrastFactor + maxval / 2;
        if(temp < 0)
          temp = 0;
        if(temp > maxval)
          temp = maxval;
        imageMatrix[i][j] = temp;
      }
  
  //Writing the pixel values to the output image
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      fprintf(fOut, "%d ", imageMatrix[i][j]);
  
  //Freeing the memory allocated to the matrix
  for(int i = 0; i < height; i++)
    free(imageMatrix[i]);
  free(imageMatrix);
  
  //Closing the input and output files
  fclose(fIn);
  fclose(fOut);
  
  return 0;
}