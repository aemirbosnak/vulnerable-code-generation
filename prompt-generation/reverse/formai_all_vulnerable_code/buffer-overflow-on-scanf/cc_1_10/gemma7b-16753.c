//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
  int i = 0;
  char num[10];

  if (n < 0)
  {
    s[0] = '-';
    n = -n;
  }

  do
  {
    num[i++] = n % 10 + '0';
    n /= 10;
  } while (n);

  num[i] = '\0';
  strcpy(s, num);
}

int main()
{
  char image[1024];
  int w, h;

  printf("Enter the width and height of the image: ");
  scanf("%d %d", &w, &h);

  printf("Enter the image data (each pixel as a number, separated by spaces): ");
  scanf("%s", image);

  int pixels = w * h;
  int i = 0;

  for (i = 0; i < pixels; i++)
  {
    int pixel = image[i] - '0';
    char asciiArt[10] = "";

    itoa(pixel, asciiArt);
    printf("%s ", asciiArt);
  }

  printf("\n");

  return 0;
}