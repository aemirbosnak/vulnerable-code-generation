//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WACKY_NUMBER 42

int main() {
  int num1, num2, sum, diff, mult, div, mod;
  char op;

  printf("Welcome to the Wacky Arithmetic Adventure!\n");

  // Generate a random number
  srand(time(NULL));
  num1 = rand() % 100;
  num2 = rand() % 100;

  // Ask the user for an operation
  printf("Choose an operation (+, -, x, /, or %): ", NULL);
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
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the results
  printf("The result of %d + %d is %d\n", num1, num2, sum);
  printf("The result of %d - %d is %d\n", num1, num2, diff);
  printf("The result of %d * %d is %d\n", num1, num2, mult);
  printf("The result of %d / %d is %d\n", num1, num2, div);
  printf("The result of %d %d is %d\n", num1, num2, mod);

  // Check for Wacky Numbers
  if (num1 == WACKY_NUMBER || num2 == WACKY_NUMBER) {
    printf("Wacky Numbers detected! The result is %d\n", WACKY_NUMBER);
  }

  return 0;
}