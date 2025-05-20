//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUMBER 100

int main() {
  int number_to_convert, source_unit, destination_unit;
  float conversion_factor;

  printf("Enter the number to be converted: ");
  scanf("%d", &number_to_convert);

  printf("Enter the source unit (e.g. kg, g, lb): ");
  scanf("%d", &source_unit);

  printf("Enter the destination unit (e.g. kg, g, lb): ");
  scanf("%d", &destination_unit);

  switch (source_unit) {
    case 1:  // kg
      switch (destination_unit) {
        case 2:  // g
          conversion_factor = 1000;
          break;
        case 3:  // lb
          conversion_factor = 2.2046;
          break;
      }
      break;
    case 2:  // g
      switch (destination_unit) {
        case 1:  // kg
          conversion_factor = 0.001;
          break;
        case 3:  // lb
          conversion_factor = 2.2046 / 1000;
          break;
      }
      break;
    case 3:  // lb
      switch (destination_unit) {
        case 1:  // kg
          conversion_factor = 0.45359;
          break;
        case 2:  // g
          conversion_factor = 1000 * 0.45359;
          break;
      }
      break;
  }

  conversion_factor = conversion_factor * number_to_convert;

  printf("The converted number is: %.2f %s", conversion_factor, destination_unit);

  return 0;
}