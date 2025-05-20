//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a recursive function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int choice, n;

  // Ask the user for their choice: 1 for the factorial of a number, 2 for the sum of a sequence, or 3 for the product of a list
  printf("Choose an option (1, 2, or 3): ");
  scanf("%d", &choice);

  // Based on the user's choice, perform the appropriate operation
  switch (choice) {
    case 1:
      // Ask the user for the number for which they want to calculate the factorial
      printf("Enter a positive integer: ");
      scanf("%d", &n);

      // Calculate and print the factorial of the given number using the recursive function
      printf("The factorial of %d is %d\n", n, factorial(n));
      break;

    case 2:
      // Calculate and print the sum of the first n natural numbers using a recursive function
      printf("The sum of the first %d natural numbers is %d\n", n, sum(n));
      break;

    case 3:
      // Calculate and print the product of the first n positive integers using a recursive function
      printf("The product of the first %d positive integers is %d\n", n, product(n));
      break;

    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }

  return 0;
}

// Recursive function to calculate the sum of the first n natural numbers
int sum(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sum(n - 1);
  }
}

// Recursive function to calculate the product of the first n positive integers
int product(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * product(n - 1);
  }
}