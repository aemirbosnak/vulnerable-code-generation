//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
  double accumulator;
  double operand;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
  int historyIndex;
} Calculator;

Calculator calculator;

void initializeCalculator() {
  calculator.accumulator = 0.0;
  calculator.operand = 0.0;
  calculator.operator = '\0';
  calculator.bufferIndex = 0;
  calculator.historyIndex = 0;
}

void storeOperand(double value) {
  calculator.operand = value;
}

void storeOperator(char operator) {
  calculator.operator = operator;
}

double calculateResult() {
  switch (calculator.operator) {
    case '+':
      return calculator.accumulator + calculator.operand;
    case '-':
      return calculator.accumulator - calculator.operand;
    case '*':
      return calculator.accumulator * calculator.operand;
    case '/':
      if (calculator.operand == 0) {
        return 0.0;
      } else {
        return calculator.accumulator / calculator.operand;
      }
    case '^':
      return pow(calculator.accumulator, calculator.operand);
    default:
      return 0.0;
  }
}

void displayHistory() {
  printf("History: ");
  for (int i = 0; i < calculator.historyIndex; i++) {
    printf("%s ", calculator.buffer[i]);
  }
  printf("\n");
}

int main() {
  initializeCalculator();

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  // Parse the input expression and store operators and operands
  char operator = '\0';
  double operand = 0.0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (isdigit(input[i])) {
      operand = operand * 10 + input[i] - '0';
    } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
      operator = input[i];
    } else if (input[i] == ')') {
      storeOperand(operand);
      storeOperator(operator);
      operand = 0.0;
    }
  }

  // Calculate the result and store it in the history
  double result = calculateResult();
  storeOperand(result);
  storeOperator('\0');

  // Display the history
  displayHistory();

  // Print the result
  printf("Result: %.2lf\n", result);

  return 0;
}