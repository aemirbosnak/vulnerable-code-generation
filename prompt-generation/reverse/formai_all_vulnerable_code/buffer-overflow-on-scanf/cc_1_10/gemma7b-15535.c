//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  double result;
  char operator;
} calculator;

calculator* create_calculator() {
  calculator* calc = (calculator*)malloc(sizeof(calculator));
  calc->top = -1;
  calc->result = 0.0;
  calc->operator = '\0';
  return calc;
}

void push_number(calculator* calc, double num) {
  if (calc->top >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[++calc->top] = num;
}

void push_operator(calculator* calc, char operator) {
  calc->operator = operator;
}

double pop_number(calculator* calc) {
  if (calc->top == -1) {
    return 0.0;
  }
  return (double)calc->buffer[calc->top--];
}

double calculate(calculator* calc) {
  switch (calc->operator) {
    case '+':
      return pop_number(calc) + pop_number(calc);
    case '-':
      return pop_number(calc) - pop_number(calc);
    case '*':
      return pop_number(calc) * pop_number(calc);
    case '/':
      return pop_number(calc) / pop_number(calc);
    default:
      return 0.0;
  }
}

int main() {
  calculator* calc = create_calculator();
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    if (isdigit(input[i])) {
      push_number(calc, (double)input[i] - '0');
    } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      push_operator(calc, input[i]);
    }
  }

  double result = calculate(calc);

  printf("The result is: %.2lf\n", result);

  return 0;
}