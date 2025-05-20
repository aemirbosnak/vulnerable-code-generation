//Gemma-7B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, quotient;
  char letter;

  printf("Welcome to the vintage calculator!\n");
  printf("Please enter two numbers: ");

  // Error handling for invalid numeric input
  if (!scanf("%d %d", &num1, &num2) || num1 < 0 || num2 < 0) {
    printf("Error: Invalid input. Please try again.\n");
    return 1;
  }

  // Error handling for division by zero
  if (num2 == 0) {
    printf("Error: Division by zero is not allowed.\n");
    return 1;
  }

  // Calculate the quotient
  quotient = num1 / num2;

  // Error handling for overflow
  if (quotient > 10) {
    printf("Error: Overflow. The result is too large.\n");
    return 1;
  }

  // Display the result
  printf("The quotient is: %d\n", quotient);

  // Error handling for invalid character input
  if (scanf("%c", &letter) != 1) {
    printf("Error: Invalid input. Please try again.\n");
    return 1;
  }

  // Check if the character is a letter
  if (!((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))) {
    printf("Error: Invalid character input. Please try again.\n");
    return 1;
  }

  // Print a message
  printf("Thank you for using the vintage calculator! Please enjoy your day.\n");

  return 0;
}