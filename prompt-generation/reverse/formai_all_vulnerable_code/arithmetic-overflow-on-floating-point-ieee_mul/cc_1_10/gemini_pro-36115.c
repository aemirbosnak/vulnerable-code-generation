//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  float fahrenheit, celsius;
  int choice;

  // Display a menu
  printf("*****  Unit Converter  *****\n\n");
  printf("1. Fahrenheit to Celsius\n");
  printf("2. Celsius to Fahrenheit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the conversion based on the user's choice
  switch (choice) {
    case 1:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
      break;
    case 2:
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      fahrenheit = (celsius * 9 / 5) + 32;
      printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
      break;
    default:
      printf("Invalid choice. Please enter 1 or 2.\n");
  }

  // Prompt the user to continue or exit
  printf("Do you want to continue? (y/n): ");
  char answer;
  scanf(" %c", &answer);

  // Continue or exit the program based on the user's input
  if (answer == 'y' || answer == 'Y') {
    printf("Restarting the program...\n\n");
    main();
  } else if (answer == 'n' || answer == 'N') {
    printf("Exiting the program...\n");
    return 0;
  } else {
    printf("Invalid input. Please enter 'y' or 'n'.\n");
    main();
  }

  return 0;
}