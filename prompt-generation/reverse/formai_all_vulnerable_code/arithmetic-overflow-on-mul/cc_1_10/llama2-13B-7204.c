//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Retro-style function declarations! 😜
void print_hello(void);
int add_numbers(int, int);

// Parse a C-style expression and print the result
void parse_expression(char *expr) {
  int num1, num2, res;
  char op;

  // Tokenize the expression into separate parts
  char *token = strtok(expr, " ");
  while (token != NULL && token[0] != '\0') {
    if (isdigit(token[0])) {
      num1 = atoi(token);
      token = strtok(NULL, " ");
    } else if (token[0] == '+') {
      op = '+';
      token = strtok(NULL, " ");
    } else if (token[0] == '-') {
      op = '-';
      token = strtok(NULL, " ");
    } else if (token[0] == '*') {
      op = '*';
      token = strtok(NULL, " ");
    } else if (token[0] == '/') {
      op = '/';
      token = strtok(NULL, " ");
    } else {
      print_hello(); // Handle invalid input
      return;
    }
    token = strtok(NULL, " ");
  }

  // Perform the operation
  if (op == '+') {
    res = add_numbers(num1, num2);
  } else if (op == '-') {
    res = num1 - num2;
  } else if (op == '*') {
    res = num1 * num2;
  } else if (op == '/') {
    res = num1 / num2;
  } else {
    print_hello(); // Handle invalid input
    return;
  }

  // Print the result
  printf("%d\n", res);
}

// Retro-style function implementations! 😄
void print_hello(void) {
  printf("Hello, world! 🐱\n");
}

int add_numbers(int num1, int num2) {
  return num1 + num2;
}

int main(void) {
  char expr[100];

  // Get the expression from the user
  printf("Enter an expression: ");
  fgets(expr, 100, stdin);

  // Parse the expression
  parse_expression(expr);

  return 0;
}