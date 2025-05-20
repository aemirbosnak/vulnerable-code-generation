//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Function to calculate factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate Fibonacci series
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int choice, n;

  // Menu to select operation
  printf("Welcome to Arithmetic Land! Please select an operation:\n");
  printf("1. Calculate Factorial\n");
  printf("2. Calculate Fibonacci Series\n");
  printf("3. Quit\n");
  scanf("%d", &choice);

  // Handle user input
  switch (choice) {
    case 1:
      // Calculate factorial of a given number
      printf("Enter a positive integer: ");
      scanf("%d", &n);
      printf("The factorial of %d is %d\n", n, factorial(n));
      break;
    case 2:
      // Calculate Fibonacci series of a given number
      printf("Enter a positive integer: ");
      scanf("%d", &n);
      printf("The Fibonacci series of %d is: ", n);
      for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
      }
      printf("\n");
      break;
    case 3:
      // Exit program
      printf("Goodbye! \n");
      return 0;
      break;
    default:
      printf("Invalid input. Please try again.\n");
      break;
  }

  return 0;
}