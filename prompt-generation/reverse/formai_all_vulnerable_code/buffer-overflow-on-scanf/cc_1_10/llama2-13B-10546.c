//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Definition of the recursive function
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int choice, n;

  // Welcome message
  printf("Welcome to the Factorial Calculator!\n");

  // Main menu
  printf("Choose an option:\n");
  printf("1. Calculate the factorial of a given number\n");
  printf("2. Quit the program\n");

  // Get the user's input
  scanf("%d", &choice);

  // Validate the user's input
  if (choice < 1 || choice > 2) {
    printf("Invalid input. Please try again.\n");
    return 1;
  }

  // Calculate the factorial of a given number
  if (choice == 1) {
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the factorial
    int result = factorial(n);

    // Print the result
    printf("The factorial of %d is %d\n", n, result);
  }

  // Quit the program
  if (choice == 2) {
    printf("Goodbye!");
    return 0;
  }

  return 1;
}