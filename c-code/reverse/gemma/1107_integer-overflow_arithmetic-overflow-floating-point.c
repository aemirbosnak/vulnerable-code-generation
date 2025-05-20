#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

#define KM_TO_M 1000
#define MI_TO_M 1609.344

double convert_length(double length, char unit) {
  switch (unit) {
    case 'm':
      return length;
    case 'km':
      return length * KM_TO_M;
    case 'mi':
      return length * MI_TO_M;
    default:
      return -1;
  }
}

int main() {
  double length;
  char unit;

  printf("Enter the length: ");
  scanf("%lf", &length);

  printf("Enter the unit (m, km, mi): ");
  scanf(" %c", &unit);

  double converted_length = convert_length(length, unit);

  if (converted_length != -1) {
    printf("Converted length: %.2lf %s\n", converted_length, unit);
  } else {
    printf("Error: Invalid unit or calculation error.\n");
  }

  return 0;
}
