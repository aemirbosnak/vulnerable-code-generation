//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, product, square;
  char op;

  printf("Welcome to the Irregular Math Exercise Program!\n");

  // Generate two random numbers
  num1 = rand() % 100;
  num2 = rand() % 100;

  // Ask the user for an operation
  printf("Please enter an operation (+, -, x, /): ");
  scanf("%c", &op);

  // Perform the operation
  if (op == '+') {
    sum = num1 + num2;
  } else if (op == '-') {
    sum = num1 - num2;
  } else if (op == 'x') {
    product = num1 * num2;
  } else if (op == '/') {
    if (num2 == 0) {
      printf("Error: cannot divide by zero!\n");
      return 1;
    }
    square = num1 / num2;
  } else {
    printf("Error: invalid operation!\n");
    return 1;
  }

  // Print the result
  printf("Result: %d\n", sum);

  // Add some magic to the program
  if (sum % MAGIC_NUMBER == 0) {
    printf("Magic happens when the result is a multiple of 42!\n");
  }

  return 0;
}