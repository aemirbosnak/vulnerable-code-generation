//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int from, int to, float value) {
  switch (from) {
    case 0:
      switch (to) {
        case 0:
          printf("Same units, value unchanged: %.2f", value);
          break;
        case 1:
          printf("Converted to liters: %.2f", value * 1000);
          break;
        case 2:
          printf("Converted to gallons: %.2f", value * 3.785);
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    case 1:
      switch (to) {
        case 0:
          printf("Converted to cubic meters: %.2f", value / 1000);
          break;
        case 1:
          printf("Same units, value unchanged: %.2f", value);
          break;
        case 2:
          printf("Converted to cubic gallons: %.2f", value * 3.785);
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    case 2:
      switch (to) {
        case 0:
          printf("Converted to liters: %.2f", value * 1000);
          break;
        case 1:
          printf("Converted to cubic meters: %.2f", value * 1000);
          break;
        case 2:
          printf("Same units, value unchanged: %.2f", value);
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    default:
      printf("Invalid conversion");
      break;
  }
}

int main() {
  float value;
  int from, to;

  printf("Enter the value: ");
  scanf("%f", &value);

  printf("Enter the conversion from: ");
  scanf("%d", &from);

  printf("Enter the conversion to: ");
  scanf("%d", &to);

  unit_converter(from, to, value);

  return 0;
}