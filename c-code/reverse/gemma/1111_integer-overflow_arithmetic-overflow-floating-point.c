#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define GALACTIC_TO_CELSIUS_FACTOR 1.8
#define CELSIUS_TO_GALACTIC_FACTOR 0.555556

int main() {
  int choice, temperature, conversion_type;
  float converted_temperature;

  while (1) {
    printf("Enter 1 for Celsius to Galactic conversion, 2 for Galactic to Celsius conversion: ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("Enter the temperature in Celsius: ");
      scanf("%d", &temperature);
      converted_temperature = (float) (temperature * GALACTIC_TO_CELSIUS_FACTOR);
      printf("The converted temperature is: %.2f Galactic\n", converted_temperature);
    } else if (choice == 2) {
      printf("Enter the temperature in Galactic: ");
      scanf("%d", &temperature);
      converted_temperature = (float) (temperature * CELSIUS_TO_GALACTIC_FACTOR);
      printf("The converted temperature is: %.2f Celsius\n", converted_temperature);
    } else {
      printf("Invalid choice. Please try again.\n");
    }

    printf("Do you want to continue converting? (Y/N): ");
    char continue_choice;
    scanf(" %c", &continue_choice);

    if (continue_choice == 'N') {
      break;
    }
  }

  return 0;
}
