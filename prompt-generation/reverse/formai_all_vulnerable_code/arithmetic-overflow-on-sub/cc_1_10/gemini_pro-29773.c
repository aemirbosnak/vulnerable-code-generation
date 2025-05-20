//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Tower of Hanoi problem solver

// A tower is represented as an array of discs, where each disc is represented by a number.
// The first disc is at the bottom of the array, and the last disc is at the top.
struct tower {
  int *discs;
  int num_discs;
};

// Create a new tower with the given number of discs.
struct tower *create_tower(int num_discs) {
  struct tower *tower = malloc(sizeof(struct tower));
  tower->discs = malloc(sizeof(int) * num_discs);
  tower->num_discs = num_discs;
  for (int i = 0; i < num_discs; i++) {
    tower->discs[i] = num_discs - i;
  }
  return tower;
}

// Free the memory allocated for the tower.
void free_tower(struct tower *tower) {
  free(tower->discs);
  free(tower);
}

// Print the tower.
void print_tower(struct tower *tower) {
  for (int i = 0; i < tower->num_discs; i++) {
    printf("%d ", tower->discs[i]);
  }
  printf("\n");
}

// Move the top disc from the source tower to the destination tower.
void move_disc(struct tower *source, struct tower *destination) {
  assert(source->num_discs > 0);
  assert(destination->num_discs == 0 || destination->discs[destination->num_discs - 1] > source->discs[source->num_discs - 1]);
  destination->discs[destination->num_discs] = source->discs[source->num_discs - 1];
  destination->num_discs++;
  source->num_discs--;
}

// Solve the Tower of Hanoi problem.
void solve_tower_of_hanoi(int num_discs, struct tower *source, struct tower *destination, struct tower *auxiliary) {
  if (num_discs == 1) {
    move_disc(source, destination);
  } else {
    solve_tower_of_hanoi(num_discs - 1, source, auxiliary, destination);
    move_disc(source, destination);
    solve_tower_of_hanoi(num_discs - 1, auxiliary, destination, source);
  }
}

int main() {
  int num_discs;
  printf("Enter the number of discs: ");
  scanf("%d", &num_discs);

  struct tower *source = create_tower(num_discs);
  struct tower *destination = create_tower(0);
  struct tower *auxiliary = create_tower(0);

  printf("Initial state:\n");
  print_tower(source);
  print_tower(destination);
  print_tower(auxiliary);

  solve_tower_of_hanoi(num_discs, source, destination, auxiliary);

  printf("Final state:\n");
  print_tower(source);
  print_tower(destination);
  print_tower(auxiliary);

  free_tower(source);
  free_tower(destination);
  free_tower(auxiliary);

  return 0;
}