//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
  int num_disks;
  int from_rod;
  int to_rod;
  int via_rod;
} move_t;

void print_move(move_t *move) {
  printf("Move disk %d from rod %d to rod %d\n", move->num_disks, move->from_rod, move->to_rod);
}

int generate_moves(int num_disks, int from_rod, int to_rod, int via_rod, move_t *moves) {
  if (num_disks == 1) {
    moves[0].num_disks = 1;
    moves[0].from_rod = from_rod;
    moves[0].to_rod = to_rod;
    moves[0].via_rod = via_rod;
    return 1;
  }

  int num_moves = generate_moves(num_disks - 1, from_rod, via_rod, to_rod, moves);
  moves[num_moves].num_disks = num_disks;
  moves[num_moves].from_rod = from_rod;
  moves[num_moves].to_rod = to_rod;
  moves[num_moves].via_rod = via_rod;
  num_moves++;
  num_moves += generate_moves(num_disks - 1, via_rod, to_rod, from_rod, moves + num_moves);
  return num_moves;
}

int main() {
  int num_disks;
  move_t moves[MAX_DISKS * 2];

  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  int num_moves = generate_moves(num_disks, 1, 3, 2, moves);

  printf("The moves are:\n");
  for (int i = 0; i < num_moves; i++) {
    print_move(&moves[i]);
  }

  return 0;
}