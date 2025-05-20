//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
/*
 * Color Code Converter
 * Post-apocalyptic style
 */

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a color
typedef struct {
  int red;
  int green;
  int blue;
} Color;

// Define a function to convert a color code to a color struct
Color color_code_to_color(int code) {
  Color color;
  color.red = (code >> 16) & 0xFF;
  color.green = (code >> 8) & 0xFF;
  color.blue = code & 0xFF;
  return color;
}

// Define a function to convert a color struct to a color code
int color_to_color_code(Color color) {
  return (color.red << 16) | (color.green << 8) | color.blue;
}

int main(void) {
  // Ask the user to input a color code
  printf("Enter a color code in hexadecimal format (e.g. FF0000 for red): ");
  int code;
  scanf("%x", &code);

  // Convert the color code to a color struct
  Color color = color_code_to_color(code);

  // Print the color struct
  printf("Color code: %x\n", code);
  printf("Red: %d\n", color.red);
  printf("Green: %d\n", color.green);
  printf("Blue: %d\n", color.blue);

  // Convert the color struct back to a color code
  code = color_to_color_code(color);

  // Print the color code again
  printf("Color code: %x\n", code);

  return 0;
}