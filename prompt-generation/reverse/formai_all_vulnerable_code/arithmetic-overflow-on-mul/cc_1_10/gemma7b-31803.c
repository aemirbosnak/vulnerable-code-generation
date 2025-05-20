//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

int main()
{
  int img_width, img_height;
  char **img_data;

  printf("Enter image width: ");
  scanf("%d", &img_width);

  printf("Enter image height: ");
  scanf("%d", &img_height);

  img_data = malloc(img_height * sizeof(char *) + 1);
  for (int h = 0; h < img_height; h++)
  {
    img_data[h] = malloc(img_width * sizeof(char) + 1);
  }

  printf("Enter image data (each pixel as a number, separated by spaces): ");
  char input[MAX_WIDTH * img_height];
  scanf("%s", input);

  int pixel_index = 0;
  for (int h = 0; h < img_height; h++)
  {
    for (int w = 0; w < img_width; w++)
    {
      img_data[h][w] = input[pixel_index++];
    }
  }

  printf("Image converted to ASCII art:\n");
  for (int h = 0; h < img_height; h++)
  {
    for (int w = 0; w < img_width; w++)
    {
      switch (img_data[h][w])
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

  free(img_data);

  return 0;
}