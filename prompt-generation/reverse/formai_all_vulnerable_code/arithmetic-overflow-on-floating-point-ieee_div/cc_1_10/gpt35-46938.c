//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
// Function prototypes
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);

int main() {
  float num1, num2;
  char operator;
  printf("Welcome to the Calculator Program\n\n");
  printf("Enter a number: ");
  scanf("%f", &num1);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Enter another number: ");
  scanf("%f", &num2);

  switch(operator) {
    case '+':
      printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
      break;
    case '-':
      printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
      break;
    case '*':
      printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
      break;
    case '/':
      printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
      break;
    default:
      printf("Invalid operator entered!\n");
      break;
  }

  return 0;
}

// Function to add two numbers
float add(float num1, float num2) {
  return num1 + num2;
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
  return num1 - num2;
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
  return num1 * num2;
}

// Function to divide two numbers
float divide(float num1, float num2) {
  if (num2 == 0) {
    printf("Undefined result: attempted to divide by zero\n");
    exit(EXIT_FAILURE);
  }
  
  return num1 / num2;
}