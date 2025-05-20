#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float r, g, b, y, k;
  printf("Enter RGB values (r, g, b): ");
  scanf("%f %f %f", &r, &g, &b);

  // Convert RGB to CMYK
  y = (r * 0.333333) + (g * 0.5) + (b * 0.166666);
  k = 255 - (y * 1.5) - (r * 0.333333) - (g * 0.5) - (b * 0.166666);

  // Overflow vulnerability: intentionally allow inputs that exceed the maximum representable value of a float or int
  if (y > 255.0) {
    y = 255.0;
  }
  if (k > 255.0) {
    k = 255.0;
  }

  printf("Converted CMYK values (y, k): ");
  printf("%f, %f\n", y, k);

  return 0;
}
