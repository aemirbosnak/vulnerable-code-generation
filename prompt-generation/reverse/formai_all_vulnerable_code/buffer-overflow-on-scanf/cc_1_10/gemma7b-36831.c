//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double result;
  double operand1;
  double operand2;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->result = 0.0;
  calculator->operand1 = 0.0;
  calculator->operand2 = 0.0;
  calculator->operator = '\0';
  calculator->bufferIndex = 0;
  return calculator;
}

void freeCalculator(Calculator* calculator) {
  free(calculator);
}

void calculate(Calculator* calculator) {
  switch (calculator->operator) {
    case '+':
      calculator->result = calculator->operand1 + calculator->operand2;
      break;
    case '-':
      calculator->result = calculator->operand1 - calculator->operand2;
      break;
    case '*':
      calculator->result = calculator->operand1 * calculator->operand2;
      break;
    case '/':
      if (calculator->operand2 == 0) {
        printf("Error: division by zero is not allowed.\n");
        return;
      }
      calculator->result = calculator->operand1 / calculator->operand2;
      break;
    default:
      printf("Error: invalid operator.\n");
      return;
  }
}

int main() {
  Calculator* calculator = createCalculator();

  // Get the calculator input
  char input[MAX_BUFFER_SIZE];
  printf("Enter your calculator expression: ");
  scanf("%s", input);

  // Parse the input and calculate the result
  calculator->bufferIndex = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      calculator->operand2 = calculator->operand1;
      calculator->operand1 = input[i] - 'a' + 1.0;
    } else if (input[i] >= '0' && input[i] <= '9') {
      calculator->operand1 = calculator->operand1 * 10 + input[i] - '0';
    } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      calculator->operator = input[i];
    } else if (input[i] == '=') {
      calculate(calculator);
      printf("The result is: %.2lf\n", calculator->result);
      freeCalculator(calculator);
      return 0;
    }
  }

  // If the input is invalid, print an error message
  printf("Error: invalid input.\n");
  freeCalculator(calculator);
  return 1;
}