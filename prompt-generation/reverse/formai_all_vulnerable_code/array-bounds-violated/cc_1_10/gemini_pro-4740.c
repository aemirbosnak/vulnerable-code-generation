//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
/* Retro Tower of Hanoi example program in C
   with all the bells and whistles. ;) */

#include <stdio.h>
#include <string.h>

// Define macro to clear the screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Define the number of disks
#define NUM_DISKS 5

// Define the three towers
char towers[3][NUM_DISKS + 1];

// Define the move count
int move_count = 0;

// Define the move history
char move_history[1000];

// Initialize the towers
void init_towers() {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < NUM_DISKS; j++) {
      towers[i][j] = ' ';
    }
    towers[i][NUM_DISKS] = '\0';
  }

  for (i = 0; i < NUM_DISKS; i++) {
    towers[0][i] = '*';
  }
}

// Print the towers
void print_towers() {
  int i, j;

  system(CLEAR);

  printf("Move count: %d\n\n", move_count);

  for (i = NUM_DISKS - 1; i >= 0; i--) {
    for (j = 0; j < 3; j++) {
      printf(" %s ", towers[j] + i);
    }
    printf("\n");
  }

  printf("\n");
}

// Move a disk from one tower to another
void move_disk(int from, int to) {
  int i;

  // Find the top disk on the from tower
  for (i = 0; i < NUM_DISKS; i++) {
    if (towers[from][i] != ' ') {
      break;
    }
  }

  // Move the top disk to the to tower
  towers[to][i - 1] = towers[from][i];
  towers[from][i] = ' ';

  // Increment the move count
  move_count++;

  // Update the move history
  sprintf(move_history + strlen(move_history), "%d -> %d\n", from + 1, to + 1);
}

// Solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int num_disks, int from, int to, int via) {
  if (num_disks == 1) {
    move_disk(from, to);
  } else {
    solve_tower_of_hanoi(num_disks - 1, from, via, to);
    move_disk(from, to);
    solve_tower_of_hanoi(num_disks - 1, via, to, from);
  }
}

// Main function
int main() {
  // Initialize the towers
  init_towers();

  // Print the initial state of the towers
  print_towers();

  // Solve the Tower of Hanoi problem
  solve_tower_of_hanoi(NUM_DISKS, 0, 2, 1);

  // Print the final state of the towers
  print_towers();

  // Print the move history
  printf("Move history:\n\n%s", move_history);

  return 0;
}