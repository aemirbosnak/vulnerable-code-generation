//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int priority(char c) {
  if (c == '(' || c == ')') return 0;
  else if (c == '+' || c == '-') return 1;
  else if (c == '*' || c == '/') return 2;
  else return -1;
}

double evaluate(double x, double y, char op) {
  switch (op) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
  }
  return 0.0;
}

int main() {
  char input[100];
  scanf("%s", input);

  int len = strlen(input);
  char stack[len];
  int top = -1;

  double num[len];
  int numIdx = 0;

  for (int i = 0; i < len; i++) {
    char c = input[i];
    if (isdigit(c)) {
      double n = atof(input + i);
      num[numIdx++] = n;
      while (isdigit(input[i])) i++;
      i--;
    } else if (isOperator(c)) {
      while (top != -1 && priority(stack[top]) >= priority(c)) {
        double y = num[numIdx - 1]; numIdx--;
        double x = num[numIdx - 1]; numIdx--;
        char op = stack[top--];
        double result = evaluate(x, y, op);
        num[numIdx++] = result;
      }
      stack[++top] = c;
    }
  }

  while (top != -1) {
    double y = num[numIdx - 1]; numIdx--;
    double x = num[numIdx - 1]; numIdx--;
    char op = stack[top--];
    double result = evaluate(x, y, op);
    num[numIdx++] = result;
  }

  printf("%lf\n", num[numIdx - 1]);

  return 0;
}