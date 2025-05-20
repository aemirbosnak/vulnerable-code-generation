//Gemma-7B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_operations = 0;
  char operation_symbol;
  float result = 0.0f;
  float operand_one = 0.0f;
  float operand_two = 0.0f;

  printf("Enter the number of operations you want to perform: ");
  scanf("%d", &number_of_operations);

  if (number_of_operations < 1) {
    printf("Error: Number of operations must be greater than 0.\n");
    return 1;
  }

  for (int i = 0; i < number_of_operations; i++) {
    printf("Enter the operation symbol (+, -, *, /): ");
    scanf(" %c", &operation_symbol);

    if (operation_symbol != '+' && operation_symbol != '-' && operation_symbol != '*' && operation_symbol != '/') {
      printf("Error: Invalid operation symbol.\n");
      return 1;
    }

    printf("Enter operand one: ");
    scanf("%f", &operand_one);

    printf("Enter operand two: ");
    scanf("%f", &operand_two);

    switch (operation_symbol) {
      case '+':
        result = operand_one + operand_two;
        break;
      case '-':
        result = operand_one - operand_two;
        break;
      case '*':
        result = operand_one * operand_two;
        break;
      case '/':
        if (operand_two == 0) {
          printf("Error: Cannot divide by 0.\n");
          return 1;
        }
        result = operand_one / operand_two;
        break;
    }

    printf("The result is: %.2f\n", result);
  }

  return 0;
}