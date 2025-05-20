//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000
#define MAX_VALUE 1000

// A smart arithmetic program that can solve math problems and tell jokes
int main() {
  // Initialize variables
  int num1, num2, sum, diff, mult, div, mod;
  char op;
  char joke[MAX_LENGTH];

  // Ask the user for the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Ask the user for the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Ask the user for the operation
  printf("Enter the operation (+, -, *, /, or %): ");
  scanf(" %c", &op);

  // Perform the operation
  switch (op) {
    case '+':
      sum = num1 + num2;
      break;
    case '-':
      diff = num1 - num2;
      break;
    case '*':
      mult = num1 * num2;
      break;
    case '/':
      div = num1 / num2;
      break;
    case '%':
      mod = num1 % num2;
      break;
    default:
      printf("Invalid operation. Please try again.");
      return 1;
  }

  // Print the result and a joke
  printf("Result: %d\n", sum);
  printf("Joke: %s\n", joke);

  // Generate a joke
  sprintf(joke, "Why did the math book look so sad? Because it had too many problems. But don't worry, I'm here to help you solve them!");

  // Give the user a chance to try again
  printf("Want to try again? (y/n): ");
  scanf(" %c", &op);

  return 0;
}