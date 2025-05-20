//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];

int main() {
  int i, j, k, l, m, n;
  int player = 1;
  int count = 0;
  int winner = 0;

  // Initialize the board
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Game loop
  while (winner == 0 && count < SIZE * SIZE) {
    // Print the board
    printf("\n");
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }

    // Get the player's move
    printf("Player %d, enter your move (row, column): ", player);
    scanf("%d %d", &i, &j);

    // Check if the move is valid
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE || board[i][j] != ' ') {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Make the move
    board[i][j] = player == 1 ? 'X' : 'O';

    // Check if the player has won
    for (k = 0; k < SIZE; k++) {
      if (board[i][k] == board[i][j] && board[i][k] != ' ') {
        winner = player;
      }
    }
    for (l = 0; l < SIZE; l++) {
      if (board[l][j] == board[i][j] && board[l][j] != ' ') {
        winner = player;
      }
    }
    if (i == j) {
      for (m = 0; m < SIZE; m++) {
        if (board[m][m] == board[i][j] && board[m][m] != ' ') {
          winner = player;
        }
      }
    }
    if (i + j == SIZE - 1) {
      for (n = 0; n < SIZE; n++) {
        if (board[n][SIZE - 1 - n] == board[i][j] && board[n][SIZE - 1 - n] != ' ') {
          winner = player;
        }
      }
    }

    // Increment the count
    count++;

    // Switch the player
    player = player == 1 ? 2 : 1;
  }

  // Print the result
  if (winner == 0) {
    printf("Tie!\n");
  } else {
    printf("Player %d wins!\n", winner);
  }

  return 0;
}