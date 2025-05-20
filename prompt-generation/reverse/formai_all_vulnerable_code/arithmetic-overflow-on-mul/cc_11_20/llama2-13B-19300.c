//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 5

int main() {
  int operations[MAX_OPERATIONS];
  int numbers[MAX_NUMBERS];
  int i, j, k;
  char op;

  srand(time(NULL));

  for (i = 0; i < MAX_OPERATIONS; i++) {
    operations[i] = rand() % 2 + 1;
  }

  for (j = 0; j < MAX_NUMBERS; j++) {
    numbers[j] = rand() % 100;
  }

  printf("Welcome to Arithmetic Land! Please enter your calculations:\n");

  while (1) {
    printf("Enter operation (+, -, x, /): ");
    scanf("%c", &op);

    if (op == '+') {
      for (k = 0; k < MAX_OPERATIONS; k++) {
        numbers[k] = operations[k] * numbers[k];
      }
    } else if (op == '-') {
      for (k = 0; k < MAX_OPERATIONS; k++) {
        numbers[k] = operations[k] * numbers[k] - 1;
      }
    } else if (op == 'x') {
      for (k = 0; k < MAX_OPERATIONS; k++) {
        numbers[k] = operations[k] * numbers[k] * 2;
      }
    } else if (op == '/') {
      for (k = 0; k < MAX_OPERATIONS; k++) {
        numbers[k] = operations[k] * numbers[k] / 2;
      }
    } else {
      break;
    }

    for (k = 0; k < MAX_NUMBERS; k++) {
      printf("%d x %d = %d\n", operations[k], numbers[k], numbers[k] * operations[k]);
    }
  }

  return 0;
}