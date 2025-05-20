//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  char operator;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
  calc->top = -1;
  calc->operator = '\0';
  calc->result = 0.0;
  return calc;
}

void calculator_push(Calculator* calc, char num) {
  if (calc->top == MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[++calc->top] = num;
}

void calculator_pop(Calculator* calc) {
  if (calc->top == -1) {
    return;
  }
  calc->top--;
}

void calculator_set_operator(Calculator* calc, char op) {
  calc->operator = op;
}

double calculator_get_result(Calculator* calc) {
  return calc->result;
}

int main() {
  Calculator* calc = calculator_init();

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
        calculator_push(calc, input[i]);
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        calculator_set_operator(calc, input[i]);
        break;
      case '=':
        calc->result = calculator_get_result(calc);
        printf("The result is: %.2lf\n", calc->result);
        break;
    }
  }

  free(calc);
  return 0;
}