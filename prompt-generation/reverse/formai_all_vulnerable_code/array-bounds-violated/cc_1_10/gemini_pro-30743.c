//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Parse a C expression and evaluate it.
double parse_expression(char *expr) {
  // Initialize the stack.
  double stack[100];
  int top = 0;

  // Loop over the expression, one character at a time.
  while (*expr) {
    // If the current character is a digit, push it onto the stack.
    if (isdigit(*expr)) {
      stack[top++] = *expr - '0';
    }
    // If the current character is an operator, pop the top two values from the stack,
    // perform the operation, and push the result back onto the stack.
    else if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
      double op2 = stack[--top];
      double op1 = stack[--top];
      switch (*expr) {
        case '+':
          stack[top++] = op1 + op2;
          break;
        case '-':
          stack[top++] = op1 - op2;
          break;
        case '*':
          stack[top++] = op1 * op2;
          break;
        case '/':
          stack[top++] = op1 / op2;
          break;
      }
    }
    // If the current character is a parenthesis, recursively parse the expression
    // inside the parentheses and push the result onto the stack.
    else if (*expr == '(') {
      expr++;
      stack[top++] = parse_expression(expr);
      while (*expr != ')') expr++;
    }
    // If the current character is a newline, ignore it.
    else if (*expr == '\n') {
      ;
    }
    // Otherwise, the current character is invalid.
    else {
      fprintf(stderr, "Invalid character in expression: %c\n", *expr);
      exit(1);
    }

    // Advance to the next character in the expression.
    expr++;
  }

  // If the stack is empty, the expression is invalid.
  if (top == 0) {
    fprintf(stderr, "Invalid expression: %s\n", expr);
    exit(1);
  }

  // Return the value at the top of the stack.
  return stack[top - 1];
}

int main(int argc, char **argv) {
  // Get the expression from the command line.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s expression\n", argv[0]);
    exit(1);
  }
  char *expr = argv[1];

  // Parse and evaluate the expression.
  double result = parse_expression(expr);

  // Print the result.
  printf("Result: %f\n", result);

  return 0;
}