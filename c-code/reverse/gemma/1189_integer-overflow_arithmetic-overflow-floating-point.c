#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  float value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%f", &value);

  printf("Enter the unit you are converting from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit you are converting to: ");
  scanf(" %c", &unit_to);

  if (unit_from == 'm' && unit_to == 'km') {
    printf("%f km = %f m\n", value, value * 1000);
  } else if (unit_from == 'm' && unit_to == 'cm') {
    printf("%f cm = %f m\n", value, value * 100);
  } else if (unit_from == 'm' && unit_to == 'mm') {
    printf("%f mm = %f m\n", value, value * 1000);
  } else if (unit_from == 'f' && unit_to == 'm') {
    printf("%f m = %f ft\n", value, value * 3.28);
  } else if (unit_from == 'f' && unit_to == 'in') {
    printf("%f in = %f ft\n", value, value * 0.08333);
  } else {
    printf("Invalid conversion\n");
  }

  return 0;
}
