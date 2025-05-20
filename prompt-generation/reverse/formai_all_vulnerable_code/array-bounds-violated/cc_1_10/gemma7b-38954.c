//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>

void play_game() {
  int board[6][6] = {{0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int move_made = 0;
  int player_turn = 0;

  while (!move_made) {
    // Get the player's move
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    // Check if the move is valid
    if (board[row][col] == 0 && row >= 0 && row < 6 && col >= 0 && col < 6) {
      // Make the move
      board[row][col] = player_turn;
      move_made = 1;
    } else {
      printf("Invalid move.\n");
    }
  }

  // Check if the player won or lost
  int winner = check_winner(board, player_turn);
  if (winner) {
    printf("You won!\n");
  } else {
    printf("You lost.\n");
  }
}

int check_winner(int **board, int player_turn) {
  // Check rows
  for (int i = 0; i < 6; i++) {
    if (board[0][i] == player_turn && board[1][i] == player_turn && board[2][i] == player_turn) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < 6; j++) {
    if (board[j][0] == player_turn && board[j][1] == player_turn && board[j][2] == player_turn) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player_turn && board[1][1] == player_turn && board[2][2] == player_turn) {
    return 1;
  }
  if (board[0][2] == player_turn && board[1][1] == player_turn && board[2][0] == player_turn) {
    return 1;
  }

  // No winner
  return 0;
}

int main() {
  play_game();
  return 0;
}