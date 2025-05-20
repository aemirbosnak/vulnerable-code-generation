#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char unit_in, unit_out;
  float weight, volume;

  printf("Enter the unit you want to convert from: ");
  scanf("%c", &unit_in);

  switch (unit_in) {
    case 'k':
    case 'g':
      printf("Enter the weight in kilograms: ");
      scanf("%f", &weight);
      unit_out = 'm';
      volume = weight * 1000;
      break;
    case 'lb':
    case 'oz':
      printf("Enter the weight in pounds: ");
      scanf("%f", &weight);
      unit_out = 'kg';
      volume = weight * 2.2046;
      break;
    default:
      printf("Invalid unit input.\n");
      return 1;
  }

  switch (unit_out) {
    case 'm':
      printf("The converted weight is: %.2f meters.\n", volume);
      break;
    case 'kg':
      printf("The converted weight is: %.2f kilograms.\n", volume);
      break;
    default:
      printf("Invalid unit conversion.\n");
      return 1;
  }

  return 0;
}
