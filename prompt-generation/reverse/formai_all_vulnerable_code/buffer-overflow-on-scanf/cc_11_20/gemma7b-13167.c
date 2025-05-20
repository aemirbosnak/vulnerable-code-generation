//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359

int main() {
  char str[100];
  printf("Enter a color code (RGB or HSV): ");
  scanf("%s", str);

  int r, g, b, h, s;
  char c;

  if (strlen(str) >= 3) {
    c = str[0];
    switch (c) {
      case 'R':
        r = atoi(&str[1]);
        break;
      case 'G':
        g = atoi(&str[1]);
        break;
      case 'B':
        b = atoi(&str[1]);
        break;
      case 'H':
        h = atoi(&str[1]);
        break;
      case 'S':
        s = atoi(&str[1]);
        break;
    }

    switch (c) {
      case 'R':
        printf("Red: %d\n", r);
        break;
      case 'G':
        printf("Green: %d\n", g);
        break;
      case 'B':
        printf("Blue: %d\n", b);
        break;
      case 'H':
        printf("Hue: %d\n", h);
        break;
      case 'S':
        printf("Saturation: %d\n", s);
        break;
    }
  } else {
    printf("Invalid color code.\n");
  }

  return 0;
}