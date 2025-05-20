//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the current state of the towers.
void print_towers(int num_disks, int towers[3][num_disks]) {
  // Loop through each disk.
  for (int i = 0; i < num_disks; i++) {
    // Loop through each tower.
    for (int j = 0; j < 3; j++) {
      // Print the disk size on the current tower.
      printf("%d ", towers[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to move a disk from one tower to another.
void move_disk(int num_disks, int towers[3][num_disks], int from_tower, int to_tower) {
  // Get the size of the disk to move.
  int disk_size = towers[from_tower][num_disks - 1];

  // Move the disk to the new tower.
  towers[to_tower][num_disks - 1] = disk_size;
  towers[from_tower][num_disks - 1] = 0;

  // Print the current state of the towers.
  print_towers(num_disks, towers);
}

// Function to solve the Tower of Hanoi problem.
void tower_of_hanoi(int num_disks, int towers[3][num_disks], int from_tower, int to_tower, int aux_tower) {
  // Base case: Only one disk left.
  if (num_disks == 1) {
    move_disk(num_disks, towers, from_tower, to_tower);
    return;
  }

  // Recursive case: Move the top n-1 disks from the from tower to the aux tower.
  tower_of_hanoi(num_disks - 1, towers, from_tower, aux_tower, to_tower);

  // Move the largest disk from the from tower to the to tower.
  move_disk(num_disks, towers, from_tower, to_tower);

  // Recursive case: Move the n-1 disks from the aux tower to the to tower.
  tower_of_hanoi(num_disks - 1, towers, aux_tower, to_tower, from_tower);
}

int main() {
  // Get the number of disks.
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // Create a 2D array to represent the towers.
  int towers[3][num_disks];

  // Initialize the towers.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < num_disks; j++) {
      towers[i][j] = 0;
    }
  }

  // Place the disks on the first tower.
  for (int i = 0; i < num_disks; i++) {
    towers[0][i] = num_disks - i;
  }

  // Print the initial state of the towers.
  print_towers(num_disks, towers);

  // Solve the Tower of Hanoi problem.
  tower_of_hanoi(num_disks, towers, 0, 2, 1);

  return 0;
}