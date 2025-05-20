//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int n) {
  int i, j, score = 0, target = rand() % n;
  char board[n][n];

  // Initialize the board
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the target
  board[target][target] = 'T';

  // Get the player's move
  printf("Enter your move (x,y): ");
  scanf("%d %d", &i, &j);

  // Check if the move is valid
  if (i < 0 || i >= n || j < 0 || j >= n) {
    printf("Invalid move.\n");
  } else if (board[i][j] != ' ') {
    printf("That spot is already taken.\n");
  } else if (board[i][j] == 'T') {
    printf("You win!\n");
    score = 1;
  } else {
    printf("Invalid move.\n");
  }

  // Print the board
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  // End the game
  if (score) {
    printf("Your score: %d\n", score);
  } else {
    printf("Game over.\n");
  }
}

int main() {
  play_game(5);
  return 0;
}