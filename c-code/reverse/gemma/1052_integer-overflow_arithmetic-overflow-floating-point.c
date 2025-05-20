#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float m, kg, s, miles, pounds, minutes;
  printf("Enter the unit you want to convert from: (m/kg/s) ");
  char unit_from;
  scanf("%c", &unit_from);

  printf("Enter the value you want to convert: ");
  float value;
  scanf("%f", &value);

  switch (unit_from) {
    case 'm':
      miles = value * 0.00621371;
      printf("The equivalent in miles is: %.2f miles\n", miles);
      break;
    case 'kg':
      pounds = value * 2.20462;
      printf("The equivalent in pounds is: %.2f pounds\n", pounds);
      break;
    case 's':
      minutes = value * 60;
      printf("The equivalent in minutes is: %.2f minutes\n", minutes);
      break;
    default:
      printf("Invalid unit.\n");
  }

  return 0;
}
