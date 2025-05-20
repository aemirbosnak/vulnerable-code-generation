//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef struct {
  char operation;
  float value;
} Operand;

Operand stack[MAX_STACK_SIZE];
int stack_size = 0;

void push(Operand op) {
  stack[stack_size++] = op;
}

Operand pop() {
  return stack[--stack_size];
}

void clear_stack() {
  stack_size = 0;
}

int main() {
  char input[MAX_INPUT_SIZE];
  float result;

  while (1) {
    printf("Enter an expression: ");
    scanf("%s", input);

    if (input[0] == 'q') {
      break;
    }

    if (input[0] == 'c') {
      clear_stack();
      continue;
    }

    if (input[0] == 's') {
      if (stack_size < 2) {
        printf("Error: not enough operands on the stack\n");
        continue;
      }
      Operand op2 = pop();
      Operand op1 = pop();
      Operand op_result;
      switch (op1.operation) {
        case '+':
          op_result.value = op1.value + op2.value;
          break;
        case '-':
          op_result.value = op1.value - op2.value;
          break;
        case '*':
          op_result.value = op1.value * op2.value;
          break;
        case '/':
          op_result.value = op1.value / op2.value;
          break;
        default:
          printf("Error: unknown operation '%c'\n", op1.operation);
          continue;
      }
      push(op_result);
      continue;
    }

    if (input[0] == 'p') {
      if (stack_size < 1) {
        printf("Error: not enough operands on the stack\n");
        continue;
      }
      Operand op = pop();
      printf("Result: %f\n", op.value);
      continue;
    }

    if (input[0] == 'r') {
      if (stack_size < 1) {
        printf("Error: not enough operands on the stack\n");
        continue;
      }
      Operand op = pop();
      printf("Result: %f\n", op.value);
      continue;
    }

    if (input[0] == 'q') {
      break;
    }

    if (input[0] == '=') {
      if (stack_size < 1) {
        printf("Error: not enough operands on the stack\n");
        continue;
      }
      Operand op = pop();
      printf("Result: %f\n", op.value);
      continue;
    }

    Operand op;
    op.operation = input[0];
    op.value = atof(&input[1]);
    push(op);
  }

  return 0;
}