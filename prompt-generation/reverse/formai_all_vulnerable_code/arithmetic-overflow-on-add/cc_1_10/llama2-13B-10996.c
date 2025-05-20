//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 1000000000
#define MAX_OPERATION 10

// Define the medieval-style arithmetic operations
void add(int a, int b, int *sum) {
  *sum = a + b;
}

void subtract(int a, int b, int *diff) {
  *diff = a - b;
}

void multiply(int a, int b, int *product) {
  *product = a * b;
}

void divide(int a, int b, int *quo) {
  *quo = a / b;
}

// Define the medieval-style expressions
int main() {
  int num1, num2, sum, diff, product, quo;
  char op[MAX_OPERATION];

  // Ask the user for the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Ask the user for the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Ask the user for the operation
  printf("Choose an operation (+, -, *, /): ");
  scanf(" %c", &op[0]);

  // Perform the operation
  switch (op[0]) {
    case '+':
      add(num1, num2, &sum);
      break;
    case '-':
      subtract(num1, num2, &diff);
      break;
    case '*':
      multiply(num1, num2, &product);
      break;
    case '/':
      divide(num1, num2, &quo);
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the results
  printf("The result of %d %c %d is %d\n", num1, op[0], num2, sum);

  return 0;
}