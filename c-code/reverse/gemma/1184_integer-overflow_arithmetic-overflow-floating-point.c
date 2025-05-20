#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
  int meters = INT_MAX / 1000;
  int kilometers = meters / 1000;
  int centimeters = (meters % 1000) * 10;
  int millimeters = (meters % 1000) * 100;
  int feet = meters * 3.28084;
  int inches = (meters * 3.28084) * 12;

  printf("Maximum meters: %d\n", meters);
  printf("Maximum kilometers: %d\n", kilometers);
  printf("Maximum centimeters: %d\n", centimeters);
  printf("Maximum millimeters: %d\n", millimeters);
  printf("Maximum feet: %d\n", feet);
  printf("Maximum inches: %d\n", inches);

  return 0;
}
