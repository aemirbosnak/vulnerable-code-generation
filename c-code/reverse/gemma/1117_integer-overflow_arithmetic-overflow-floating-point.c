#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius, galactic;
  char unit;

  printf("Enter temperature: ");
  scanf("%f %c", &celsius, &unit);

  switch (unit) {
    case 'C':
      galactic = (celsius * 1.8) + 32;
      printf("Temperature in Galactic: %.2f\n", galactic);
      break;
    case 'G':
      galactic = (celsius - 32) * 1.8;
      printf("Temperature in Celsius: %.2f\n", celsius);
      break;
    default:
      printf("Invalid unit.\n");
  }

  return 0;
}
