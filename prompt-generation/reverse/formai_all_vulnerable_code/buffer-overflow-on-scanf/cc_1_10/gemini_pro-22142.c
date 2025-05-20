//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int top;
  int capacity;
  int* array;
} Stack;

Stack* createStack(int capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

int isFull(Stack* stack) {
  return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
  return stack->top == -1;
}

void push(Stack* stack, int item) {
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
  if (isEmpty(stack))
    return -1;
  return stack->array[stack->top--];
}

int peek(Stack* stack) {
  if (isEmpty(stack))
    return -1;
  return stack->array[stack->top];
}

void move(Stack* from, Stack* to) {
  int item = pop(from);
  push(to, item);
}

void towerOfHanoi(int n, Stack* from, Stack* to, Stack* aux) {
  if (n == 1) {
    move(from, to);
    return;
  }
  towerOfHanoi(n - 1, from, aux, to);
  move(from, to);
  towerOfHanoi(n - 1, aux, to, from);
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  Stack* from = createStack(n);
  Stack* to = createStack(n);
  Stack* aux = createStack(n);
  for (int i = n; i >= 1; i--)
    push(from, i);
  towerOfHanoi(n, from, to, aux);
  printf("The disks have been moved from the first tower to the third tower.\n");
  return 0;
}