//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
  double d_value;
  char unit_from, unit_to;

  printf("Enter the value and units: ");
  scanf("%lf %c %c", &d_value, &unit_from, &unit_to);

  switch (unit_from) {
    case 'm':
      switch (unit_to) {
        case 'kg':
          d_value *= 1000;
          break;
        case 'g':
          d_value *= 1000;
          break;
        case 't':
          d_value *= 1000000;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 'kg':
      switch (unit_to) {
        case 'm':
          d_value /= 1000;
          break;
        case 'g':
          d_value /= 1000;
          break;
        case 't':
          d_value /= 1000000;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 'g':
      switch (unit_to) {
        case 'm':
          d_value /= 1000;
          break;
        case 'kg':
          d_value /= 1000;
          break;
        case 't':
          d_value /= 1000000;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 't':
      switch (unit_to) {
        case 'm':
          d_value *= 1000;
          break;
        case 'kg':
          d_value *= 1000000;
          break;
        case 'g':
          d_value *= 1000000;
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

  printf("The converted value is: %.2lf %s.\n", d_value, unit_to);

  return 0;
}