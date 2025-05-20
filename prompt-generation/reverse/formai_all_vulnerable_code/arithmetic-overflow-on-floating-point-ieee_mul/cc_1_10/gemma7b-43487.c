//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct CalculatorState {
  double currentNumber;
  double previousNumber;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
  int historyIndex;
} CalculatorState;

CalculatorState state;

void clearCalculator() {
  state.currentNumber = 0.0;
  state.previousNumber = 0.0;
  state.operator = '\0';
  state.bufferIndex = 0;
  state.historyIndex = 0;
}

void appendNumber(double number) {
  if (state.bufferIndex >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  state.buffer[state.bufferIndex++] = (number - (int)number) * 10 + (int)number;
}

void enterOperator(char operator) {
  state.operator = operator;
  state.previousNumber = state.currentNumber;
  state.currentNumber = 0.0;
}

double calculate() {
  switch (state.operator) {
    case '+':
      return state.previousNumber + state.currentNumber;
    case '-':
      return state.previousNumber - state.currentNumber;
    case '*':
      return state.previousNumber * state.currentNumber;
    case '/':
      if (state.currentNumber == 0) {
        return 0.0;
      }
      return state.previousNumber / state.currentNumber;
    default:
      return 0.0;
  }
}

int main() {
  clearCalculator();

  char input;
  double number;

  printf("Enter an expression: ");

  // Read input until the user enters an operator or a newline character
  while ((input = getchar()) != '+' && input != '-' && input != '*' && input != '/' && input != '\n') {
    appendNumber(number);
  }

  // Enter the operator
  enterOperator(input);

  // Read the remaining input and calculate the expression
  appendNumber(number);
  calculate();

  // Display the result
  printf("The result is: %.2lf\n", state.currentNumber);

  return 0;
}