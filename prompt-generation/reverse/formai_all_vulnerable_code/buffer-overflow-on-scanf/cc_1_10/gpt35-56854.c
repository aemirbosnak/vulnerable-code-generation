//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
  char input[10];
  printf("Enter the color code (e.g. #F08080): ");
  scanf("%s", input);

  int r, g, b;
  sscanf(input, "#%02x%02x%02x", &r, &g, &b);

  printf("\nColor Code Entered: %s", input);
  printf("\nRed: %d", r);
  printf("\nGreen: %d", g);
  printf("\nBlue: %d", b);
  
  //Convert RGB to HSL
  float h = 0, s = 0, l = 0;

  float red = r / 255.0;
  float green = g / 255.0;
  float blue = b / 255.0;

  float min = fmin(fmin(red, green), blue);
  float max = fmax(fmax(red, green), blue);

  if (max == min) {
    h = 0;
  } else if (max == red && green >= blue) {
    h = 60 * ((green - blue) / (max - min));
  } else if (max == red && green < blue) {
    h = 60 * ((green - blue) / (max - min)) + 360;
  } else if (max == green) {
    h = 60 * ((blue - red) / (max - min)) + 120;
  } else if (max == blue) {
    h = 60 * ((red - green) / (max - min)) + 240;
  }

  l = (max + min) / 2;

  if (max == min) {
    s = 0;
  } else if (l <= 0.5) {
    s = (max - min) / (max + min);
  } else {
    s = (max - min) / (2 - max - min);
  }

  printf("\nHSL Color Code: ");
  printf("\nHue: %.2f", h);
  printf("\nSaturation: %.2f", s);
  printf("\nLightness: %.2f", l);

  return 0;
}