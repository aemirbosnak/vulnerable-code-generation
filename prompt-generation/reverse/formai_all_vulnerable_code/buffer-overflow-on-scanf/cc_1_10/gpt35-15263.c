//FormAI DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>

int main() {
  int option;
  float conversion, value;
  char fromUnit[20], toUnit[20];

  // Displaying the options to user
  printf("Select an Option:\n");
  printf("1. Distance Conversion\n2. Temperature Conversion\n3. Weight Conversion\n");
  scanf("%d", &option);

  // Distance Conversion
  if (option == 1) {
    printf("Select an option:\n");
    printf("1. Miles to Kilometers\n2. Kilometers to Miles\n");
    scanf("%d", &option);

    // Miles to Kilometers Conversion
    if (option == 1) {
      printf("Enter value in Miles: ");
      scanf("%f", &value);
      conversion = value * 1.60934;
      printf("%.2f Miles = %.2f Kilometers\n", value, conversion);
    }

    // Kilometers to Miles Conversion
    else {
      printf("Enter value in Kilometers: ");
      scanf("%f", &value);
      conversion = value / 1.60934;
      printf("%.2f Kilometers = %.2f Miles\n", value, conversion);
    }
  }

  // Temperature Conversion
  else if (option == 2) {
    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &option);

    // Celsius to Fahrenheit Conversion
    if (option == 1) {
      printf("Enter value in Celsius: ");
      scanf("%f", &value);
      conversion = (value * 9/5) + 32;
      printf("%.2f Celsius = %.2f Fahrenheit\n", value, conversion);
    }

    // Fahrenheit to Celsius Conversion
    else {
      printf("Enter value in Fahrenheit: ");
      scanf("%f", &value);
      conversion = (value - 32) * 5/9;
      printf("%.2f Fahrenheit = %.2f Celsius\n", value, conversion);
    }
  }

  // Weight Conversion
  else if (option == 3) {
    printf("Select an option:\n");
    printf("1. Pounds to Kilograms\n2. Kilograms to Pounds\n");
    scanf("%d", &option);

    // Pounds to Kilograms Conversion
    if (option == 1) {
      printf("Enter value in Pounds: ");
      scanf("%f", &value);
      conversion = value * 0.453592;
      printf("%.2f Pounds = %.2f Kilograms\n", value, conversion);
    }

    // Kilograms to Pounds Conversion
    else {
      printf("Enter value in Kilograms: ");
      scanf("%f", &value);
      conversion = value / 0.453592;
      printf("%.2f Kilograms = %.2f Pounds\n", value, conversion);
    }
  }

  // Invalid Option
  else {
    printf("Invalid Option!\n");
  }

  return 0;
}