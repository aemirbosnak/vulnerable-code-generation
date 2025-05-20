//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int num1, num2;
  char operator;
  int result;

  // Get user input for the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Get user input for the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Get user input for the arithmetic operator
  printf("Enter the arithmetic operator (+, -, *, /): ");
  scanf(" %c", &operator);

  // Perform arithmetic operation based on operator
  switch (operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
      }
      result = num1 / num2;
      break;
    default:
      printf("Error: Invalid operator.\n");
      exit(1);
  }

  // Print the result of the arithmetic operation
  printf("The result is: %d\n", result);

  return 0;
}