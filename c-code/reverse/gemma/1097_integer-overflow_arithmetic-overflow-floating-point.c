#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

void rgb_to_CMYK(float r, float g, float b) {
  float cmy = (r - g - b) / (r + g + b);
  float m = (r + g + b - cmy) / 2;
  printf("CMYK: %.2f, %.2f, %.2f, %.2f\n", cmy, m, (r - cmy) / 2, (g - cmy) / 2);
}

void cmy_to_rgb(float c, float m, float y) {
  float r = (255 - (c * 255)) + (m * 255) / 2;
  float g = (255 - (c * 255)) + (m * 255) / 2;
  float b = 255 - r - g;
  printf("RGB: %.2f, %.2f, %.2f\n", r, g, b);
}

int main() {
  float r, g, b, c, m, y;

  printf("Enter RGB values (separated by commas): ");
  scanf("%f, %f, %f", &r, &g, &b);

  rgb_to_CMYK(r, g, b);

  printf("Enter CMYK values (separated by commas): ");
  scanf("%f, %f, %f, %f", &c, &m, &y);

  cmy_to_rgb(c, m, y);

  return 0;
}
