#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float length, original_length, conversion_factor;
  char unit, target_unit;

  printf("Enter the original length: ");
  scanf("%f", &original_length);

  printf("Enter the original unit (m, km, mi, etc.): ");
  scanf("%c", &unit);

  printf("Enter the target unit (m, km, mi, etc.): ");
  scanf("%c", &target_unit);

  switch (unit) {
    case 'm':
      conversion_factor = 1;
      break;
    case 'km':
      conversion_factor = 1000;
      break;
    case 'mi':
      conversion_factor = 1609.34;
      break;
    default:
      printf("Invalid unit.\n");
      return 1;
  }

  switch (target_unit) {
    case 'm':
      length = original_length * conversion_factor;
      printf("The converted length is: %.2f meters.\n", length);
      break;
    case 'km':
      length = original_length * conversion_factor / 1000;
      printf("The converted length is: %.2f kilometers.\n", length);
      break;
    case 'mi':
      length = original_length * conversion_factor / 1609.34;
      printf("The converted length is: %.2f miles.\n", length);
      break;
    default:
      printf("Invalid target unit.\n");
      return 1;
  }

  return 0;
}
