//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  char expression[100];
  double num1, num2, result;
  int operator;

  printf("Enter an expression in the format num1 operator num2: ");
  scanf("%s", expression);

  // Check for invalid input
  if (strlen(expression) < 6) {
    printf("Invalid input. Please enter an expression in the format num1 operator num2.\n");
    return 1;
  }

  // Split expression into two parts
  char* token = strtok(expression, " ");
  num1 = atof(token);
  operator = token[strlen(token)-1];
  token = strtok(NULL, " ");
  num2 = atof(token);

  // Perform calculation based on operator
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
        printf("Error: Division by zero.\n");
        return 1;
      }
      result = num1 / num2;
      break;
    case '^':
      result = pow(num1, num2);
      break;
    default:
      printf("Invalid operator. Please use one of the following: +, -, *, /, ^.\n");
      return 1;
  }

  // Print result
  printf("Result: %.2f\n", result);

  return 0;
}