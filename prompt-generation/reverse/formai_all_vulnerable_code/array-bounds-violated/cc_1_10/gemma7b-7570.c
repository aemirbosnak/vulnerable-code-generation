//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 24
#define NUM_ROWS 5
#define NUM_COLS 5

int main() {
  int balls_drawn = 0;
  int bingo_card[NUM_ROWS][NUM_COLS] = {{0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

  // Seed the random number generator
  srand(time(NULL));

  // Draw balls
  while (balls_drawn < MAX_BALLS) {
    int number = rand() % MAX_BALLS + 1;

    // Check if the ball has already been drawn
    if (bingo_card[number][number] == 0) {
      // Mark the ball as drawn
      bingo_card[number][number] = 1;

      // Increment the number of balls drawn
      balls_drawn++;

      // Print the number of the ball drawn
      printf("%d ", number);
    }
  }

  // Check if the player has won
  int winner = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (bingo_card[i][j] == 5) {
        winner = 1;
      }
    }
  }

  // Print the winner
  if (winner) {
    printf("Winner!");
  } else {
    printf("No winner");
  }

  return 0;
}