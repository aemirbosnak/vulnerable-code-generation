#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int unit_from, unit_to, value;

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &unit_from);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &unit_to);

  printf("Enter the value you want to convert: ");
  scanf("%d", &value);

  switch (unit_from) {
    case 1:
      switch (unit_to) {
        case 2:
          printf("%d centimeters are equal to %d meters.\n", value, value / 100);
          break;
        case 3:
          printf("%d centimeters are equal to %d kilometers.\n", value, value / 100000);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 2:
      switch (unit_to) {
        case 1:
          printf("%d meters are equal to %d centimeters.\n", value, value * 100);
          break;
        case 3:
          printf("%d meters are equal to %d kilometers.\n", value, value / 1000);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 3:
      switch (unit_to) {
        case 1:
          printf("%d kilometers are equal to %d centimeters.\n", value, value * 100000);
          break;
        case 2:
          printf("%d kilometers are equal to %d meters.\n", value, value * 1000);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    default:
      printf("Invalid unit conversion.\n");
      break;
  }

  return 0;
}
