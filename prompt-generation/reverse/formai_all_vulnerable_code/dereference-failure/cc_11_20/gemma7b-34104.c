//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_ROWS 5
#define MAX_COLS 5

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the bingo card
  int **bingoCard = (int **)malloc(MAX_ROWS * sizeof(int *));
  for (int r = 0; r < MAX_ROWS; r++) {
    bingoCard[r] = (int *)malloc(MAX_COLS * sizeof(int));
  }
  for (int r = 0; r < MAX_ROWS; r++) {
    for (int c = 0; c < MAX_COLS; c++) {
      bingoCard[r][c] = 0;
    }
  }

  // Generate the balls
  int balls[MAX_BALLS];
  for (int i = 0; i < MAX_BALLS; i++) {
    balls[i] = rand() % MAX_BALLS + 1;
  }

  // Play the game
  int won = 0;
  for (int i = 0; i < MAX_BALLS; i++) {
    for (int r = 0; r < MAX_ROWS; r++) {
      for (int c = 0; c < MAX_COLS; c++) {
        if (bingoCard[r][c] == balls[i]) {
          bingoCard[r][c] = -1;
        }
      }
    }

    // Check if the player has won
    won = 1;
    for (int r = 0; r < MAX_ROWS; r++) {
      if (bingoCard[r][0] == -1 && bingoCard[r][1] == -1 && bingoCard[r][2] == -1) {
        won = 0;
      }
    }

    // If the player has won, print the winning message
    if (won) {
      printf("Congratulations! You have won!\n");
      break;
    }
  }

  // Free the memory
  for (int r = 0; r < MAX_ROWS; r++) {
    free(bingoCard[r]);
  }
  free(bingoCard);

  return 0;
}