//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1e-100
#define MAX_VALUE 1e100

int main() {
  int num_cases = 10;
  int i, j, k;
  double a, b, c, d, e;
  double result;
  char op;

  // Generate random numbers
  for (i = 0; i < num_cases; i++) {
    a = (double)rand() / RAND_MAX;
    b = (double)rand() / RAND_MAX;
    c = (double)rand() / RAND_MAX;
    d = (double)rand() / RAND_MAX;
    e = (double)rand() / RAND_MAX;

    // Generate random operation
    op = '+';
    switch (rand() % 4) {
      case 0:
        op = '+';
        break;
      case 1:
        op = '-';
        break;
      case 2:
        op = '*';
        break;
      case 3:
        op = '/';
        break;
    }

    // Evaluate expression
    result = 0;
    switch (op) {
      case '+':
        result = a + b + c + d + e;
        break;
      case '-':
        result = a - b - c - d - e;
        break;
      case '*':
        result = a * b * c * d * e;
        break;
      case '/':
        result = a / b / c / d / e;
        break;
    }

    // Check if result is within range
    if (result < MIN_VALUE || result > MAX_VALUE) {
      printf("Error: result out of range\n");
      return 1;
    }

    // Print result
    printf("Case %d: %f\n", i + 1, result);
  }

  return 0;
}