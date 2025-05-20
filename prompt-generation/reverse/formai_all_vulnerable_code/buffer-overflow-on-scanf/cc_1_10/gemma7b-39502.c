//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  char operator;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calculator = malloc(sizeof(Calculator));
  calculator->top = -1;
  calculator->operator = '\0';
  calculator->result = 0.0;
  return calculator;
}

void calculator_push(Calculator* calculator, char number) {
  if (calculator->top >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calculator->buffer[++calculator->top] = number;
}

double calculator_pop(Calculator* calculator) {
  if (calculator->top == -1) {
    return -1;
  }
  return (double) calculator->buffer[calculator->top] - '0';
}

void calculator_operator(Calculator* calculator, char operator) {
  calculator->operator = operator;
}

double calculator_calculate(Calculator* calculator) {
  switch (calculator->operator) {
    case '+':
      calculator->result = calculator_pop(calculator) + calculator_pop(calculator);
      break;
    case '-':
      calculator->result = calculator_pop(calculator) - calculator_pop(calculator);
      break;
    case '*':
      calculator->result = calculator_pop(calculator) * calculator_pop(calculator);
      break;
    case '/':
      if (calculator_pop(calculator) == 0) {
        return -1;
      }
      calculator->result = calculator_pop(calculator) / calculator_pop(calculator);
      break;
    default:
      return -1;
  }
  return calculator->result;
}

int main() {
  Calculator* calculator = calculator_init();

  char input;
  double result;

  printf("Enter an expression: ");
  scanf("%c", &input);

  while (input != '=') {
    calculator_push(calculator, input);
    scanf("%c", &input);
  }

  calculator_operator(calculator, '=');
  result = calculator_calculate(calculator);

  if (result != -1) {
    printf("The result is: %.2lf\n", result);
  } else {
    printf("Error!\n");
  }

  free(calculator);

  return 0;
}