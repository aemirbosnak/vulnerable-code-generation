//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the towers
void printTowers(int numDisks, int towers[][numDisks]) {
  for (int i = numDisks - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int numDisks, int towers[][numDisks], int fromTower, int toTower) {
  // Check if the move is valid
  if (towers[numDisks - 1][fromTower] > towers[numDisks - 1][toTower]) {
    printf("Invalid move!\n");
    return;
  }

  // Move the disk
  towers[numDisks - 1][toTower] = towers[numDisks - 1][fromTower];
  towers[numDisks - 1][fromTower] = 0;

  // Print the current state of the towers
  printTowers(numDisks, towers);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int numDisks, int towers[][numDisks]) {
  // Base case: no disks to move
  if (numDisks == 1) {
    moveDisk(numDisks, towers, 0, 2);
    return;
  }

  // Recursive case: move the top n-1 disks to the middle tower
  towerOfHanoi(numDisks - 1, towers);

  // Move the nth disk to the destination tower
  moveDisk(numDisks, towers, 0, 2);

  // Recursive case: move the top n-1 disks from the middle tower to the destination tower
  towerOfHanoi(numDisks - 1, towers);
}

int main() {
  // Get the number of disks from the user
  int numDisks;
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  // Create the towers
  int towers[numDisks][3];
  for (int i = 0; i < numDisks; i++) {
    towers[i][0] = i + 1;
    towers[i][1] = 0;
    towers[i][2] = 0;
  }

  // Print the initial state of the towers
  printTowers(numDisks, towers);

  // Solve the Tower of Hanoi problem
  towerOfHanoi(numDisks, towers);

  return 0;
}