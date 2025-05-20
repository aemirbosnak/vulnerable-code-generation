//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

void push(Stack *stack, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
}

int pop(Stack *stack) {
  if (stack->top == NULL) {
    return -1;
  }
  Node *temp = stack->top;
  int data = temp->data;
  stack->top = temp->next;
  free(temp);
  return data;
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  Stack *towers[3];
  for (int i = 0; i < 3; i++) {
    towers[i] = (Stack *)malloc(sizeof(Stack));
    towers[i]->top = NULL;
  }

  for (int i = n; i > 0; i--) {
    push(towers[0], i);
  }

  int moves = 0;
  while (towers[2]->top == NULL) {
    int from, to;
    printf("Enter the from tower and to tower: ");
    scanf("%d %d", &from, &to);

    if (from < 1 || from > 3 || to < 1 || to > 3) {
      printf("Invalid tower numbers\n");
      continue;
    }

    int from_disk = pop(towers[from - 1]);
    if (from_disk == -1) {
      printf("No disk on the from tower\n");
      continue;
    }

    int to_disk = pop(towers[to - 1]);
    if (to_disk != -1 && from_disk > to_disk) {
      printf("Cannot move a larger disk onto a smaller disk\n");
      push(towers[from - 1], from_disk);
      continue;
    }

    push(towers[to - 1], from_disk);
    moves++;
  }

  printf("The towers are now:\n");
  for (int i = 0; i < 3; i++) {
    Node *temp = towers[i]->top;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }

  printf("The number of moves required: %d\n", moves);

  for (int i = 0; i < 3; i++) {
    Node *temp = towers[i]->top;
    while (temp != NULL) {
      Node *next = temp->next;
      free(temp);
      temp = next;
    }
    free(towers[i]);
  }

  return 0;
}