#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  int unit_type, result;

  printf("Enter unit type (m, kg, l, t, f, c): ");
  scanf("%d", &unit_type);

  switch (unit_type) {
    case 1:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 1000;
      printf("Converted value: %.2f kg\n", b);
      break;
    case 2:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 2.2046;
      printf("Converted value: %.2f lb\n", b);
      break;
    case 3:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 1000;
      printf("Converted value: %.2f l\n", b);
      break;
    case 4:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 1000;
      printf("Converted value: %.2f t\n", b);
      break;
    case 5:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 3.2808;
      printf("Converted value: %.2f fl\n", b);
      break;
    case 6:
      printf("Enter value: ");
      scanf("%f", &a);
      b = a * 1.8022;
      printf("Converted value: %.2f °C\n", b);
      break;
  }

  return 0;
}
