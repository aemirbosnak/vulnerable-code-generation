//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of disks
#define MAX_DISKS 10

// Define the three towers
#define TOWER_A 1
#define TOWER_B 2
#define TOWER_C 3

// Define the number of moves
#define NUM_MOVES 7

// Define the move function
void move(int disk, int from, int to) {
  printf("Move disk %d from tower %d to tower %d\n", disk, from, to);
}

// Define the recursive Tower of Hanoi function
void tower_of_hanoi(int num_disks, int from, int to, int via) {
  // If there are no disks, then do nothing
  if (num_disks == 0) {
    return;
  }

  // Move the top n - 1 disks from the from tower to the via tower
  tower_of_hanoi(num_disks - 1, from, via, to);

  // Move the nth disk from the from tower to the to tower
  move(num_disks, from, to);

  // Move the n - 1 disks from the via tower to the to tower
  tower_of_hanoi(num_disks - 1, via, to, from);
}

// Define the main function
int main() {
  // Get the number of disks from the user
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // Check if the number of disks is valid
  if (num_disks > MAX_DISKS) {
    printf("The number of disks must be less than or equal to %d\n", MAX_DISKS);
    return 1;
  }

  // Solve the Tower of Hanoi problem
  tower_of_hanoi(num_disks, TOWER_A, TOWER_C, TOWER_B);

  return 0;
}