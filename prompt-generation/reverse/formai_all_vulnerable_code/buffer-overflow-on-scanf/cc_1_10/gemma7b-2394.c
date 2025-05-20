//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int w, h;
  scanf("Enter the dimensions of the image (w,h): ", "%d %d", &w, &h);

  char **img = malloc(h * sizeof(char *) + 1);
  for (int r = 0; r < h; r++)
  {
    img[r] = malloc(w * sizeof(char) + 1);
  }

  // Read the image data
  printf("Enter the image data (each pixel as a decimal number, separated by commas): ");
  scanf("%[^\n]", img);

  // Convert the image data into ASCII art
  for (int r = 0; r < h; r++)
  {
    for (int c = 0; c < w; c++)
    {
      int pixel = img[r][c];
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

  // Free the memory allocated for the image
  for (int r = 0; r < h; r++)
  {
    free(img[r]);
  }
  free(img);

  return 0;
}