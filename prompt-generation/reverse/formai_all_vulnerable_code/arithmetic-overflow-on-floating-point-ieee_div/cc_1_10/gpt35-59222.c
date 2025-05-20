//FormAI DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>

int main() {

  // Introduction
  printf("\nWelcome to the C Color Code Converter!\n\n");

  // Ask user for input
  printf("Please enter a color code in Hexadecimal format (e.g. #FF5733): ");
  char hexCode[8];
  scanf("%s", hexCode);

  // Convert Hexadecimal to RGB
  int r, g, b;
  sscanf(hexCode, "#%02x%02x%02x", &r, &g, &b);

  // Display RGB values
  printf("\nRGB values for %s:\n", hexCode);
  printf("Red: %d\n", r);
  printf("Green: %d\n", g);
  printf("Blue: %d\n", b);

  // Convert RGB to HSL
  double h, s, l;
  double rDecimal = r / 255.0;
  double gDecimal = g / 255.0;
  double bDecimal = b / 255.0;
  double max = fmax(fmax(rDecimal, gDecimal), bDecimal);
  double min = fmin(fmin(rDecimal, gDecimal), bDecimal);
  double delta = max - min;

  if (delta == 0) {
    h = 0;
  } else if (max == rDecimal) {
    h = fmod((gDecimal - bDecimal) / delta, 6);
  } else if (max == gDecimal) {
    h = (bDecimal - rDecimal) / delta + 2;
  } else {
    h = (rDecimal - gDecimal) / delta + 4;
  }

  h = h * 60;
  if (h < 0) {
    h += 360;
  }

  l = (max + min) / 2;

  if (delta == 0) {
    s = 0;
  } else {
    s = delta / (1 - fabs(2 * l - 1));
  }

  // Display HSL values
  printf("\nHSL values for %s:\n", hexCode);
  printf("Hue: %g\n", h);
  printf("Saturation: %g\n", s);
  printf("Lightness: %g\n", l);

  // Exit message
  printf("\nThank you for using the C Color Code Converter!\n\n");

  return 0;
}