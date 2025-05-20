//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

int main() {
  printf("\n\n                                 .---.  .--.    _____ ______  .---.     \n");
  printf("                                ( __\\ \\( (__)  / ___//  __  \\( __\\ \\    \n");
  printf("                                / __\\ \\ )    ( (   \\(  /_|  | / __\\ \\   \n");
  printf("                               / /___\ /      \\ \\___(  _)   / / /___\ \\  \n");
  printf("                              / /_____(        \\____/\__/   / /_____(  \\ \n");
  printf("                             ( (____(        |   |       ( (____(   ) )\n");
  printf("                             (_______)        |___|        (_______) (__) \n\n");
  printf("==========================================================================\n\n");

  // Declare the variables
  float celsius, fahrenheit, kelvin;
  int choice;

  // Display the menu
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("3. Convert Celsius to Kelvin\n");
  printf("4. Convert Kelvin to Celsius\n");
  printf("5. Convert Fahrenheit to Kelvin\n");
  printf("6. Convert Kelvin to Fahrenheit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the conversion based on the user's choice
  switch (choice) {
    case 1:
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      fahrenheit = celsius * 9 / 5 + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
      break;
    case 2:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2f\n", celsius);
      break;
    case 3:
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      kelvin = celsius + 273.15;
      printf("The temperature in Kelvin is: %.2f\n", kelvin);
      break;
    case 4:
      printf("Enter the temperature in Kelvin: ");
      scanf("%f", &kelvin);
      celsius = kelvin - 273.15;
      printf("The temperature in Celsius is: %.2f\n", celsius);
      break;
    case 5:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
      printf("The temperature in Kelvin is: %.2f\n", kelvin);
      break;
    case 6:
      printf("Enter the temperature in Kelvin: ");
      scanf("%f", &kelvin);
      fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}