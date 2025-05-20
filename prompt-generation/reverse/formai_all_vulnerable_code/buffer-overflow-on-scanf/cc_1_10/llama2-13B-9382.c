//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBER_OF_VARIABLES 5

// Global variables
int numVariables[MAX_NUMBER_OF_VARIABLES];
char operations[MAX_OPERATIONS][20];
int result[MAX_OPERATIONS];

// Function to get input from user
void getInput() {
  int i, j;

  for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
    printf("Enter value of variable %d: ", i + 1);
    scanf("%d", &numVariables[i]);
  }

  for (j = 0; j < MAX_OPERATIONS; j++) {
    printf("Enter operation %d: ", j + 1);
    fgets(operations[j], 20, stdin);
  }
}

// Function to perform arithmetic operations
void performOperations() {
  int i, j;

  for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
    for (j = 0; j < MAX_OPERATIONS; j++) {
      if (strcmp(operations[j], "+") == 0) {
        result[j] = numVariables[i] + numVariables[i + 1];
      } else if (strcmp(operations[j], "-") == 0) {
        result[j] = numVariables[i] - numVariables[i + 1];
      } else if (strcmp(operations[j], "*") == 0) {
        result[j] = numVariables[i] * numVariables[i + 1];
      } else if (strcmp(operations[j], "/") == 0) {
        result[j] = numVariables[i] / numVariables[i + 1];
      }
      printf("Result of operation %d: %d\n", j + 1, result[j]);
    }
  }
}

int main() {
  srand(time(NULL));

  // Initialize variables
  for (int i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
    numVariables[i] = rand() % 100;
  }

  getInput();
  performOperations();

  return 0;
}