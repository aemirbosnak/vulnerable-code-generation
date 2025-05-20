//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  double result;
} Calculator;

void initializeCalculator(Calculator *calc) {
  calc->position = 0;
  calc->result = 0.0;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void addToBuffer(Calculator *calc, char character) {
  if (calc->position >= MAX_BUFFER_SIZE - 1) {
    return;
  }

  calc->buffer[calc->position++] = character;
}

double calculateResult(Calculator *calc) {
  double number = 0.0;
  int i = 0;

  for (; calc->buffer[i] != '\0'; i++) {
    switch (calc->buffer[i]) {
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
        number = number * 10 + calc->buffer[i] - '0';
        break;
      case '.':
        number = number + 0.1 * (calc->buffer[i + 1] - '0');
        break;
      case '=':
        calc->result = number;
        break;
    }
  }

  return calc->result;
}

int main() {
  Calculator calculator;
  initializeCalculator(&calculator);

  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    addToBuffer(&calculator, input[i]);
  }

  double result = calculateResult(&calculator);

  if (result != 0.0) {
    printf("Result: %.2lf\n", result);
  } else {
    printf("Invalid expression\n");
  }

  return 0;
}