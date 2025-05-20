#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

void rgb_to_cmy(float r, float g, float b, float *c, float *m, float *y, float *k) {
  *c = (1.0 - (r / 255.0) * 0.3333) * 255.0;
  *m = (1.0 - (g / 255.0) * 0.5) * 255.0;
  *y = (1.0 - (b / 255.0) * 0.1666) * 255.0;
  *k = 255.0 - (*c) - (*m) - (*y);
}

void cmy_to_rgb(float c, float m, float y, float k, float *r, float *g, float *b) {
  *r = (c / (255.0 - k)) * 255.0;
  *g = (m / (255.0 - k)) * 255.0;
  *b = (y / (255.0 - k)) * 255.0;
}

int main() {
  float r, g, b, c, m, y, k;

  printf("Enter RGB values (r, g, b): ");
  scanf("%f %f %f", &r, &g, &b);

  rgb_to_cmy(r, g, b, &c, &m, &y, &k);

  printf("Converted CMYK values (c, m, y, k): ");
  printf("%f, %f, %f, %f\n", c, m, y, k);

  return 0;
}
