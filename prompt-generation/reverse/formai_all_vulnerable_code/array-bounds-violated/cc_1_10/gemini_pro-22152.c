//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int main() {
  int grid[SIZE][SIZE];
  int revealed[SIZE][SIZE];
  int i, j, x, y, moves, revealed_count;
  srand(time(NULL));

  // Initialize the grid with random numbers
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      grid[i][j] = rand() % 10;
      revealed[i][j] = 0;
    }
  }

  // Print the welcome message
  printf("Welcome to the Memory Game!\n\n");

  // Initialize the game state
  moves = 0;
  revealed_count = 0;

  // Main game loop
  while (revealed_count < SIZE * SIZE) {
    // Print the grid
    printf("  ");
    for (i = 0; i < SIZE; i++) {
      printf("%2d ", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
      printf("%2d ", i);
      for (j = 0; j < SIZE; j++) {
        if (revealed[i][j]) {
          printf("%2d ", grid[i][j]);
        } else {
          printf("  ");
        }
      }
      printf("\n");
    }

    // Get the player's input
    printf("Enter the coordinates of the first card (row, column): ");
    scanf("%d %d", &x, &y);

    // Reveal the first card
    revealed[x][y] = 1;

    // Get the player's input
    printf("Enter the coordinates of the second card (row, column): ");
    scanf("%d %d", &x, &y);

    // Reveal the second card
    revealed[x][y] = 1;

    // Check if the cards match
    if (grid[x][y] == grid[i][j]) {
      printf("Match!\n");
      revealed_count += 2;
    } else {
      printf("No match.\n");
      revealed[x][y] = 0;
      revealed[i][j] = 0;
    }

    // Increment the number of moves
    moves++;
  }

  // Print the game results
  printf("Congratulations! You won in %d moves.\n", moves);

  return 0;
}