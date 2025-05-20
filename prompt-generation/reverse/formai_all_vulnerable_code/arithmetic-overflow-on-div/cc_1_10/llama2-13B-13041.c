//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the math operations to perform
#define OPERATION_ADD 1
#define OPERATION_SUB 2
#define OPERATION_MUL 3
#define OPERATION_DIV 4

// Define the numbers to operate on
#define NUMBER1 10
#define NUMBER2 5

// Define the result of the operation
int result;

int main() {
  // Get the operation from the user
  int operation = getchar() - '0';

  // Check if the operation is valid
  if (operation < 0 || operation > 4) {
    printf("Invalid operation. Please enter a valid operation (1-4).\n");
    return 1;
  }

  // Get the first number from the user
  int first_number = getchar() - '0';

  // Get the second number from the user
  int second_number = getchar() - '0';

  // Perform the operation
  switch (operation) {
    case OPERATION_ADD:
      result = first_number + second_number;
      break;
    case OPERATION_SUB:
      result = first_number - second_number;
      break;
    case OPERATION_MUL:
      result = first_number * second_number;
      break;
    case OPERATION_DIV:
      result = first_number / second_number;
      break;
    default:
      printf("Invalid operation. Please enter a valid operation (1-4).\n");
      return 1;
  }

  // Print the result
  printf("Result: %d\n", result);

  return 0;
}