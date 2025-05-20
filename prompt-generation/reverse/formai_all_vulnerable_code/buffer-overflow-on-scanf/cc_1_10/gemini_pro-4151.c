//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

const char* colors[] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

typedef struct {
  int color;
  int size;
} disk_t;

typedef struct {
  disk_t* disks;
  int num_disks;
} tower_t;

void print_disk(disk_t disk) {
  printf("%s disk of size %d\n", colors[disk.color], disk.size);
}

void print_tower(tower_t tower) {
  for (int i = tower.num_disks - 1; i >= 0; i--) {
    print_disk(tower.disks[i]);
  }
}

void move_disk(tower_t* from, tower_t* to) {
  disk_t disk = from->disks[from->num_disks - 1];
  from->num_disks--;
  to->num_disks++;
  to->disks = realloc(to->disks, sizeof(disk_t) * to->num_disks);
  to->disks[to->num_disks - 1] = disk;
}

void tower_of_hanoi(int num_disks, tower_t* from, tower_t* to, tower_t* aux) {
  if (num_disks == 1) {
    move_disk(from, to);
  } else {
    tower_of_hanoi(num_disks - 1, from, aux, to);
    move_disk(from, to);
    tower_of_hanoi(num_disks - 1, aux, to, from);
  }
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  tower_t from = {malloc(sizeof(disk_t) * num_disks), 0};
  for (int i = 0; i < num_disks; i++) {
    from.disks[i].color = i;
    from.disks[i].size = num_disks - i;
    from.num_disks++;
  }

  tower_t to = {malloc(sizeof(disk_t) * num_disks), 0};
  tower_t aux = {malloc(sizeof(disk_t) * num_disks), 0};

  printf("Initial state:\n");
  print_tower(from);
  printf("\n");

  tower_of_hanoi(num_disks, &from, &to, &aux);

  printf("Final state:\n");
  print_tower(to);
  printf("\n");

  return 0;
}