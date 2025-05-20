//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct _stack {
  int top;
  int size;
  int *array;
} Stack;

Stack *create_stack(int size) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = -1;
  stack->size = size;
  stack->array = (int *)malloc(sizeof(int) * size);
  return stack;
}

void push(Stack *stack, int data) {
  if (stack->top == stack->size - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack->array[stack->top--];
}

int peek(Stack *stack) {
  if (stack->top == -1) {
    return -1;
  }
  return stack->array[stack->top];
}

void print_stack(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

void tower_of_hanoi(int n, Stack *source, Stack *auxiliary, Stack *destination) {
  if (n == 1) {
    push(destination, pop(source));
    return;
  }
  tower_of_hanoi(n - 1, source, destination, auxiliary);
  push(destination, pop(source));
  tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  Stack *source = create_stack(MAX_STACK_SIZE);
  Stack *auxiliary = create_stack(MAX_STACK_SIZE);
  Stack *destination = create_stack(MAX_STACK_SIZE);

  for (int i = n; i >= 1; i--) {
    push(source, i);
  }

  tower_of_hanoi(n, source, auxiliary, destination);

  printf("The disks have been moved from the source stack to the destination stack:\n");
  print_stack(destination);

  return 0;
}