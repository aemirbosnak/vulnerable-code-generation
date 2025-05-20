//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
// Decentralized Arithmetic example program

#include <stdio.h>
#include <stdlib.h>

// function that accepts two integers and returns their sum
int add(int a, int b) {
  return a + b;
}

// function that accepts two integers and returns their difference
int subtract(int a, int b) {
  return a - b;
}

// function that accepts two integers and returns their product
int multiply(int a, int b) {
  return a * b;
}

// function that accepts two integers and returns their quotient
int divide(int a, int b) {
  if (b == 0) {
    printf("Error: division by zero");
    exit(1);
  }
  return a / b;
}

// main function
int main() {
  int a, b;
  char op;

  printf("Enter an arithmetic operation (+, -, *, /): ");
  scanf("%c", &op);

  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);

  switch (op) {
    case '+':
      printf("Result: %d\n", add(a, b));
      break;
    case '-':
      printf("Result: %d\n", subtract(a, b));
      break;
    case '*':
      printf("Result: %d\n", multiply(a, b));
      break;
    case '/':
      printf("Result: %d\n", divide(a, b));
      break;
    default:
      printf("Error: invalid operation");
      exit(1);
  }

  return 0;
}