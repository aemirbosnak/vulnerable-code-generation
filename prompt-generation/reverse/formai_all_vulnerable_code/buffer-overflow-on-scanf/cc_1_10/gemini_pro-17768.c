//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to print the instructions
void print_instructions() {
  printf("Welcome to the Tower of Hanoi game!\n");
  printf("The goal of the game is to move all the disks from the leftmost rod to the rightmost rod.\n");
  printf("You can only move one disk at a time.\n");
  printf("You cannot place a larger disk on top of a smaller disk.\n");
  printf("Good luck!\n");
}

// Function to get the number of disks
int get_num_disks() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);
  return num_disks;
}

// Function to create the rods
void create_rods(int num_disks, char **rods) {
  for (int i = 0; i < 3; i++) {
    rods[i] = malloc(sizeof(char) * num_disks);
    for (int j = 0; j < num_disks; j++) {
      rods[i][j] = ' ';
    }
  }
}

// Function to print the rods
void print_rods(int num_disks, char **rods) {
  for (int i = num_disks - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", rods[j][i]);
    }
    printf("\n");
  }
  printf("---------\n");
}

// Function to move a disk
void move_disk(int num_disks, char **rods, int from_rod, int to_rod) {
  // Find the top disk on the from_rod
  int from_disk = -1;
  for (int i = num_disks - 1; i >= 0; i--) {
    if (rods[from_rod][i] != ' ') {
      from_disk = i;
      break;
    }
  }

  // Find the top disk on the to_rod
  int to_disk = -1;
  for (int i = num_disks - 1; i >= 0; i--) {
    if (rods[to_rod][i] != ' ') {
      to_disk = i;
      break;
    }
  }

  // Check if the move is valid
  if (from_disk == -1 || (to_disk != -1 && rods[from_rod][from_disk] > rods[to_rod][to_disk])) {
    printf("Invalid move!\n");
    return;
  }

  // Move the disk
  rods[to_rod][to_disk + 1] = rods[from_rod][from_disk];
  rods[from_rod][from_disk] = ' ';
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int num_disks, char **rods, int from_rod, int to_rod, int aux_rod) {
  // Base case
  if (num_disks == 1) {
    move_disk(num_disks, rods, from_rod, to_rod);
    return;
  }

  // Recursive case
  solve_tower_of_hanoi(num_disks - 1, rods, from_rod, aux_rod, to_rod);
  move_disk(num_disks, rods, from_rod, to_rod);
  solve_tower_of_hanoi(num_disks - 1, rods, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
  // Print the instructions
  print_instructions();

  // Get the number of disks
  int num_disks = get_num_disks();

  // Create the rods
  char **rods = malloc(sizeof(char *) * 3);
  create_rods(num_disks, rods);

  // Print the initial state of the rods
  print_rods(num_disks, rods);

  // Solve the Tower of Hanoi problem
  solve_tower_of_hanoi(num_disks, rods, 0, 2, 1);

  // Print the final state of the rods
  print_rods(num_disks, rods);

  return 0;
}