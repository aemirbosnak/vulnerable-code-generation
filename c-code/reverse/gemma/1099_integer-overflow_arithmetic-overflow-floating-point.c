#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

void rgb_to_CMYK(int r, int g, int b) {
  int c = (255 - r) * 3 / 255;
  int m = (255 - g) * 3 / 255;
  int y = (255 - b) * 3 / 255;
  printf("CMYK: %d, %d, %d, %d\n", c, m, y, 255 - c - m - y);
}

void cmyk_to_rgb(int c, int m, int y, int k) {
  int r = 255 - (c * 255) / 3;
  int g = 255 - (m * 255) / 3;
  int b = 255 - (y * 255) / 3 - k * 255;
  printf("RGB: %d, %d, %d\n", r, g, b);
}

int main() {
  int r, g, b, c, m, y, k;

  printf("Enter RGB values (r, g, b): ");
  scanf("%d %d %d", &r, &g, &b);

  rgb_to_CMYK(r, g, b);

  printf("Enter CMYK values (c, m, y, k): ");
  scanf("%d %d %d %d", &c, &m, &y, &k);

  cmyk_to_rgb(c, m, y, k);

  return 0;
}
