//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_OPERATIONS 100

typedef enum {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  POWER,
  SIN,
  COS,
  TAN,
  LOG,
  EXP
} Operation;

typedef struct {
  Operation operation;
  double operand1;
  double operand2;
} OperationRecord;

int main() {
  // Get the number of operations from the user.
  printf("Enter the number of operations to perform: ");
  int num_operations;
  scanf("%d", &num_operations);

  // Check if the number of operations is valid.
  if (num_operations < 1 || num_operations > MAX_NUM_OPERATIONS) {
    printf("Invalid number of operations. The number of operations must be between 1 and %d.\n", MAX_NUM_OPERATIONS);
    return 1;
  }

  // Get the operations from the user.
  OperationRecord operations[MAX_NUM_OPERATIONS];
  for (int i = 0; i < num_operations; i++) {
    printf("Enter the operation to perform (add, subtract, multiply, divide, power, sin, cos, tan, log, exp): ");
    char operation_str[10];
    scanf("%s", operation_str);

    // Convert the operation string to an Operation enum value.
    Operation operation;
    if (strcmp(operation_str, "add") == 0) {
      operation = ADD;
    } else if (strcmp(operation_str, "subtract") == 0) {
      operation = SUBTRACT;
    } else if (strcmp(operation_str, "multiply") == 0) {
      operation = MULTIPLY;
    } else if (strcmp(operation_str, "divide") == 0) {
      operation = DIVIDE;
    } else if (strcmp(operation_str, "power") == 0) {
      operation = POWER;
    } else if (strcmp(operation_str, "sin") == 0) {
      operation = SIN;
    } else if (strcmp(operation_str, "cos") == 0) {
      operation = COS;
    } else if (strcmp(operation_str, "tan") == 0) {
      operation = TAN;
    } else if (strcmp(operation_str, "log") == 0) {
      operation = LOG;
    } else if (strcmp(operation_str, "exp") == 0) {
      operation = EXP;
    } else {
      printf("Invalid operation. The operation must be one of the following: add, subtract, multiply, divide, power, sin, cos, tan, log, exp.\n");
      return 1;
    }

    // Get the operands for the operation.
    printf("Enter the first operand: ");
    double operand1;
    scanf("%lf", &operand1);

    printf("Enter the second operand: ");
    double operand2;
    scanf("%lf", &operand2);

    // Store the operation and operands in the array.
    operations[i].operation = operation;
    operations[i].operand1 = operand1;
    operations[i].operand2 = operand2;
  }

  // Perform the operations and print the results.
  for (int i = 0; i < num_operations; i++) {
    double result;
    switch (operations[i].operation) {
      case ADD:
        result = operations[i].operand1 + operations[i].operand2;
        break;
      case SUBTRACT:
        result = operations[i].operand1 - operations[i].operand2;
        break;
      case MULTIPLY:
        result = operations[i].operand1 * operations[i].operand2;
        break;
      case DIVIDE:
        result = operations[i].operand1 / operations[i].operand2;
        break;
      case POWER:
        result = pow(operations[i].operand1, operations[i].operand2);
        break;
      case SIN:
        result = sin(operations[i].operand1);
        break;
      case COS:
        result = cos(operations[i].operand1);
        break;
      case TAN:
        result = tan(operations[i].operand1);
        break;
      case LOG:
        result = log(operations[i].operand1);
        break;
      case EXP:
        result = exp(operations[i].operand1);
        break;
    }

    printf("Result: %lf\n", result);
  }

  return 0;
}