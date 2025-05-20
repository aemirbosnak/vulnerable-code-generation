//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *data;
  int top;
  int size;
} Stack;

Stack *stack_init(int size) {
  Stack *stack = malloc(sizeof(Stack));
  stack->data = malloc(sizeof(int) * size);
  stack->top = -1;
  stack->size = size;
  return stack;
}

void stack_push(Stack *stack, int value) {
  if (stack->top == stack->size - 1) {
    printf("Stack overflow!\n");
    return;
  }
  stack->data[++stack->top] = value;
}

int stack_pop(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow!\n");
    return -1;
  }
  return stack->data[stack->top--];
}

int stack_peek(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow!\n");
    return -1;
  }
  return stack->data[stack->top];
}

int main() {
  int n, i, j, k;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  Stack *stacks[3];
  for (i = 0; i < 3; i++) {
    stacks[i] = stack_init(n);
  }

  // Initialize the stacks
  for (i = n; i >= 1; i--) {
    stack_push(stacks[0], i);
  }

  // Print the initial state of the stacks
  printf("\nInitial state of the stacks:\n");
  for (i = 0; i < 3; i++) {
    printf("Stack %d: ", i + 1);
    for (j = 0; j <= stacks[i]->top; j++) {
      printf("%d ", stacks[i]->data[j]);
    }
    printf("\n");
  }

  // Solve the Tower of Hanoi problem
  for (i = 1; i <= n; i++) {
    // Move the top disk from the source to the intermediate stack
    j = (i % 2 == 1) ? 0 : 1;
    k = (i % 2 == 1) ? 1 : 0;
    while (stack_peek(stacks[j]) != i) {
      stack_push(stacks[k], stack_pop(stacks[j]));
    }
    stack_pop(stacks[j]);

    // Print the current state of the stacks
    printf("\nCurrent state of the stacks after step %d:\n", i);
    for (j = 0; j < 3; j++) {
      printf("Stack %d: ", j + 1);
      for (k = 0; k <= stacks[j]->top; k++) {
        printf("%d ", stacks[j]->data[k]);
      }
      printf("\n");
    }

    // Move the top disk from the intermediate to the destination stack
    j = (i % 2 == 1) ? 2 : (i % 2 == 0) ? 0 : 1;
    stack_push(stacks[j], stack_pop(stacks[k]));

    // Print the current state of the stacks
    printf("\nCurrent state of the stacks after step %d:\n", i);
    for (j = 0; j < 3; j++) {
      printf("Stack %d: ", j + 1);
      for (k = 0; k <= stacks[j]->top; k++) {
        printf("%d ", stacks[j]->data[k]);
      }
      printf("\n");
    }
  }

  // Free the stacks
  for (i = 0; i < 3; i++) {
    free(stacks[i]->data);
    free(stacks[i]);
  }

  return 0;
}