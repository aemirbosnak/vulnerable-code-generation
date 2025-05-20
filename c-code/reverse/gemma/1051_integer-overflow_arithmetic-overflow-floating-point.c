#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float m, kg, s, km, lb, min, converted_value;
  char unit_from, unit_to;

  printf("Enter the unit you want to convert from (m/kg/s): ");
  scanf("%c", &unit_from);

  printf("Enter the unit you want to convert to (km/lb/min): ");
  scanf("%c", &unit_to);

  switch (unit_from) {
    case 'm':
      printf("Enter the number of meters: ");
      scanf("%f", &m);
      converted_value = m * 1000;
      unit_to = 'km';
      break;
    case 'kg':
      printf("Enter the number of kilograms: ");
      scanf("%f", &kg);
      converted_value = kg * 2.2046;
      unit_to = 'lb';
      break;
    case 's':
      printf("Enter the number of seconds: ");
      scanf("%f", &s);
      converted_value = s * 60;
      unit_to = 'min';
      break;
  }

  switch (unit_to) {
    case 'km':
      converted_value = converted_value / 1000;
      printf("The converted value is: %.2f kilometers.\n", converted_value);
      break;
    case 'lb':
      converted_value = converted_value / 2.2046;
      printf("The converted value is: %.2f pounds.\n", converted_value);
      break;
    case 'min':
      converted_value = converted_value / 60;
      printf("The converted value is: %.2f minutes.\n", converted_value);
      break;
  }

  return 0;
}
