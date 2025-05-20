//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes
void flipImage(FILE *file, int width, int height, int maxValue, char outputFileName[]);
void adjustBrightnessContrast(FILE *file, int width, int height, int maxValue, char outputFileName[]);

int main()
{
  FILE *file;
  char fileName[100], outputFileName[100];
  char option[20];
  int width, height, maxValue;

  //Prompt user for file name
  printf("Enter the file name: ");
  scanf("%s", fileName);

  //Open input file for reading  
  file = fopen(fileName, "r");

  //Check if file exists
  if(file == NULL)
  {
    printf("Error: Could not open file!");
    return 0;
  }

  //Read in the image header info
  fscanf(file, "P3 %d %d %d\n", &width, &height, &maxValue);

  //Prompt user for image processing option
  printf("Enter the image processing option (flip/brightness-contrast): ");
  scanf("%s", option);

  //Call the corresponding function based on user's option
  if(strcmp(option, "flip") == 0)
  {
    //Prompt user for output file name
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    //Call function to flip the image
    flipImage(file, width, height, maxValue, outputFileName);
  }
  else if(strcmp(option, "brightness-contrast") == 0)
  {
    //Prompt user for output file name
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    //Call function to adjust the brightness/contrast of the image
    adjustBrightnessContrast(file, width, height, maxValue, outputFileName);
  }
  else
  {
    printf("Error: Invalid option!");
    return 0;
  }

  //Close the input file
  fclose(file);

  return 0;
}

//Function to flip an image horizontally
void flipImage(FILE *file, int width, int height, int maxValue, char outputFileName[])
{
  FILE *outputFile;
  int r, g, b, i, j;

  //Allocate memory for image data
  int ***imageData = (int ***)malloc(height * sizeof(int **));
  for(i = 0; i < height; i++)
  {
    imageData[i] = (int **)malloc(width * sizeof(int *));
    for(j = 0; j < width; j++)
    {
      imageData[i][j] = (int *)malloc(3 * sizeof(int));
    }
  }

  //Read in the image data
  for(i = 0; i < height; i++)
  {
    for(j = 0; j < width; j++)
    {
      fscanf(file, "%d %d %d", &r, &g, &b);
      imageData[i][j][0] = r;
      imageData[i][j][1] = g;
      imageData[i][j][2] = b;
    }
  }

  //Open output file for writing
  outputFile = fopen(outputFileName, "w");

  //Write the image header info to the output file
  fprintf(outputFile, "P3\n%d %d\n%d\n", width, height, maxValue);

  //Write the flipped image data to the output file
  for(i = 0; i < height; i++)
  {
    for(j = width-1; j >= 0; j--)
    {
      fprintf(outputFile, "%d %d %d ", imageData[i][j][0], imageData[i][j][1], imageData[i][j][2]);
    }
    fprintf(outputFile, "\n");
  }

  //Free up memory used by the image data
  for(i = 0; i < height; i++)
  {
     for(j = 0; j < width; j++)
     {
        free(imageData[i][j]);
     }
     free(imageData[i]);
  }
  free(imageData);

  //Close the output file
  fclose(outputFile);

  //Success message
  printf("Image flipped successfully!\n");
}

//Function to adjust the brightness/contrast of an image
void adjustBrightnessContrast(FILE *file, int width, int height, int maxValue, char outputFileName[])
{
  FILE *outputFile;
  int r, g, b, i, j;
  float brightness, contrast;

  //Prompt user for brightness and contrast values
  printf("Enter the brightness value (-255 to 255): ");
  scanf("%f", &brightness);
  printf("Enter the contrast value (0.1 to 10.0): ");
  scanf("%f", &contrast);

  //Allocate memory for image data
  int ***imageData = (int ***)malloc(height * sizeof(int **));
  for(i = 0; i < height; i++)
  {
    imageData[i] = (int **)malloc(width * sizeof(int *));
    for(j = 0; j < width; j++)
    {
      imageData[i][j] = (int *)malloc(3 * sizeof(int));
    }
  }

  //Read in the image data
  for(i = 0; i < height; i++)
  {
    for(j = 0; j < width; j++)
    {
      fscanf(file, "%d %d %d", &r, &g, &b);
      imageData[i][j][0] = r;
      imageData[i][j][1] = g;
      imageData[i][j][2] = b;
    }
  }

  //Open output file for writing
  outputFile = fopen(outputFileName, "w");

  //Write the image header info to the output file
  fprintf(outputFile, "P3\n%d %d\n%d\n", width, height, maxValue);

  //Write the adjusted image data to the output file
  for(i = 0; i < height; i++)
  {
    for(j = 0; j < width; j++)
    {
      r = (int)(brightness + contrast * (imageData[i][j][0] - brightness));
      g = (int)(brightness + contrast * (imageData[i][j][1] - brightness));
      b = (int)(brightness + contrast * (imageData[i][j][2] - brightness));

      //Ensure that pixel values are within the allowed range of 0 to maxValue
      if(r < 0) r = 0;
      if(r > maxValue) r = maxValue;
      if(g < 0) g = 0;
      if(g > maxValue) g = maxValue;
      if(b < 0) b = 0;
      if(b > maxValue) b = maxValue;

      fprintf(outputFile, "%d %d %d ", r, g, b);
    }
    fprintf(outputFile, "\n");
  }

  //Free up memory used by the image data
  for(i = 0; i < height; i++)
  {
     for(j = 0; j < width; j++)
     {
        free(imageData[i][j]);
     }
     free(imageData[i]);
  }
  free(imageData);

  //Close the output file
  fclose(outputFile);

  //Success message
  printf("Brightness/contrast adjusted successfully!\n");
}