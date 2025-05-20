#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char operator;
  float num1, num2;

  printf("Enter an arithmetic expression: ");
  scanf("%c %f %f", &operator, &num1, &num2);

  switch (operator) {
    case '+':
      printf("%f + %f = %f\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%f - %f = %f\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%f * %f = %f\n", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Cannot divide by zero\n");
      } else {
        printf("%f / %f = %f\n", num1, num2, num1 / num2);
      }
      break;
    default:
      printf("Invalid operator\n");
  }

  return 0;
}
