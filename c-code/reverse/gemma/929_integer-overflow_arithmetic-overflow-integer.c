#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_operations = 0;
  printf("Enter the number of operations (max 10): ");
  scanf("%d", &num_operations);

  if (num_operations > 10) {
    num_operations = 10;
  }

  for (int i = 0; i < num_operations; i++) {
    int operand1, operand2;
    char operator;

    printf("Enter operand 1: ");
    scanf("%d", &operand1);

    printf("Enter operand 2: ");
    scanf("%d", &operand2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
      case '+':
        printf("The result is: %d\n", operand1 + operand2);
        break;
      case '-':
        printf("The result is: %d\n", operand1 - operand2);
        break;
      case '*':
        printf("The result is: %d\n", operand1 * operand2);
        break;
      case '/':
        if (operand2 == 0) {
          printf("Cannot divide by zero.\n");
        } else {
          printf("The result is: %d\n", operand1 / operand2);
        }
        break;
      default:
        printf("Invalid operator.\n");
    }
  }

  return 0;
}
