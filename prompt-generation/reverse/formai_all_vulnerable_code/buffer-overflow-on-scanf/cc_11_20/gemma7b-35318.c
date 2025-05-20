//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  char color_code[3];
  printf("Enter a color code (e.g. rgb, hsb): ");
  scanf("%s", color_code);

  switch (color_code[0]) {
    case 'r':
      printf("Red: ");
      break;
    case 'g':
      printf("Green: ");
      break;
    case 'b':
      printf("Blue: ");
      break;
    case 'h':
      printf("Hue: ");
      break;
    default:
      printf("Invalid color code.\n");
      break;
  }

  switch (color_code[1]) {
    case 'g':
      printf("Green: ");
      break;
    case 'b':
      printf("Blue: ");
      break;
    case 'r':
      printf("Red: ");
      break;
    case 'a':
      printf("Alpha: ");
      break;
    default:
      printf("Invalid color code.\n");
      break;
  }

  switch (color_code[2]) {
    case 'b':
      printf("Blue: ");
      break;
    case 'g':
      printf("Green: ");
      break;
    case 'r':
      printf("Red: ");
      break;
    case 'a':
      printf("Alpha: ");
      break;
    default:
      printf("Invalid color code.\n");
      break;
  }

  printf("\n");
  return 0;
}