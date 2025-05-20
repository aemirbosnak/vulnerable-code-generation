//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

// Function to perform an arithmetic operation
void perform_op(int *numbers, int num_numbers, char op) {
  int result = 0;

  switch (op) {
    case '+':
      result = numbers[0] + numbers[1];
      break;
    case '-':
      result = numbers[0] - numbers[1];
      break;
    case '*':
      result = numbers[0] * numbers[1];
      break;
    case '/':
      result = numbers[0] / numbers[1];
      break;
    case '%':
      result = numbers[0] % numbers[1];
      break;
    default:
      printf("Invalid operation %c\n", op);
      return;
  }

  printf("Result: %d\n", result);
}

int main() {
  int numbers[MAX_NUMBERS];
  char operations[MAX_OPERATIONS];
  int i, j, num_ops = 0;

  // Read the numbers and operations from the user
  for (i = 0; i < MAX_NUMBERS; i++) {
    printf("Enter a number: ");
    scanf("%d", &numbers[i]);
  }

  for (i = 0; i < MAX_OPERATIONS; i++) {
    printf("Enter an operation (+, -, *, /, or %): ");
    scanf(" %c", &operations[i]);
  }

  // Perform the operations
  for (i = 0; i < MAX_OPERATIONS; i++) {
    perform_op(numbers, i, operations[i]);
  }

  return 0;
}