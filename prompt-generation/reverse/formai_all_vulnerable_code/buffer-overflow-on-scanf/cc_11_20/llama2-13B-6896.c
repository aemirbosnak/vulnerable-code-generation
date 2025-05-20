//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBER_OF_VARIABLES 5

int main() {
  int operations[MAX_OPERATIONS];
  int variables[MAX_NUMBER_OF_VARIABLES];
  int i, j, k;
  char op;

  // Initialize variables
  for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
    variables[i] = 0;
  }

  // Get operations from user
  for (i = 0; i < MAX_OPERATIONS; i++) {
    printf("Enter operation (+, -, *, /, or ^): ");
    scanf("%c", &op);
    operations[i] = op;
  }

  // Get numbers from user
  for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
    printf("Enter variable %d: ", i + 1);
    scanf("%d", &variables[i]);
  }

  // Perform operations
  for (i = 0; i < MAX_OPERATIONS; i++) {
    for (j = 0; j < MAX_NUMBER_OF_VARIABLES; j++) {
      if (operations[i] == '+') {
        variables[j] += variables[j];
      } else if (operations[i] == '-') {
        variables[j] -= variables[j];
      } else if (operations[i] == '*') {
        variables[j] *= variables[j];
      } else if (operations[i] == '/') {
        variables[j] /= variables[j];
      } else if (operations[i] == '^') {
        variables[j] = pow(variables[j], variables[j]);
      }
    }
  }

  // Print results
  for (j = 0; j < MAX_NUMBER_OF_VARIABLES; j++) {
    printf("%d ", variables[j]);
  }

  return 0;
}