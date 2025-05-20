//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
// Tower of Hanoi problem
#include <stdio.h>
#include <stdlib.h>

// define the number of disks
#define N 4

// define the disks
struct disk {
  int size;
  struct disk *left;
  struct disk *right;
};

// define the towers
struct tower {
  struct disk *disks;
};

// define the moves
enum move {
  MOVE_LEFT,
  MOVE_RIGHT
};

// define the game state
struct game_state {
  struct tower towers[3];
  enum move move;
  int n_moves;
};

// move a disk
void move_disk(struct game_state *state, int from_tower, int to_tower) {
  // get the top disk from the from tower
  struct disk *top_disk = state->towers[from_tower].disks;

  // move the disk to the to tower
  state->towers[to_tower].disks = top_disk;

  // update the move and number of moves
  state->move = (state->move == MOVE_LEFT) ? MOVE_RIGHT : MOVE_LEFT;
  state->n_moves++;
}

// solve the game
void solve_game(struct game_state *state) {
  // solve the game
  for (int i = 0; i < N; i++) {
    // move the disk from the from tower to the to tower
    move_disk(state, 0, 2);

    // move the disk from the from tower to the to tower
    move_disk(state, 1, 0);
  }
}

// print the game state
void print_game_state(struct game_state *state) {
  // print the disks on the towers
  for (int i = 0; i < 3; i++) {
    struct disk *disk = state->towers[i].disks;
    while (disk != NULL) {
      printf("%d ", disk->size);
      disk = disk->right;
    }
    printf("\n");
  }

  // print the moves
  printf("Moves: %d\n", state->n_moves);
}

int main() {
  // create the game state
  struct game_state state;
  state.towers[0].disks = NULL;
  state.towers[1].disks = NULL;
  state.towers[2].disks = NULL;
  state.move = MOVE_LEFT;
  state.n_moves = 0;

  // add the disks to the towers
  for (int i = N; i > 0; i--) {
    struct disk *disk = (struct disk *)malloc(sizeof(struct disk));
    disk->size = i;
    disk->left = NULL;
    disk->right = NULL;
    state.towers[0].disks = disk;
  }

  // solve the game
  solve_game(&state);

  // print the game state
  print_game_state(&state);

  return 0;
}