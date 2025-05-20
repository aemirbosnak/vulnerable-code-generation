#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int convert_temp(int, int);

int main() {
  int choice, celsius, galactic;
  printf("Enter 1 for Celsius to Galactic or 2 for Galactic to Celsius:\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the temperature in Celsius:");
      scanf("%d", &celsius);
      galactic = convert_temp(celsius, 0);
      printf("The temperature in Galactic is: %d\n", galactic);
      break;
    case 2:
      printf("Enter the temperature in Galactic:");
      scanf("%d", &galactic);
      celsius = convert_temp(galactic, 1);
      printf("The temperature in Celsius is: %d\n", celsius);
      break;
    default:
      printf("Invalid input.\n");
  }

  return 0;
}

int convert_temp(int temp, int direction) {
  int formula_result, converted_temp;

  formula_result = (temp * 2) + direction * 5;
  converted_temp = formula_result / 3;

  return converted_temp;
}
