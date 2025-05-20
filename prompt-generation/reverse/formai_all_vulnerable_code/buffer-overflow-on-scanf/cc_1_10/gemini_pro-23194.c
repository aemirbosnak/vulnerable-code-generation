//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>

// Function to print the instructions
void printInstructions() {
  printf("Welcome to the Tower of Hanoi!\n\n");
  printf("The objective of the game is to move all the disks from the leftmost tower to the rightmost tower, using the middle tower as an intermediate.\n");
  printf("You can only move one disk at a time, and you cannot place a larger disk on top of a smaller disk.\n\n");
  printf("Enter the number of disks you want to play with (1-9): ");
}

// Function to get the user's input
int getInput() {
  int numDisks;
  scanf("%d", &numDisks);
  while (numDisks < 1 || numDisks > 9) {
    printf("Invalid input. Please enter a number between 1 and 9: ");
    scanf("%d", &numDisks);
  }
  return numDisks;
}

// Function to move a disk from one tower to another
void moveDisk(int disk, int fromTower, int toTower) {
  printf("Move disk %d from tower %d to tower %d\n", disk, fromTower, toTower);
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int numDisks, int fromTower, int toTower, int auxTower) {
  if (numDisks == 1) {
    moveDisk(1, fromTower, toTower);
    return;
  }
  solveTowerOfHanoi(numDisks - 1, fromTower, auxTower, toTower);
  moveDisk(numDisks, fromTower, toTower);
  solveTowerOfHanoi(numDisks - 1, auxTower, toTower, fromTower);
}

// Main function
int main() {
  // Print the instructions
  printInstructions();
  
  // Get the user's input
  int numDisks = getInput();
  
  // Solve the Tower of Hanoi problem
  solveTowerOfHanoi(numDisks, 1, 3, 2);
  
  return 0;
}