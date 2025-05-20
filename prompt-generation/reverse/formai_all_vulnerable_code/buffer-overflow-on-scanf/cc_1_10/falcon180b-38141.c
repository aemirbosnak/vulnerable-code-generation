//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include <stdio.h>

// Define a function to perform addition
int add(int a, int b) {
  return a + b;
}

// Define a function to perform subtraction
int subtract(int a, int b) {
  return a - b;
}

// Define a function to perform multiplication
int multiply(int a, int b) {
  return a * b;
}

// Define a function to perform division
int divide(int a, int b) {
  if (b == 0) {
    printf("Error: Division by zero is not allowed.\n");
    return -1;
  }
  return a / b;
}

int main() {
  int num1, num2, result;
  char operation;

  printf("Enter two numbers separated by space: ");
  scanf("%d %d", &num1, &num2);

  printf("Enter the operation (+, -, *, /): ");
  scanf("%c", &operation);

  switch (operation) {
    case '+':
      result = add(num1, num2);
      printf("The result is %d\n", result);
      break;
    case '-':
      result = subtract(num1, num2);
      printf("The result is %d\n", result);
      break;
    case '*':
      result = multiply(num1, num2);
      printf("The result is %d\n", result);
      break;
    case '/':
      result = divide(num1, num2);
      printf("The result is %d\n", result);
      break;
    default:
      printf("Invalid operation!\n");
  }

  return 0;
}