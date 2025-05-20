//Falcon-180B DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int num1, num2;
  char operator;
  bool valid_operator = false;

  // Prompt user for two numbers and an operator
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  // Validate operator input
  switch (operator) {
    case '+':
      valid_operator = true;
      break;
    case '-':
      valid_operator = true;
      break;
    case '*':
      valid_operator = true;
      break;
    case '/':
      valid_operator = true;
      break;
    default:
      printf("Invalid operator.\n");
      return 1;
  }

  // Perform calculation based on operator input
  switch (operator) {
    case '+':
      printf("The result is: %d\n", num1 + num2);
      break;
    case '-':
      printf("The result is: %d\n", num1 - num2);
      break;
    case '*':
      printf("The result is: %d\n", num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Cannot divide by zero.\n");
        return 1;
      } else {
        printf("The result is: %d\n", num1 / num2);
      }
      break;
    default:
      printf("Invalid operator.\n");
      return 1;
  }

  return 0;
}