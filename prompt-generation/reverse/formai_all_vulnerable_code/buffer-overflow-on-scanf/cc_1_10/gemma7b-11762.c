//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  double result;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->top = -1;
  calculator->result = 0.0;
  return calculator;
}

void push(Calculator* calculator, char number) {
  if (calculator->top == MAX_BUFFER_SIZE - 1) {
    printf("Error: Calculator buffer overflow!\n");
    return;
  }
  calculator->buffer[++calculator->top] = number;
}

double pop(Calculator* calculator) {
  if (calculator->top == -1) {
    printf("Error: Calculator buffer underflow!\n");
    return -1.0;
  }
  return (double)calculator->buffer[calculator->top] - '0';
}

double calculate(Calculator* calculator) {
  double operand1 = pop(calculator);
  double operand2 = pop(calculator);
  switch (calculator->buffer[calculator->top]) {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
    default:
      return -1.0;
  }
}

int main() {
  Calculator* calculator = createCalculator();
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        push(calculator, input[i]);
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        calculate(calculator);
        break;
    }
  }

  printf("Result: %.2lf\n", calculator->result);

  return 0;
}