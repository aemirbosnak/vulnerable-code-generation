//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double value;
  char *operator;
} operation;

operation opStack[100];
int opIndex = 0;

double evalStack[100];
int evalIndex = 0;

void pushOp(double value, char *operator) {
  opStack[opIndex++] = (operation){value, operator};
}

void pushEval(double value) {
  evalStack[evalIndex++] = value;
}

double popOp() {
  return opStack[--opIndex].value;
}

char *popOperator() {
  return opStack[--opIndex].operator;
}

double popEval() {
  return evalStack[--evalIndex];
}

int main() {
  char *input = "2+3*4-5/2";
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      pushEval(input[i] - '0');
    } else {
      double b = popEval();
      double a = popEval();
      switch (input[i]) {
        case '+':
          pushEval(a + b);
          break;
        case '-':
          pushEval(a - b);
          break;
        case '*':
          pushEval(a * b);
          break;
        case '/':
          pushEval(a / b);
          break;
      }
    }
  }
  printf("%lf\n", popEval());
  return 0;
}