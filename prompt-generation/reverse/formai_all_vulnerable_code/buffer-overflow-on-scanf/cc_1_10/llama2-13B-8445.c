//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a recursive function to calculate the factorial of a given integer
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Define a recursive function to calculate the sum of the first n positive integers
int sum(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sum(n - 1);
  }
}

// Define a recursive function to calculate the product of the first n positive integers
int product(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * product(n - 1);
  }
}

int main() {
  int n, choice;

  // Ask the user to enter a choice (1 for factorial, 2 for sum, or 3 for product)
  printf("Enter your choice (1 for factorial, 2 for sum, or 3 for product): ");
  scanf("%d", &choice);

  // Based on the user's choice, call the appropriate recursive function
  switch (choice) {
    case 1:
      // Calculate and print the factorial of a given integer
      printf("Factorial of 5: ");
      n = 5;
      factorial(n);
      break;

    case 2:
      // Calculate and print the sum of the first n positive integers
      printf("Sum of first 10 positive integers: ");
      n = 10;
      sum(n);
      break;

    case 3:
      // Calculate and print the product of the first n positive integers
      printf("Product of first 10 positive integers: ");
      n = 10;
      product(n);
      break;

    default:
      printf("Invalid choice. Please enter a valid choice (1, 2, or 3).\n");
      return 1;
  }

  return 0;
}