#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, operator;

  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  printf("Enter an operator (+, -, *, /): ");
  scanf("%d", &operator);

  switch (operator) {
    case '+':
      num1 += num2;
      printf("The result is: %d\n", num1);
      break;
    case '-':
      num1 -= num2;
      printf("The result is: %d\n", num1);
      break;
    case '*':
      num1 *= num2;
      printf("The result is: %d\n", num1);
      break;
    case '/':
      if (num2 == 0) {
        printf("Cannot divide by zero\n");
      } else {
        num1 /= num2;
        printf("The result is: %d\n", num1);
      }
      break;
    default:
      printf("Invalid operator\n");
  }

  return 0;
}
