//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main()
{
  int image[HEIGHT][WIDTH]; //initialize the image with zeros
  int x, y, i, j;
  FILE* fp;
  fp = fopen("input.txt", "r");
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      fscanf(fp, "%d", &image[y][x]);
    }
  }
  fclose(fp);

  //Flip the image horizontally
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      i = x;
      j = y;
      image[y][x] = image[j][i];
    }
  }

  //Change brightness
  int brightness = 20; //change this value to increase or decrease brightness
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      image[y][x] += brightness;
    }
  }

  //Change contrast
  int contrast = 50; //change this value to increase or decrease contrast
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      image[y][x] = (int) round((double) image[y][x] * (double) contrast / 100);
    }
  }

  //Save the modified image to a file
  fp = fopen("output.txt", "w");
  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      fprintf(fp, "%d ", image[y][x]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  return 0;
}