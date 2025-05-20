#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float m, kg, s, km, lb, min;
  printf("Enter the unit you want to convert from (m/kg/s): ");
  scanf("%f", &m);
  kg = m * 1000;
  s = m * 3.6;
  km = m * 1000;
  lb = kg * 2.20462;
  min = s / 60;

  printf("The conversion is:\n");
  printf("  - Meters to Kilograms: %.2f kg\n", kg);
  printf("  - Meters to Seconds: %.2f seconds\n", s);
  printf("  - Meters to Kilometers: %.2f km\n", km);
  printf("  - Kilograms to Pounds: %.2f lb\n", lb);
  printf("  - Seconds to Minutes: %.2f minutes\n", min);

  return 0;
}
