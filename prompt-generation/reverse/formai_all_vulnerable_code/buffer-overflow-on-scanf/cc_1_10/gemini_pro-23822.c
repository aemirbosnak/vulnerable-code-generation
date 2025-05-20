//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a color code to RGB values
void colorCodeToRGB(char *colorCode, int *r, int *g, int *b) {
  int i;
  char *hexDigits = "0123456789ABCDEF";

  // Check if the color code is valid
  if (strlen(colorCode) != 7 || colorCode[0] != '#') {
    printf("Invalid color code: %s\n", colorCode);
    return;
  }

  // Convert the hex digits to integers
  for (i = 1; i < 7; i += 2) {
    int digit1 = strchr(hexDigits, colorCode[i]) - hexDigits;
    int digit2 = strchr(hexDigits, colorCode[i + 1]) - hexDigits;
    *r = (*r << 4) | digit1;
    *g = (*g << 4) | digit2;
  }
}

// Function to convert RGB values to a color code
void RGBToColorCode(int r, int g, int b, char *colorCode) {
  int i;
  char *hexDigits = "0123456789ABCDEF";

  // Convert the RGB values to hex digits
  for (i = 0; i < 6; i += 2) {
    int digit1 = r & 0xF;
    int digit2 = g & 0xF;
    r >>= 4;
    g >>= 4;
    colorCode[i] = hexDigits[digit1];
    colorCode[i + 1] = hexDigits[digit2];
  }

  // Add the '#' prefix to the color code
  colorCode[6] = '\0';
}

// Main function
int main() {
  char colorCode[7];
  int r, g, b;

  // Get the color code from the user
  printf("Enter a color code in the format #RRGGBB: ");
  scanf("%s", colorCode);

  // Convert the color code to RGB values
  colorCodeToRGB(colorCode, &r, &g, &b);

  // Print the RGB values
  printf("Red: %d\n", r);
  printf("Green: %d\n", g);
  printf("Blue: %d\n", b);

  // Convert the RGB values back to a color code
  RGBToColorCode(r, g, b, colorCode);

  // Print the color code
  printf("Color code: %s\n", colorCode);

  return 0;
}