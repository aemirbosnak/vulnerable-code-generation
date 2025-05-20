//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BRAVE_MODE 1

int main() {
  int brave_level = BRAVE_MODE;

  if (brave_level == 1) {
    // Level 1: Basic Arithmetic
    int num1 = 5;
    int num2 = 10;
    int sum = num1 + num2;
    int diff = num1 - num2;
    int mult = num1 * num2;
    int div = num1 / num2;

    printf("Level 1: Basic Arithmetic\n");
    printf("Sum: %d\n", sum);
    printf("Diff: %d\n", diff);
    printf("Mult: %d\n", mult);
    printf("Div: %d\n", div);

    // Level 2: Advanced Arithmetic
    int num3 = 20;
    int num4 = 30;
    int quotient = num3 / num4;
    int remainder = num3 % num4;
    int power = num3 * pow(num4, 2);

    printf("Level 2: Advanced Arithmetic\n");
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    printf("Power: %d\n", power);
  } else if (brave_level == 2) {
    // Level 3: Brave Arithmetic
    int num5 = 40;
    int num6 = 50;
    int product = num5 * num6;
    int square = num5 * num5;
    int cube = num5 * num5 * num5;

    printf("Level 3: Brave Arithmetic\n");
    printf("Product: %d\n", product);
    printf("Square: %d\n", square);
    printf("Cube: %d\n", cube);
  } else {
    printf("Invalid brave level selected\n");
    return 1;
  }

  return 0;
}