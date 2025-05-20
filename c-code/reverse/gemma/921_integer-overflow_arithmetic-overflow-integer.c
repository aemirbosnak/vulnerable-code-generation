#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char operator;
  int num1, num2, result;
  while (1) {
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
      printf("Enter first number: ");
      scanf("%d", &num1);
      printf("Enter second number: ");
      scanf("%d", &num2);

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
      }

      printf("Result: %d\n", result);
    } else if (operator == '\0') {
      break;
    } else {
      printf("Invalid operator.\n");
    }
  }

  return 0;
}
