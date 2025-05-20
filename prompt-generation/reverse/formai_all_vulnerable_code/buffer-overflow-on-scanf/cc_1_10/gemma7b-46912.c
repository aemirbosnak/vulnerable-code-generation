//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color {
  int red;
  int green;
  int blue;
  int alpha;
} Color;

Color color_convert(int color_code)
{
  Color color;

  switch (color_code) {
    case 0:
      color.red = 0;
      color.green = 0;
      color.blue = 0;
      color.alpha = 255;
      break;
    case 1:
      color.red = 255;
      color.green = 0;
      color.blue = 0;
      color.alpha = 255;
      break;
    case 2:
      color.red = 0;
      color.green = 255;
      color.blue = 0;
      color.alpha = 255;
      break;
    case 3:
      color.red = 0;
      color.green = 0;
      color.blue = 255;
      color.alpha = 255;
      break;
    default:
      color.red = 0;
      color.green = 0;
      color.blue = 0;
      color.alpha = 0;
  }

  return color;
}

int main()
{
  int color_code;

  printf("Enter a color code: ");
  scanf("%d", &color_code);

  Color color = color_convert(color_code);

  printf("Red: %d\n", color.red);
  printf("Green: %d\n", color.green);
  printf("Blue: %d\n", color.blue);
  printf("Alpha: %d\n", color.alpha);

  return 0;
}