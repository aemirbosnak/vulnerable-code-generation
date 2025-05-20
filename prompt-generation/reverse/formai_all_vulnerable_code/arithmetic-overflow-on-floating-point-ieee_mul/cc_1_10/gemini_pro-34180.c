//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>

// Watson, I have devised a contraption that will convert temperatures between Celsius and Fahrenheit.

int main() {
  // Declare our variables, my dear Watson.
  float celsius, fahrenheit;
  int choice;

  // Greet our user, Dr. Watson.
  printf("Greetings, Dr. Watson! I am pleased to present my temperature converter.\n");

  // Present our options to the user.
  do {
    printf("Please select an option, Dr. Watson:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    // Convert Celsius to Fahrenheit.
    if (choice == 1) {
      printf("Enter the temperature in Celsius, Dr. Watson:\n");
      scanf("%f", &celsius);
      fahrenheit = (celsius * 9 / 5) + 32;
      printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
    }

    // Convert Fahrenheit to Celsius.
    else if (choice == 2) {
      printf("Enter the temperature in Fahrenheit, Dr. Watson:\n");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2f\n", celsius);
    }

    // Exit the program.
    else if (choice == 3) {
      printf("Thank you for using my temperature converter, Dr. Watson. Farewell!\n");
      return 0;
    }

    // Handle invalid input.
    else {
      printf("Invalid option, Dr. Watson. Please try again.\n");
    }

  } while (choice != 3);

  return 0;
}