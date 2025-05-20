//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
  int i = 0;
  char buf[11];

  if (num < 0)
  {
    str[0] = '-';
    num = -num;
  }

  do
  {
    buf[i++] = num % 10 + '0';
    num /= 10;
  } while (num);

  buf[i] = '\0';
  strcpy(str, buf);
}

int main()
{
  int img_width, img_height;
  char **img_data;

  printf("Enter image width: ");
  scanf("%d", &img_width);

  printf("Enter image height: ");
  scanf("%d", &img_height);

  img_data = (char **)malloc(img_height * sizeof(char *) + 1);
  for (int h = 0; h < img_height; h++)
  {
    img_data[h] = (char *)malloc(img_width * sizeof(char) + 1);
  }

  printf("Enter image data (separated by spaces): ");
  char img_str[2048];
  scanf("%s", img_str);

  char *p = img_str;
  for (int h = 0; h < img_height; h++)
  {
    for (int w = 0; w < img_width; w++)
    {
      img_data[h][w] = *p++;
    }
  }

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
          printf("·");
          break;
        case 2:
          printf("○");
          break;
        case 3:
          printf("●");
          break;
        case 4:
          printf("■");
          break;
        default:
          printf("Error!");
          break;
      }
    }
    printf("\n");
  }

  free(img_data);

  return 0;
}