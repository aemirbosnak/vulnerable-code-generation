//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Define variables
  int num1, num2, operator;
  char operation;

  // Get user input for first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Get user input for second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Get user input for operator
  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operation);

  // Perform arithmetic operation based on user input
  switch (operation) {
    case '+':
      num1 += num2;
      break;
    case '-':
      num1 -= num2;
      break;
    case '*':
      num1 *= num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
      }
      num1 /= num2;
      break;
    default:
      printf("Error: Invalid operator.\n");
      return 0;
  }

  // Print result
  printf("The result is: %d\n", num1);

  return 0;
}