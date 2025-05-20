//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    return 1;
  }

  double result = 0;
  char* expr = argv[1];
  int i = 0;

  while(expr[i] != '\0') {
    if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
      double op1 = result;
      double op2 = 0;
      char op = expr[i];
      i++;

      while(expr[i] != '\0' && expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != '^') {
        op2 = op2 * 10 + (expr[i] - '0');
        i++;
      }

      switch(op) {
        case '+':
          result = op1 + op2;
          break;
        case '-':
          result = op1 - op2;
          break;
        case '*':
          result = op1 * op2;
          break;
        case '/':
          if(op2 == 0) {
            printf("Error: Division by zero.\n");
            return 2;
          }

          result = op1 / op2;
          break;
        case '^':
          result = pow(op1, op2);
          break;
      }
    } else {
      result = result * 10 + (expr[i] - '0');
      i++;
    }
  }

  printf("Result: %f\n", result);
  return 0;
}