//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color {
  int r;
  int g;
  int b;
  int a;
} Color;

Color colorConvert(int colorCode) {
  Color color;

  switch (colorCode) {
    case 0:
      color.r = 0;
      color.g = 0;
      color.b = 0;
      color.a = 255;
      break;
    case 1:
      color.r = 255;
      color.g = 0;
      color.b = 0;
      color.a = 255;
      break;
    case 2:
      color.r = 0;
      color.g = 255;
      color.b = 0;
      color.a = 255;
      break;
    case 3:
      color.r = 0;
      color.g = 0;
      color.b = 255;
      color.a = 255;
      break;
    default:
      color.r = -1;
      color.g = -1;
      color.b = -1;
      color.a = -1;
  }

  return color;
}

int main() {
  int colorCode;

  printf("Enter a color code (0-3): ");
  scanf("%d", &colorCode);

  Color color = colorConvert(colorCode);

  if (color.r == -1 || color.g == -1 || color.b == -1) {
    printf("Invalid color code.\n");
  } else {
    printf("Color converted:\n");
    printf("R: %d\n", color.r);
    printf("G: %d\n", color.g);
    printf("B: %d\n", color.b);
    printf("A: %d\n", color.a);
  }

  return 0;
}