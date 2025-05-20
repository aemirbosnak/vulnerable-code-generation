//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;
  char op;
  char magic_word[20];

  printf("Welcome to the Magic Arithmetic Machine!\n");

  // Initialize the magic word
  strcpy(magic_word, "forty-two");

  // Ask the user for the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Ask the user for the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Ask the user for the operation
  printf("Enter the operation (+, -, *, /): ");
  scanf(" %c", &op);

  // Perform the operation
  if (op == '+') {
    sum = num1 + num2;
  } else if (op == '-') {
    difference = num1 - num2;
  } else if (op == '*') {
    product = num1 * num2;
  } else if (op == '/') {
    quotient = num1 / num2;
    remainder = num1 % num2;
  }

  // Check if the result is within the magic range
  if (abs(sum) > MAX_NUMBER || abs(difference) > MAX_NUMBER || abs(product) > MAX_NUMBER || abs(quotient) > MAX_NUMBER) {
    printf("Error: result is outside the magic range\n");
    return 1;
  }

  // Print the result
  if (op == '+') {
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
  } else if (op == '-') {
    printf("The difference of %d and %d is %d\n", num1, num2, difference);
  } else if (op == '*') {
    printf("The product of %d and %d is %d\n", num1, num2, product);
  } else if (op == '/') {
    printf("The quotient of %d and %d is %d, with a remainder of %d\n", num1, num2, quotient, remainder);
  }

  // Check if the result is equal to the magic number
  if (sum == MAGIC_NUMBER || difference == MAGIC_NUMBER || product == MAGIC_NUMBER || quotient == MAGIC_NUMBER) {
    printf("Congratulations! You have found the magic number %d!\n", MAGIC_NUMBER);
  }

  return 0;
}