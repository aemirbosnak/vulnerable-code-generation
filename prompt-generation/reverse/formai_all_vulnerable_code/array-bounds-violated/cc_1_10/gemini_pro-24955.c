//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the towers
int towers[3][3];

// Declare the number of disks
int numDisks;

// Declare the source tower
int sourceTower;

// Declare the destination tower
int destinationTower;

// Declare the temporary tower
int tempTower;

// Initialize the towers
void initializeTowers() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      towers[i][j] = 0;
    }
  }
}

// Print the towers
void printTowers() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[i][j]);
    }
    printf("\n");
  }
}

// Move a disk from one tower to another
void moveDisk(int disk, int source, int destination) {
  // Check if the move is valid
  if (disk > towers[source][0] || disk < 1 || source < 1 || source > 3 || destination < 1 || destination > 3) {
    printf("Invalid move!\n");
    return;
  }

  // Move the disk
  towers[destination][0]++;
  towers[destination][towers[destination][0]] = towers[source][towers[source][0]];
  towers[source][towers[source][0]] = 0;
  towers[source][0]--;
}

// Solve the Tower of Hanoi problem
void solveTowerOfHanoi(int numDisks, int source, int destination, int temp) {
  // Check if the base case is reached
  if (numDisks == 1) {
    moveDisk(1, source, destination);
    return;
  }

  // Move the top n-1 disks from the source tower to the temporary tower
  solveTowerOfHanoi(numDisks - 1, source, temp, destination);

  // Move the nth disk from the source tower to the destination tower
  moveDisk(numDisks, source, destination);

  // Move the n-1 disks from the temporary tower to the destination tower
  solveTowerOfHanoi(numDisks - 1, temp, destination, source);
}

// Get the input from the user
void getInput() {
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  printf("Enter the source tower: ");
  scanf("%d", &sourceTower);

  printf("Enter the destination tower: ");
  scanf("%d", &destinationTower);

  printf("Enter the temporary tower: ");
  scanf("%d", &tempTower);
}

// Main function
int main() {
  // Initialize the towers
  initializeTowers();

  // Get the input from the user
  getInput();

  // Solve the Tower of Hanoi problem
  solveTowerOfHanoi(numDisks, sourceTower, destinationTower, tempTower);

  // Print the towers
  printTowers();

  return 0;
}