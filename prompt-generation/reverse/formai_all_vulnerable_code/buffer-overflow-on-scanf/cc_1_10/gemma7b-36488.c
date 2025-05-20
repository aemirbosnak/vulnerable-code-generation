//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color {
  int r;
  int g;
  int b;
} Color;

Color convert_color(char color_code) {
  Color color;

  switch (color_code) {
    case 'r':
      color.r = 255;
      color.g = 0;
      color.b = 0;
      break;
    case 'g':
      color.r = 0;
      color.g = 255;
      color.b = 0;
      break;
    case 'b':
      color.r = 0;
      color.g = 0;
      color.b = 255;
      break;
    case 'w':
      color.r = 255;
      color.g = 255;
      color.b = 255;
      break;
    default:
      color.r = 0;
      color.g = 0;
      color.b = 0;
  }

  return color;
}

int main() {
  char color_code;

  printf("Enter a color code: ");
  scanf("%c", &color_code);

  Color color = convert_color(color_code);

  printf("Red: %d\n", color.r);
  printf("Green: %d\n", color.g);
  printf("Blue: %d\n", color.b);

  return 0;
}