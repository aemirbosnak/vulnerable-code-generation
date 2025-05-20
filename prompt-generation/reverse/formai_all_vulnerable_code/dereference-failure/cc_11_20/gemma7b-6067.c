//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_ROWS 5
#define MAX_COLS 5

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a bingo card
  int **bingoCard = (int **)malloc(MAX_ROWS * sizeof(int *));
  for (int r = 0; r < MAX_ROWS; r++) {
    bingoCard[r] = (int *)malloc(MAX_COLS * sizeof(int));
    for (int c = 0; c < MAX_COLS; c++) {
      bingoCard[r][c] = 0;
    }
  }

  // Generate the bingo balls
  int balls[MAX_BALLS] = {0};
  for (int i = 0; i < MAX_BALLS; i++) {
    balls[i] = rand() % MAX_BALLS + 1;
  }

  // Mark the bingo card
  for (int i = 0; i < MAX_BALLS; i++) {
    for (int r = 0; r < MAX_ROWS; r++) {
      for (int c = 0; c < MAX_COLS; c++) {
        if (bingoCard[r][c] == balls[i]) {
          bingoCard[r][c] = 2;
        }
      }
    }
  }

  // Check for bingo
  int bingo = 0;
  for (int r = 0; r < MAX_ROWS; r++) {
    if (bingoCard[r][0] == 2 && bingoCard[r][1] == 2 && bingoCard[r][2] == 2) {
      bingo = 1;
    }
  }

  // Print the results
  if (bingo) {
    printf("Bingo!\n");
  } else {
    printf("Sorry, no bingo.\n");
  }

  // Free the memory
  for (int r = 0; r < MAX_ROWS; r++) {
    free(bingoCard[r]);
  }
  free(bingoCard);

  return 0;
}