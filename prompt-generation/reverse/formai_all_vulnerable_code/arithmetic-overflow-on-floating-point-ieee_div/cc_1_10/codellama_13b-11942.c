//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STR_LEN 100

struct Calculator {
  double result;
  char input[MAX_STR_LEN];
  int input_len;
  int op;
};

void init_calculator(struct Calculator *calc) {
  calc->result = 0;
  calc->input_len = 0;
  calc->op = 0;
}

void display_calculator(struct Calculator *calc) {
  printf("Result: %f\n", calc->result);
  printf("Input: %s\n", calc->input);
  printf("Input Length: %d\n", calc->input_len);
  printf("Operation: %d\n", calc->op);
}

int calculate(struct Calculator *calc) {
  switch (calc->op) {
    case '+':
      calc->result += atof(calc->input);
      break;
    case '-':
      calc->result -= atof(calc->input);
      break;
    case '*':
      calc->result *= atof(calc->input);
      break;
    case '/':
      calc->result /= atof(calc->input);
      break;
    default:
      printf("Invalid operation.\n");
      return -1;
  }
  return 0;
}

int main() {
  struct Calculator calc;
  init_calculator(&calc);

  while (1) {
    printf("Enter an operation (+, -, *, /): ");
    scanf("%s", calc.input);
    calc.op = calc.input[0];

    printf("Enter a number: ");
    scanf("%s", calc.input);
    calc.input_len = strlen(calc.input);

    calculate(&calc);
    display_calculator(&calc);
  }

  return 0;
}