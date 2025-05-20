//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: romantic
/*
 * A romantic temperature monitor program
 *
 * Author: [Your Name]
 */

#include <stdio.h>

int main() {
  float temperature;
  char unit;
  char choice;

  printf("Welcome to the temperature monitor program! 😍\n");
  printf("Enter the current temperature (in Celsius or Fahrenheit): ");
  scanf("%f%c", &temperature, &unit);

  if (unit == 'C' || unit == 'c') {
    printf("Your current temperature is %f°C\n", temperature);
  } else if (unit == 'F' || unit == 'f') {
    printf("Your current temperature is %f°F\n", temperature);
  } else {
    printf("Invalid unit entered. Exiting program...\n");
    return 1;
  }

  printf("Do you want to enter another temperature reading? (y/n): ");
  scanf(" %c", &choice);

  while (choice == 'y' || choice == 'Y') {
    printf("Enter the current temperature (in Celsius or Fahrenheit): ");
    scanf("%f%c", &temperature, &unit);

    if (unit == 'C' || unit == 'c') {
      printf("Your current temperature is %f°C\n", temperature);
    } else if (unit == 'F' || unit == 'f') {
      printf("Your current temperature is %f°F\n", temperature);
    } else {
      printf("Invalid unit entered. Exiting program...\n");
      return 1;
    }

    printf("Do you want to enter another temperature reading? (y/n): ");
    scanf(" %c", &choice);
  }

  printf("Thank you for using the temperature monitor program! 😍\n");

  return 0;
}