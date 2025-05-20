//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function to check if a given character is an operator
int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

// function to apply the operator to two numbers
double applyOperator(char op, double a, double b) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
  }
  return 0.0;
}

int main() {
  char expr[100];
  printf("Enter a mathematical expression: ");
  scanf("%s", expr);

  // initialize the stack
  char stack[100];
  int top = -1;

  // iterate over the expression
  for (int i = 0; expr[i] != '\0'; i++) {
    char c = expr[i];

    // if the character is an operand, push it to the stack
    if (isdigit(c)) {
      stack[++top] = c;
    }

    // if the character is an operator, pop two operands from the stack and apply the operator
    else if (isOperator(c)) {
      double b = stack[top--];
      double a = stack[top--];
      double result = applyOperator(c, a, b);
      stack[++top] = result;
    }
  }

  // the result is at the top of the stack
  double result = stack[top];

  printf("The result is: %lf\n", result);

  return 0;
}