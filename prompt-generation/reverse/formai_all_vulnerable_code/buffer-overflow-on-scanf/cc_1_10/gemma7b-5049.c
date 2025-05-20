//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
  int from_unit, to_unit, value;
  float conversion_factor;

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &from_unit);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &to_unit);

  printf("Enter the value you want to convert: ");
  scanf("%d", &value);

  switch (from_unit) {
    case 1:
      switch (to_unit) {
        case 2:
          conversion_factor = 2.20;
          break;
        case 3:
          conversion_factor = 1.618;
          break;
        default:
          printf("Invalid conversion");
          exit(1);
      }
      break;
    case 2:
      switch (to_unit) {
        case 1:
          conversion_factor = 0.45359;
          break;
        case 3:
          conversion_factor = 1.618;
          break;
        default:
          printf("Invalid conversion");
          exit(1);
      }
      break;
    case 3:
      switch (to_unit) {
        case 1:
          conversion_factor = 1.618;
          break;
        case 2:
          conversion_factor = 0.625;
          break;
        default:
          printf("Invalid conversion");
          exit(1);
      }
      break;
    default:
      printf("Invalid unit");
      exit(1);
  }

  conversion_factor = (float) conversion_factor;
  value = (int) (value * conversion_factor);

  printf("The converted value is: %d", value);

  return 0;
}