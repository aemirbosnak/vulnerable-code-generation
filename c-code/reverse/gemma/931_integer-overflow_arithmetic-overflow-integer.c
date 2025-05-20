#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char operator;
  float num1, num2, result;

  printf("Enter an expression: ");
  scanf("%f %c %f", &num1, &operator, &num2);

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
        printf("Cannot divide by zero\n");
      } else {
        result = num1 / num2;
      }
      break;
    default:
      printf("Invalid operator\n");
  }

  if (result) {
    printf("The result is: %.2f\n", result);
  }

  return 0;
}
