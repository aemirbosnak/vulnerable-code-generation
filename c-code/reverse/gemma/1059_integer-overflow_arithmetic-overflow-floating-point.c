#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%f", &value);

  printf("Enter the unit you are converting from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit you are converting to: ");
  scanf(" %c", &unit_to);

  switch (unit_from) {
    case 'm':
      switch (unit_to) {
        case 'km':
          printf("%f km = %f m\n", value * 1000, value);
          break;
        case 'miles':
          printf("%f miles = %f m\n", value * 1609.34, value);
          break;
      }
      break;
    case 'kg':
      switch (unit_to) {
        case 't':
          printf("%f tons = %f kg\n", value * 1000, value);
          break;
        case 'lbs':
          printf("%f lbs = %f kg\n", value * 2.2046, value);
          break;
      }
      break;
    case 's':
      switch (unit_to) {
        case 'min':
          printf("%f minutes = %f seconds\n", value * 60, value);
          break;
        case 'hours':
          printf("%f hours = %f seconds\n", value * 3600, value);
          break;
      }
      break;
  }

  return 0;
}
