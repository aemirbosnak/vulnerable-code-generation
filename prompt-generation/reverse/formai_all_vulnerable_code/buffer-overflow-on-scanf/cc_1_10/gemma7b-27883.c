//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct CalculatorState {
  double accumulator;
  double operand;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
} CalculatorState;

CalculatorState state;

void calculate() {
  switch (state.operator) {
    case '+':
      state.accumulator += state.operand;
      break;
    case '-':
      state.accumulator -= state.operand;
      break;
    case '*':
      state.accumulator *= state.operand;
      break;
    case '/':
      if (state.operand == 0) {
        printf("Error: division by zero\n");
      } else {
        state.accumulator /= state.operand;
      }
      break;
    default:
      printf("Error: invalid operator\n");
  }

  state.bufferIndex = 0;
  memset(state.buffer, 0, MAX_BUFFER_SIZE);
}

void processInput() {
  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  // Parse the input expression
  char *token = strtok(input, " ");
  while (token) {
    double number = atof(token);
    if (number != -1) {
      state.operand = number;
    } else {
      state.operator = token[0];
    }

    token = strtok(NULL, " ");
  }

  calculate();
}

int main() {
  processInput();

  return 0;
}