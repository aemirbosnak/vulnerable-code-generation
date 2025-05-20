//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n; // Number of disks
  int a, b, c; // Tower names
  int steps = 0; // Number of steps taken

  printf("Welcome to the Tower of Hanoi game!\n");
  printf("How many disks do you want to play with? ");
  scanf("%d", &n);

  int towers[3][n]; // Towers: a, b, c

  // Initialize the towers
  for (int i = 0; i < n; i++) {
    towers[a][i] = n - i;
    towers[b][i] = 0;
    towers[c][i] = 0;
  }

  // Print the initial state of the towers
  printf("Initial state of the towers:\n");
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[j][i]);
    }
    printf("\n");
  }

  // Play the game
  while (towers[c][n - 1] != n) {
    // Get the source and destination towers
    printf("Enter the source tower: ");
    scanf("%d", &a);
    printf("Enter the destination tower: ");
    scanf("%d", &b);

    // Check if the move is valid
    if (towers[a][0] == 0 || towers[b][0] > towers[a][0]) {
      printf("Invalid move. Try again.\n");
    } else {
      // Move the disk
      towers[b][0] = towers[a][0];
      towers[a][0] = 0;
      steps++;

      // Print the current state of the towers
      printf("Current state of the towers:\n");
      for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
          printf("%d ", towers[j][i]);
        }
        printf("\n");
      }
    }
  }

  // Print the number of steps taken
  printf("Congratulations! You solved the Tower of Hanoi puzzle in %d steps.\n", steps);

  return 0;
}