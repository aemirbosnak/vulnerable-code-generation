//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  if(scanf("%d", &num1) == 0) {
    printf("Error: Invalid input\n");
    return EXIT_FAILURE;
  }

  printf("Enter the operator (+, -, *, /): ");
  if(scanf(" %c", &operator) == 0) {
    printf("Error: Invalid input\n");
    return EXIT_FAILURE;
  }

  printf("Enter the second number: ");
  if(scanf("%d", &num2) == 0) {
    printf("Error: Invalid input\n");
    return EXIT_FAILURE;
  }

  switch(operator) {
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
      if(num2 == 0) {
        printf("Error: Cannot divide by zero\n");
        return EXIT_FAILURE;
      }
      result = num1 / num2;
      break;
    default:
      printf("Error: Invalid operator\n");
      return EXIT_FAILURE;
  }

  printf("%d %c %d = %d\n", num1, operator, num2, result);
  return EXIT_SUCCESS;
}