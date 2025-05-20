//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 4
#define MAX_OPERAND_VALUE 100

// Function to perform arithmetic operations
void perform_arithmetic(int *operands, int num_operands, char *operation) {
  int result = 0;

  // Check if the operation is valid
  if (strcmp(operation, "+") == 0) {
    result = operands[0] + operands[1];
  } else if (strcmp(operation, "-") == 0) {
    result = operands[0] - operands[1];
  } else if (strcmp(operation, "*") == 0) {
    result = operands[0] * operands[1];
  } else if (strcmp(operation, "/") == 0) {
    result = operands[0] / operands[1];
  } else {
    printf("Invalid operation\n");
    return;
  }

  // Print the result
  printf("Result: %d\n", result);
}

int main() {
  int operands[MAX_OPERANDS] = {0};
  int num_operands = 0;
  char operation[MAX_OPERAND_VALUE] = "";

  // Get the operands and operation from the user
  while (num_operands < MAX_OPERANDS && strlen(operation) < MAX_OPERAND_VALUE) {
    printf("Enter operand %d: ", num_operands + 1);
    scanf("%d", &operands[num_operands]);

    printf("Enter operation: ");
    fgets(operation, MAX_OPERAND_VALUE, stdin);

    // Check if the operation is valid
    if (strcmp(operation, "+") == 0 || strcmp(operation, "-") == 0 ||
        strcmp(operation, "*") == 0 || strcmp(operation, "/") == 0) {
      num_operands++;
    } else {
      printf("Invalid operation\n");
      return 1;
    }
  }

  // Perform the arithmetic operations
  perform_arithmetic(operands, num_operands, operation);

  return 0;
}