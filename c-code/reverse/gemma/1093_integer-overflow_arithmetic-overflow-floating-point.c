#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

void rgb_to_CMYK(float r, float g, float b) {
  float cmy = (r - g - b) / (r + g + b);
  float m = (r + g + b) - cmy * (r + g + b);
  printf("CMYK: %.2f, %.2f, %.2f, %.2f\n", cmy, m, (r - cmy * r) / m, (g - cmy * g) / m);
}

void cmy_to_rgb(float c, float m, float y) {
  float r = (m * (c / 255.0) + y) * 2.55f;
  float g = (m * (c / 255.0) + y) * 2.55f;
  float b = (m * (c / 255.0) + y) * 2.55f - r - g;
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
