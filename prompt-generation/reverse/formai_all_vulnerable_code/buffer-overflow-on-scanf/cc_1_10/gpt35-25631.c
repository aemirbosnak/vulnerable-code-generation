//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Ada Lovelace
/*
  Color Code Converter Program in C
  Written by [Your Name]

  This program converts RGB color values to hexadecimal and vice versa.

  To run the program, simply compile and execute:
  $ gcc color_converter.c -o color_converter
  $ ./color_converter
*/

#include <stdio.h>

int main() {
  int red, green, blue;
  char hex_color[7];

  printf("===== Color Code Converter =====\n\n");

  // RGB to Hexadecimal
  printf("RGB to Hexadecimal:\n");

  printf("Enter Red value (0-255): ");
  scanf("%d", &red);

  printf("Enter Green value (0-255): ");
  scanf("%d", &green);

  printf("Enter Blue value (0-255): ");
  scanf("%d", &blue);

  // Convert RGB to Hexadecimal
  sprintf(hex_color, "#%02x%02x%02x", red, green, blue);

  printf("Hexadecimal color: %s\n\n", hex_color);

  // Hexadecimal to RGB
  printf("Hexadecimal to RGB:\n");

  printf("Enter Hexadecimal color code (e.g. #ff00ff): ");
  scanf("%s", hex_color);

  // Convert Hexadecimal to RGB
  sscanf(hex_color, "#%02x%02x%02x", &red, &green, &blue);

  printf("Red value: %d\n", red);
  printf("Green value: %d\n", green);
  printf("Blue value: %d\n", blue);

  return 0;
}