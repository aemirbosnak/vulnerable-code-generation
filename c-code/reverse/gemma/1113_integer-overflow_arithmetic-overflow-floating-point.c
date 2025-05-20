#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void convert_temp(int choice) {
  float temp, conversion_factor;
  switch (choice) {
    case 1:
      conversion_factor = 1.8f;
      temp = (temp * conversion_factor) + 32.0f;
      printf("The converted temperature is: %.2f Fahrenheit.\n", temp);
      break;
    case 2:
      conversion_factor = 0.555556f;
      temp = (temp - 32.0f) * conversion_factor;
      printf("The converted temperature is: %.2f Celsius.\n", temp);
      break;
    default:
      printf("Invalid choice.\n");
  }
}

int main() {
  int choice;
  printf("Enter 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius: ");
  scanf("%d", &choice);
  convert_temp(choice);
  return 0;
}
