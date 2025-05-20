//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void print_towers(int num_disks, int towers[num_disks][3]) {
  for (int i = 0; i < num_disks; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[i][j]);
    }
    printf("\n");
  }
}

// Function to move a single disk from one tower to another
void move_disk(int num_disks, int towers[num_disks][3], int from_tower, int to_tower) {
  // Check if the move is valid
  if (towers[num_disks - 1][from_tower] > towers[num_disks - 1][to_tower]) {
    printf("Invalid move: Cannot move a larger disk onto a smaller disk.\n");
    return;
  }

  // Move the disk
  towers[num_disks - 1][to_tower] = towers[num_disks - 1][from_tower];
  towers[num_disks - 1][from_tower] = 0;
}

// Function to solve the Tower of Hanoi problem using recursion
void solve_tower_of_hanoi(int num_disks, int towers[num_disks][3], int from_tower, int to_tower, int via_tower) {
  // Base case: No more disks to move
  if (num_disks == 0) {
    return;
  }

  // Recursive case: Move the top n-1 disks from the source tower to the via tower
  solve_tower_of_hanoi(num_disks - 1, towers, from_tower, via_tower, to_tower);

  // Move the bottom disk from the source tower to the destination tower
  move_disk(num_disks, towers, from_tower, to_tower);

  // Recursive case: Move the top n-1 disks from the via tower to the destination tower
  solve_tower_of_hanoi(num_disks - 1, towers, via_tower, to_tower, from_tower);
}

int main() {
  // Get the number of disks from the user
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // Create an array to represent the towers
  int towers[num_disks][3];

  // Initialize the towers
  for (int i = 0; i < num_disks; i++) {
    for (int j = 0; j < 3; j++) {
      towers[i][j] = 0;
    }
  }

  // Place the disks on the first tower
  for (int i = 0; i < num_disks; i++) {
    towers[i][0] = num_disks - i;
  }

  // Solve the Tower of Hanoi problem
  solve_tower_of_hanoi(num_disks, towers, 0, 2, 1);

  // Print the final state of the towers
  print_towers(num_disks, towers);

  return 0;
}