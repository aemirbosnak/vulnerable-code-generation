//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>

int main() {
  // Declare variables
  int red, green, blue;

  printf("Enter the red, green, and blue color values separated by spaces: ");
  scanf("%d %d %d", &red, &green, &blue);

  // Convert RGB to HEX
  int hexValue = (red << 16) + (green << 8) + blue;
  printf("HEX code: #%06X\n", hexValue);

  // Convert RGB to HSL
  float r = red / 255.0;
  float g = green / 255.0;
  float b = blue / 255.0;

  float cmax = (r > g) ? r : g;
  if (b > cmax) {
    cmax = b;
  }

  float cmin = (r < g) ? r : g;
  if (b < cmin) {
    cmin = b;
  }

  float delta = cmax - cmin;

  float h = 0.0f;
  if (delta == 0) {
    h = 0.0f;
  } else if (cmax == r) {
    h = fmod((g - b) / delta, 6);
  } else if (cmax == g) {
    h = (b - r) / delta + 2;
  } else {
    h = (r - g) / delta + 4;
  }

  h = h * 60;
  if (h < 0.0f) {
    h = h + 360;
  }

  float l = (cmax + cmin) / 2.0;
  float s = (delta == 0) ? 0 : delta / (1 - fabs((2 * l) - 1));

  printf("HSL code: H:%.2f S:%.2f L:%.2f\n", h, s, l);

  return 0;
}