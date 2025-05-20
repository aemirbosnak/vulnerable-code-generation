//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>

int main() {
  float tempCelsius, tempFahrenheit;
  char choice;

  // Welcome message
  printf("Welcome to the Temperature Converter!\n");

  // Prompt the user to enter the temperature and its unit
  printf("Enter the temperature and its unit (C/F): ");
  scanf("%f %c", &tempCelsius, &choice);

  // Convert the temperature
  switch (choice) {
    case 'C':
      tempFahrenheit = (tempCelsius * 9 / 5) + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", tempFahrenheit);
      break;
    case 'F':
      tempCelsius = (tempFahrenheit - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2f\n", tempCelsius);
      break;
    default:
      printf("Invalid unit entered. Please enter C for Celsius or F for Fahrenheit.\n");
  }

  // Repeat the conversion or quit
  while (1) {
    printf("Do you want to convert another temperature? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
      printf("Enter the temperature and its unit (C/F): ");
      scanf("%f %c", &tempCelsius, &choice);

      switch (choice) {
        case 'C':
          tempFahrenheit = (tempCelsius * 9 / 5) + 32;
          printf("The temperature in Fahrenheit is: %.2f\n", tempFahrenheit);
          break;
        case 'F':
          tempCelsius = (tempFahrenheit - 32) * 5 / 9;
          printf("The temperature in Celsius is: %.2f\n", tempCelsius);
          break;
        default:
          printf("Invalid unit entered. Please enter C for Celsius or F for Fahrenheit.\n");
      }
    } else if (choice == 'N' || choice == 'n') {
      printf("Thank you for using the Temperature Converter!\n");
      break;
    } else {
      printf("Invalid choice entered. Please enter Y for Yes or N for No.\n");
    }
  }

  return 0;
}