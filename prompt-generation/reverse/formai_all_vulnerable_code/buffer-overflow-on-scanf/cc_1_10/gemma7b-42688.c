//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

char buffer[MAX_BUFFER_SIZE];
char operator[MAX_BUFFER_SIZE];
int top = -1;
double result = 0;

void push(char op) {
  operator[++top] = op;
}

double pop() {
  if (top == -1) {
    return 0;
  } else {
    return operator[top--];
  }
}

void calculate() {
  double a = pop();
  double b = pop();
  char operator = pop();

  switch (operator) {
    case '+':
      result = a + b;
      break;
    case '-':
      result = b - a;
      break;
    case '*':
      result = a * b;
      break;
    case '/':
      if (b == 0) {
        printf("Error: division by zero\n");
        return;
      }
      result = a / b;
      break;
    default:
      printf("Error: invalid operator\n");
      return;
  }

  push(result);
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    if (isdigit(input[i])) {
      push(input[i]);
    } else if (input[i] == '+') {
      push('+');
    } else if (input[i] == '-') {
      push('-');
    } else if (input[i] == '*') {
      push('*');
    } else if (input[i] == '/') {
      push('/');
    }
  }

  calculate();

  if (result != 0) {
    printf("The result is: %.2lf\n", result);
  } else {
    printf("Error: invalid expression\n");
  }

  return 0;
}