//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the bingo board
  int bingoBoard[BINGO_SIZE][BINGO_SIZE];
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      bingoBoard[i][j] = rand() % 100 + 1;
    }
  }

  // Print the bingo board
  printf("Bingo Board:\n");
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      printf("%d ", bingoBoard[i][j]);
    }
    printf("\n");
  }

  // Get the player's numbers
  int playerNumbers[BINGO_SIZE];
  printf("Enter your numbers (5 numbers between 1 and 100): ");
  for (int i = 0; i < BINGO_SIZE; i++) {
    scanf("%d", &playerNumbers[i]);
  }

  // Check if the player has won
  int matches = 0;
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      if (bingoBoard[i][j] == playerNumbers[i]) {
        matches++;
      }
    }
  }

  // Print the results
  if (matches == BINGO_SIZE) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Sorry, you didn't win.\n");
  }

  return 0;
}