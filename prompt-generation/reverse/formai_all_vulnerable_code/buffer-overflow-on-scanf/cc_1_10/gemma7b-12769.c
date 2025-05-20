//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  system("clear");
  printf("Welcome to the Pixel Master!\n");
  printf("Please paste your image below:\n");

  char img[1024];
  fgets(img, 1024, stdin);

  int w, h;
  printf("Enter the width of your image: ");
  scanf("%d", &w);

  printf("Enter the height of your image: ");
  scanf("%d", &h);

  int pixels[w * h];
  printf("Enter the pixel values (separated by commas): ");
  scanf("%d,", pixels);

  int i, j, k = 0;
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      int pixel = pixels[k];
      switch (pixel)
      {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("#");
          break;
        default:
          printf("!");
          break;
      }
    }
    printf("\n");
  }

  return 0;
}