//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 10
#define MAX_DIGITS 10

// Function to perform arithmetic operations
void do_arithmetic(int *operands, int num_operands, int op) {
  int i, j, sum = 0, diff = 0, mult = 0, div = 0;
  char str[10];

  // Check for invalid input
  if (num_operands < 2 || num_operands > MAX_OPERANDS) {
    printf("Invalid number of operands\n");
    return;
  }

  // Perform operation based on input
  switch (op) {
    case '+':
      for (i = 0; i < num_operands; i++) {
        sum += operands[i];
      }
      break;
    case '-':
      for (i = 0; i < num_operands; i++) {
        diff += operands[i];
      }
      break;
    case '*':
      for (i = 0; i < num_operands; i++) {
        mult += operands[i] * operands[i];
      }
      break;
    case '/':
      for (i = 0; i < num_operands; i++) {
        div += operands[i] / operands[i];
      }
      break;
    default:
      printf("Invalid operation\n");
      return;
  }

  // Print results
  sprintf(str, "%d", sum);
  printf("Sum: %s\n", str);
  sprintf(str, "%d", diff);
  printf("Difference: %s\n", str);
  sprintf(str, "%d", mult);
  printf("Product: %s\n", str);
  sprintf(str, "%d", div);
  printf("Quotient: %s\n", str);
}

int main() {
  int operands[MAX_OPERANDS], i, num_operands;

  // Get number of operands from user
  printf("Enter number of operands: ");
  scanf("%d", &num_operands);

  // Get operands from user
  for (i = 0; i < num_operands; i++) {
    printf("Operand %d: ", i + 1);
    scanf("%d", &operands[i]);
  }

  // Perform arithmetic operations
  do_arithmetic(operands, num_operands, getchar());

  return 0;
}