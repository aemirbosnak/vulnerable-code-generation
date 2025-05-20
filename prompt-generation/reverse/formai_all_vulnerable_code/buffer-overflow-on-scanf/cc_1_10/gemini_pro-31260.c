//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 1000
#define MAX_MOVES 200

struct move {
  int from;
  int to;
};

struct stack {
  int size;
  int data[STACK_SIZE];
};

void push(struct stack *s, int value) {
  if (s->size < STACK_SIZE) {
    s->data[s->size++] = value;
  }
}

int pop(struct stack *s) {
  if (s->size > 0) {
    return s->data[--s->size];
  }
  return -1;
}

int main() {
  int n, i, j, k, moves, total_moves;
  struct stack towers[3];

  srand(time(NULL));

  printf("Enter the number of disks: ");
  scanf("%d", &n);

  for (i = 0; i < 3; i++) {
    towers[i].size = 0;
  }

  for (i = n; i >= 1; i--) {
    push(&towers[0], i);
  }

  moves = 0;
  total_moves = 0;

  while (moves < MAX_MOVES) {
    i = rand() % 3;
    j = rand() % 3;
    k = rand() % 3;

    if (i != j && j != k && i != k) {
      if (towers[i].size > 0 && (towers[j].size == 0 || towers[i].data[towers[i].size - 1] < towers[j].data[towers[j].size - 1])) {
        push(&towers[j], pop(&towers[i]));
        moves++;
        total_moves++;
      }
      else if (towers[j].size > 0 && (towers[k].size == 0 || towers[j].data[towers[j].size - 1] < towers[k].data[towers[k].size - 1])) {
        push(&towers[k], pop(&towers[j]));
        moves++;
        total_moves++;
      }
      else if (towers[k].size > 0 && (towers[i].size == 0 || towers[k].data[towers[k].size - 1] < towers[i].data[towers[i].size - 1])) {
        push(&towers[i], pop(&towers[k]));
        moves++;
        total_moves++;
      }
    }

    if (towers[1].size == n && towers[2].size == n) {
      break;
    }
  }

  if (total_moves < MAX_MOVES) {
    printf("The minimum number of moves is %d.\n", total_moves);
  }
  else {
    printf("The puzzle is unsolvable.\n");
  }

  return 0;
}