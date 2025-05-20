//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  char operator;
  double num1, num2;
  double result;

  // Get user input
  printf("Enter an operator (+, -, *, /, %): ");
  scanf(" %c", &operator);
  printf("Enter two numbers: ");
  scanf(" %lf %lf", &num1, &num2);

  // Perform operation based on the operator
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
        printf("Error: Cannot divide by zero.\n");
        return 1;  // Error code
      } else {
        result = num1 / num2;
      }
      break;
    case '%':
      if ((int)num2 == 0) {
        printf("Error: Cannot perform modulus operation with zero.\n");
        return 1;  // Error code
      } else {
        result = (int)num1 % (int)num2;
      }
      break;
    default:
      printf("Error: Invalid operator.\n");
      return 1;  // Error code
  }

  // Print the result
  if (operator == '/') {
    printf("The result is: %.2lf\n", result);
  } else {
    printf("The result is: %.0lf\n", result);
  }

  return 0;
}