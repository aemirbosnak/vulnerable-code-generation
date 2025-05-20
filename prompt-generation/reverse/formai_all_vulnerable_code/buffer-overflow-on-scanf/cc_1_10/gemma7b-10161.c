//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  int history[10];
  int historyPos;
} Calculator;

void initializeCalculator(Calculator *calc) {
  calc->pos = 0;
  calc->historyPos = 0;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void addToBuffer(Calculator *calc, char ch) {
  if (calc->pos >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[calc->pos++] = ch;
}

void clearBuffer(Calculator *calc) {
  calc->pos = 0;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void storeHistory(Calculator *calc, char expression) {
  if (calc->historyPos >= 10) {
    return;
  }
  calc->history[calc->historyPos++] = expression;
}

char calculateExpression(Calculator *calc) {
  char result = 0;
  char operator = calc->buffer[0];
  switch (operator) {
    case '+':
      result = calc->history[calc->historyPos - 1] + calc->buffer[1] - '0';
      break;
    case '-':
      result = calc->history[calc->historyPos - 1] - calc->buffer[1] - '0';
      break;
    case '*':
      result = calc->history[calc->historyPos - 1] * calc->buffer[1] - '0';
      break;
    case '/':
      result = calc->history[calc->historyPos - 1] / calc->buffer[1] - '0';
      break;
  }
  storeHistory(calc, result);
  return result;
}

int main() {
  Calculator calc;
  initializeCalculator(&calc);

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    addToBuffer(&calc, input[i]);
  }

  char result = calculateExpression(&calc);

  if (result) {
    printf("Result: %c\n", result);
  } else {
    printf("Error: Invalid expression.\n");
  }

  return 0;
}