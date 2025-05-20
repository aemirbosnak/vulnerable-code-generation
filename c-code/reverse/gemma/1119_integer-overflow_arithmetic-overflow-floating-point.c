#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void convert_temp(int choice, float temp) {
  switch (choice) {
    case 1:
      float f_temp = (temp * 1.8) + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", f_temp);
      break;
    case 2:
      float c_temp = (temp - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2f\n", c_temp);
      break;
    default:
      printf("Invalid choice.\n");
  }
}

int main() {
  int choice;
  float temp;

  printf("Enter the temperature: ");
  scanf("%f", &temp);

  printf("Select an option:\n");
  printf("1. Convert to Fahrenheit\n");
  printf("2. Convert to Celsius\n");
  scanf("%d", &choice);

  convert_temp(choice, temp);

  return 0;
}
