//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 2048

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  int history[10];
  int historyIndex;
  char operator;
  float result;
} Calculator;

void calculator_init(Calculator *calc) {
  calc->position = 0;
  calc->historyIndex = 0;
  calc->result = 0.0f;
}

void calculator_append_number(Calculator *calc, int number) {
  int i = calc->position;
  if (i >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[i++] = number + '0';
  calc->position = i;
}

void calculator_append_operator(Calculator *calc, char operator) {
  calc->operator = operator;
  calc->position++;
}

void calculator_clear(Calculator *calc) {
  calc->position = 0;
  calc->result = 0.0f;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void calculator_calculate(Calculator *calc) {
  switch (calc->operator) {
    case '+':
      calc->result = (float)calc->buffer[0] + (float)calc->buffer[1] - '0';
      break;
    case '-':
      calc->result = (float)calc->buffer[0] - (float)calc->buffer[1] - '0';
      break;
    case '*':
      calc->result = (float)calc->buffer[0] * (float)calc->buffer[1] - '0';
      break;
    case '/':
      calc->result = (float)calc->buffer[0] / (float)calc->buffer[1] - '0';
      break;
  }
  calc->history[calc->historyIndex++] = calc->result;
  calculator_clear(calc);
}

int main() {
  Calculator calc;
  calculator_init(&calc);

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  int i = 0;
  while (input[i] != '\0') {
    if (isdigit(input[i])) {
      calculator_append_number(&calc, input[i] - '0');
    } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      calculator_append_operator(&calc, input[i]);
    }
    i++;
  }

  calculator_calculate(&calc);

  printf("Result: %.2f\n", calc.result);

  return 0;
}