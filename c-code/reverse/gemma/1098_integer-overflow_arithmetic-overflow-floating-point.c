#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float r, g, b, c, m, y;

  printf("Enter RGB values (r, g, b): ");
  scanf("%f %f %f", &r, &g, &b);

  c = (r - 105.0) * 2.42 / 255.0 + 100.0;
  m = (g - 105.0) * 2.42 / 255.0 + 100.0;
  y = (b - 105.0) * 2.42 / 255.0 + 100.0;

  printf("Converted CMYK values (c, m, y): ");
  printf("%f, %f, %f\n", c, m, y);

  return 0;
}
