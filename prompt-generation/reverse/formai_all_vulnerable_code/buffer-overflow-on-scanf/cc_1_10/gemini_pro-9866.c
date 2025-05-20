//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the function to convert a hex color code to RGB values
void hex_to_rgb(char *hex, int *r, int *g, int *b);

// Declare the function to convert RGB values to a hex color code
void rgb_to_hex(int r, int g, int b, char *hex);

int main() {
  // Declare the variables to store the hex color code and RGB values
  char hex[7];
  int r, g, b;

  // Get the hex color code from the user
  printf("Enter a hex color code (e.g., #FFFFFF): ");
  scanf("%s", hex);

  // Convert the hex color code to RGB values
  hex_to_rgb(hex, &r, &g, &b);

  // Print the RGB values
  printf("The RGB values of the hex color code %s are: %d, %d, %d\n", hex, r, g, b);

  // Convert the RGB values back to a hex color code
  rgb_to_hex(r, g, b, hex);

  // Print the hex color code
  printf("The hex color code of the RGB values %d, %d, %d is: %s\n", r, g, b, hex);

  return 0;
}

// Function to convert a hex color code to RGB values
void hex_to_rgb(char *hex, int *r, int *g, int *b) {
  // Check if the hex color code is valid
  if (strlen(hex) != 7 || hex[0] != '#') {
    printf("Invalid hex color code: %s\n", hex);
    exit(1);
  }

  // Convert the hex color code to RGB values
  *r = (hex[1] - '0') * 16 + (hex[2] - '0');
  *g = (hex[3] - '0') * 16 + (hex[4] - '0');
  *b = (hex[5] - '0') * 16 + (hex[6] - '0');
}

// Function to convert RGB values to a hex color code
void rgb_to_hex(int r, int g, int b, char *hex) {
  // Check if the RGB values are valid
  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
    printf("Invalid RGB values: %d, %d, %d\n", r, g, b);
    exit(1);
  }

  // Convert the RGB values to a hex color code
  sprintf(hex, "#%02X%02X%02X", r, g, b);
}