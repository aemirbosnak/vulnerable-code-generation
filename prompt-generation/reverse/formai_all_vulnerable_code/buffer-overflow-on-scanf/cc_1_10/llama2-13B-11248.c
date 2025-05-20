//LLAMA2-13B DATASET v1.0 Category: Game ; Style: calm
// This program calculates the factorial of a given number, with a twist!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define FACTORIAL_LIMIT 100000

// Function to calculate the factorial of a given number
int factorial(int n) {
  // If the input is 0, return 1
  if (n == 0) {
    return 1;
  }

  // If the input is 1, return 1
  if (n == 1) {
    return 1;
  }

  // Otherwise, calculate the factorial of n-1 and multiply by n
  int result = factorial(n - 1) * n;

  // Return the result
  return result;
}

// Function to print the factorial in a soothing manner
void print_factorial(int n) {
  // Calculate the factorial of n
  int result = factorial(n);

  // Print the result in a calm and soothing way
  printf("Ah, the factorial of %d is %d, a truly magnificent number, don't you agree?\n", n, result);
}

int main() {
  // Prompt the user for the input
  printf("Please enter a positive integer: ");

  // Read the input from the user
  int n;
  scanf("%d", &n);

  // Check if the input is valid
  if (n < 1 || n > FACTORIAL_LIMIT) {
    printf("Invalid input. Please try again.\n");
    return 1;
  }

  // Calculate and print the factorial
  print_factorial(n);

  // Wait for a moment to let the user appreciate the beauty of the factorial
  sleep(1);

  // Print a final message
  printf("The factorial of %d has been calculated. Goodbye, and may the math be with you!\n", n);

  return 0;
}