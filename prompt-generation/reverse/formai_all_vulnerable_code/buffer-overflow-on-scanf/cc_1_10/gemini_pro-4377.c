//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Matrix to represent the towers
char towers[3][20];

// Function to move a disk from one tower to another
void move(int disk, int from, int to) {
  // Move the disk from the 'from' tower to the 'to' tower
  towers[to][disk - 1] = towers[from][disk - 1];

  // Clear the 'from' tower
  towers[from][disk - 1] = ' ';
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
  // Base case: if there is only one disk, move it from the 'from' tower to the 'to' tower
  if (n == 1) {
    move(n, from, to);
    return;
  }

  // Recursive case: move the top n - 1 disks from the 'from' tower to the 'aux' tower 
  hanoi(n - 1, from, aux, to);

  // Move the remaining disk from the 'from' tower to the 'to' tower
  move(n, from, to);

  // Recursive case: move the n - 1 disks from the 'aux' tower to the 'to' tower
  hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
  // Number of disks
  int n;

  // Get the number of disks from the user
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  // Initialize the towers
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 20; j++) {
      towers[i][j] = ' ';
    }
  }

  // Place the disks on the 'from' tower
  for (int i = 0; i < n; i++) {
    towers[0][i] = 'X';
  }

  // Solve the Tower of Hanoi problem
  hanoi(n, 0, 2, 1);

  // Print the towers
  for (int i = 0; i < 3; i++) {
    printf("Tower %d: ", i);
    for (int j = 0; j < 20; j++) {
      printf("%c", towers[i][j]);
    }
    printf("\n");
  }

  return 0;
}