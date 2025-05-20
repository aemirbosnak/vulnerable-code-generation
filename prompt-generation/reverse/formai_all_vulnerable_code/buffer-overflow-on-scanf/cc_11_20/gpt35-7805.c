//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main() {
  // Initialize game board
  char board[ROWS][COLS] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
  };

  // Initialize player position and score
  int playerRow = 4;
  int playerCol = 5;
  int score = 0;

  // Set up random number generator
  srand(time(NULL));

  // Loop until game is over
  while (1) {
    // Print board and player score
    printf("Score: %d\n\n", score);
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }

    // Move player left or right
    char move;
    printf("Move left (L) or right (R): ");
    scanf(" %c", &move);
    if (move == 'L') {
      if (playerCol > 0) {
        board[playerRow][playerCol] = '*';
        playerCol--;
      }
    } else if (move == 'R') {
      if (playerCol < COLS - 1) {
        board[playerRow][playerCol] = '*';
        playerCol++;
      }
    }

    // Add enemy to board
    int enemyRow = rand() % 5;
    int enemyCol = rand() % 10;
    board[enemyRow][enemyCol] = 'E';

    // Check for collisions
    if (enemyRow == playerRow && enemyCol == playerCol) {
      printf("\nYou were hit by an enemy!\n");
      break;
    }

    // Increase score
    score++;

    // Remove enemy from board
    board[enemyRow][enemyCol] = '*';

    // Sleep for 1 second
    printf("\n");
    for (int i = 0; i < 50; i++) {
      printf(".");
      fflush(stdout);
      usleep(20000);
    }
    printf("\n\n");

    // Check for end of game
    int emptyCount = 0;
    for (int i = 0; i < COLS; i++) {
      if (board[0][i] == '*') {
        emptyCount++;
      }
    }
    if (emptyCount == COLS) {
      printf("You won the game with a score of %d!\n", score);
      break;
    }
  }

  return 0;
}