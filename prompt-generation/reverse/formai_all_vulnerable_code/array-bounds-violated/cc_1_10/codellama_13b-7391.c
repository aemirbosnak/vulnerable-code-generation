//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 100
#define MAX_TOWERS 3

typedef struct {
  int disks[MAX_DISKS];
  int top_disk;
} Tower;

Tower towers[MAX_TOWERS];

void init_towers() {
  for (int i = 0; i < MAX_TOWERS; i++) {
    towers[i].top_disk = -1;
  }
}

bool is_empty(int tower) {
  return towers[tower].top_disk == -1;
}

bool is_full(int tower) {
  return towers[tower].top_disk == MAX_DISKS - 1;
}

void move_disk(int from, int to) {
  if (!is_empty(from) && !is_full(to)) {
    towers[to].disks[++towers[to].top_disk] = towers[from].disks[towers[from].top_disk--];
  }
}

void print_towers() {
  for (int i = 0; i < MAX_TOWERS; i++) {
    printf("Tower %d: ", i + 1);
    for (int j = 0; j <= towers[i].top_disk; j++) {
      printf("%d ", towers[i].disks[j]);
    }
    printf("\n");
  }
}

int main() {
  init_towers();

  int n = 4;
  int from = 1;
  int to = 2;
  int via = 3;

  for (int i = n; i > 0; i--) {
    towers[from].disks[++towers[from].top_disk] = i;
  }

  print_towers();

  while (towers[from].top_disk != -1) {
    if (towers[from].top_disk == 1) {
      move_disk(from, to);
    } else if (towers[from].top_disk == 2) {
      move_disk(from, via);
      move_disk(via, to);
    } else {
      move_disk(from, to);
      move_disk(from, via);
      move_disk(via, to);
    }
    print_towers();
  }

  return 0;
}