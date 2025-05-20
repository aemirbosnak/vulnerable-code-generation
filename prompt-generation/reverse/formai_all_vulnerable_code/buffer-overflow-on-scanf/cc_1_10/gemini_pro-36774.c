//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOWERS 10

struct tower {
  int num_disks;
  int disks[MAX_TOWERS];
};

struct move {
  int from;
  int to;
};

struct stack {
  int top;
  struct move moves[MAX_TOWERS];
};

void push(struct stack *stack, struct move move) {
  stack->moves[stack->top++] = move;
}

struct move pop(struct stack *stack) {
  return stack->moves[--stack->top];
}

int is_empty(struct stack *stack) {
  return stack->top == 0;
}

void solve_tower_of_hanoi(struct tower *towers, int num_disks) {
  struct stack stack;
  stack.top = 0;

  // Move all disks from tower 0 to tower 1
  for (int i = 0; i < num_disks; i++) {
    struct move move = {0, 1};
    push(&stack, move);
    towers[0].disks[i] = -1;
    towers[1].disks[i] = i;
  }

  // Move all disks from tower 1 to tower 2
  for (int i = 0; i < num_disks; i++) {
    struct move move = {1, 2};
    push(&stack, move);
    towers[1].disks[i] = -1;
    towers[2].disks[i] = i;
  }

  // Move all disks from tower 2 to tower 0
  for (int i = 0; i < num_disks; i++) {
    struct move move = {2, 0};
    push(&stack, move);
    towers[2].disks[i] = -1;
    towers[0].disks[i] = i;
  }
}

void print_towers(struct tower *towers, int num_disks) {
  for (int i = 0; i < num_disks; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[j].disks[i]);
    }
    printf("\n");
  }
}

int main() {
  struct tower towers[3];
  int num_disks;

  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  solve_tower_of_hanoi(towers, num_disks);

  printf("The towers after solving the Tower of Hanoi problem:\n");
  print_towers(towers, num_disks);

  return 0;
}