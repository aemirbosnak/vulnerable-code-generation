//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void itoa(int n, char *s);

int main()
{
  int img_width, img_height;
  printf("Enter image width: ");
  scanf("%d", &img_width);

  printf("Enter image height: ");
  scanf("%d", &img_height);

  unsigned char **img_data = (unsigned char **)malloc(img_height * sizeof(unsigned char *) + 1);
  for (int h = 0; h < img_height; h++)
  {
    img_data[h] = (unsigned char *)malloc(img_width * sizeof(unsigned char) + 1);
  }

  printf("Enter image data (separated by commas): ");
  char img_data_str[2048];
  fgets(img_data_str, 2048, stdin);

  char *img_data_ptr = img_data_str;
  for (int h = 0; h < img_height; h++)
  {
    for (int w = 0; w < img_width; w++)
    {
      int pixel_value = atoi(img_data_ptr);
      img_data[h][w] = pixel_value;
      img_data_ptr++;
    }
  }

  for (int h = 0; h < img_height; h++)
  {
    for (int w = 0; w < img_width; w++)
    {
      int pixel_value = img_data[h][w];
      char pixel_ascii = (pixel_value < 25) ? pixel_value + 32 : '*';
      printf("%c ", pixel_ascii);
    }
    printf("\n");
  }

  free(img_data);

  return 0;
}

void itoa(int n, char *s)
{
  int i = 0;
  char sign = (n < 0) ? '-' : '+';
  n = abs(n);

  while (n)
  {
    int digit = n % 10;
    s[i++] = digit + '0';
    n /= 10;
  }

  if (sign)
    s[i++] = sign;

  s[i] = '\0';
}