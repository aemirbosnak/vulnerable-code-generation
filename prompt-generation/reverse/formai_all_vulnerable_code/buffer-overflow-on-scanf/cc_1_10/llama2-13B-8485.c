//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAGIC_NUMBER 42

void artistic_expression(int num1, int num2, int num3) {
  double result = 0;
  int i, j, k;
  char op;
  char digits[10];

  srand(time(NULL));

  // Generate random numbers and operations
  num1 = (rand() % 10) + 1;
  num2 = (rand() % 10) + 1;
  num3 = (rand() % 10) + 1;
  op = (rand() % 2) ? '+' : '-';

  // Generate a random string of digits
  for (i = 0; i < 10; i++) {
    digits[i] = (rand() % 10) + '0';
  }

  // Perform the operation
  switch (op) {
    case '+':
      result = num1 + num2 + num3;
      break;
    case '-':
      result = num1 - num2 - num3;
      break;
    case '*':
      result = num1 * num2 * num3;
      break;
    case '/':
      result = num1 / num2 / num3;
      break;
    default:
      result = MAGIC_NUMBER;
      break;
  }

  // Print the result in a artistic way
  for (i = 0; i < 10; i++) {
    printf("%c", digits[i]);
    if (i % 2 == 0) {
      printf(" ");
    }
  }
  printf("\n");

  return;
}

int main() {
  int num1, num2, num3;

  printf("Enter three numbers: ");
  scanf("%d%d%d", &num1, &num2, &num3);

  artistic_expression(num1, num2, num3);

  return 0;
}