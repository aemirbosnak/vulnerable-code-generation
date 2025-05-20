//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct tower {
  int num_disks;
  int *disks;
} tower;

void print_tower(tower t) {
  for (int i = 0; i < t.num_disks; i++) {
    printf("%d ", t.disks[i]);
  }
  printf("\n");
}

void move_disk(tower *from, tower *to) {
  int disk = from->disks[from->num_disks - 1];
  from->num_disks--;
  to->disks[to->num_disks] = disk;
  to->num_disks++;
}

void towers_of_hanoi(tower *from, tower *to, tower *aux, int num_disks) {
  if (num_disks == 1) {
    move_disk(from, to);
    return;
  }

  towers_of_hanoi(from, aux, to, num_disks - 1);
  move_disk(from, to);
  towers_of_hanoi(aux, to, from, num_disks - 1);
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  tower from = {num_disks, malloc(sizeof(int) * num_disks)};
  for (int i = 0; i < num_disks; i++) {
    from.disks[i] = num_disks - i;
  }

  tower to = {0, malloc(sizeof(int) * num_disks)};
  tower aux = {0, malloc(sizeof(int) * num_disks)};

  towers_of_hanoi(&from, &to, &aux, num_disks);

  printf("The disks have been moved to the destination tower:\n");
  print_tower(to);

  free(from.disks);
  free(to.disks);
  free(aux.disks);

  return 0;
}