//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int height, width;
  printf("Enter the height and width of the pixel art: ");
  scanf("%d %d", &height, &width);
  
  char pixelChar;
  printf("Enter the character to use for the pixels: ");
  scanf(" %c", &pixelChar);
  
  int colorChoice;
  printf("Choose the color of the pixel art:\n1. Black & White\n2. RGB\n");
  scanf("%d", &colorChoice);

  int pixelArt[height][width];
  srand(time(NULL));
  
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (colorChoice == 1)
      {
        pixelArt[i][j] = rand() % 2; // Black or white
      }
      else
      {
        pixelArt[i][j] = rand() % 256; // Red, green, or blue
      }
    }
  }

  printf("Your pixel art:\n");
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (colorChoice == 1)
      {
        if (pixelArt[i][j] == 0)
        {
          printf(" ");
        }
        else
        {
          printf("%c", pixelChar);
        }
      }
      else
      {
        printf("\033[48;2;%d;%d;%dm%c\033[0m", pixelArt[i][j], pixelArt[i][j], pixelArt[i][j], pixelChar);
        // ANSI escape code for RGB background color
      }
    }
    printf("\n");
  }

  return 0;
}