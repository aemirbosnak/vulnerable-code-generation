#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, operator, result;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

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
        printf("Cannot divide by zero.\n");
      } else {
        result = num1 / num2;
      }
      break;
    default:
      printf("Invalid operator.\n");
  }

  if (result) {
    printf("The result is: %d\n", result);
  }

  return 0;
}
