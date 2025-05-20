//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
/* Tic Tac Toe AI in C */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Setup
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int player = 1; // 1 for X, -1 for O
  int turn = 0;
  int winner = 0;
  int x, y;

  // Game loop
  while (winner == 0) {
    // Print board
    printf("\n");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // Get player input
    if (player == 1) {
      printf("Enter X coordinates: ");
    } else {
      printf("Enter O coordinates: ");
    }
    scanf("%d %d", &x, &y);

    // Check for valid input
    if (x < 1 || x > 3 || y < 1 || y > 3 || board[x - 1][y - 1] != 0) {
      printf("Invalid input\n");
      continue;
    }

    // Set board
    board[x - 1][y - 1] = player;

    // Check for win
    if (check_win(board, player)) {
      winner = player;
      break;
    }

    // Update player and turn
    player = -player;
    turn++;

    // Check for draw
    if (turn == 9) {
      winner = 0;
      break;
    }
  }

  // Print winner
  if (winner == 1) {
    printf("Player 1 wins\n");
  } else if (winner == -1) {
    printf("Player 2 wins\n");
  } else {
    printf("Draw\n");
  }

  return 0;
}

// Check for win
int check_win(int board[3][3], int player) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }
  return 0;
}