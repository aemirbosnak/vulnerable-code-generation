//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i, pos, num, sign, operator;
  float result;

  printf("Enter an expression: ");
  scanf("%s", buffer);

  pos = 0;
  num = 0;
  sign = 1;
  operator = 0;

  for (i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] >= '0' && buffer[i] <= '9') {
      num = num * 10 + buffer[i] - '0';
    } else if (buffer[i] == '+') {
      operator = '+';
      sign = 1;
    } else if (buffer[i] == '-') {
      operator = '-';
      sign = -1;
    } else if (buffer[i] == '*') {
      operator = '*';
      sign = 1;
    } else if (buffer[i] == '/') {
      operator = '/';
      sign = 1;
    } else if (buffer[i] == '=') {
      result = (float)num * sign;
      switch (operator) {
        case '+':
          result += (float)num * sign;
          break;
        case '-':
          result -= (float)num * sign;
          break;
        case '*':
          result *= (float)num * sign;
          break;
        case '/':
          result /= (float)num * sign;
          break;
      }
      printf("The result is: %.2f\n", result);
      break;
    }
  }

  if (i == 0) {
    printf("Invalid expression.\n");
  }

  return 0;
}