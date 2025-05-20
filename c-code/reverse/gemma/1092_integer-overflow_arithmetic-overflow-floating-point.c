#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int r, g, b, c, m, y;

  printf("Enter RGB values (r, g, b): ");
  scanf("%d %d %d", &r, &g, &b);

  c = (255 - r) * 3 / 255;
  m = (255 - r - g) * 3 / 255;
  y = (255 - r - g - b) * 3 / 255;

  printf("Converted CMYK values (c, m, y): ");
  printf("%d, %d, %d\n", c, m, y);

  return 0;
}
