//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>

char board[3][3];

void display_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %c ", board[i][j]);
      if (j != 2) {
        printf("|");
      }
    }
    printf("\n");
    if (i != 2) {
      printf("---+---+---\n");
    }
  }
}

int check_winner() {
  // check rows for winner
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
      return 1;
    }
  }

  // check columns for winner
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ') {
      return 1;
    }
  }

  // check diagonals for winner
  if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
      (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
    return 1;
  }

  // check if board is full
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }

  // no winner, board is full
  return -1;
}

int main() {
  int turn = 1; // player 1's turn
  int row, col;
  int winner;

  // initialize board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  while ((winner = check_winner()) == 0) {
    printf("Player %d's turn\n", turn);
    display_board();

    // input player's move
    do {
      printf("Enter row (1-3): ");
      scanf("%d", &row);
      printf("Enter column (1-3): ");
      scanf("%d", &col);

      row--; // adjust for 0-based array
      col--; // adjust for 0-based array
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

    // update board with player's move
    if (turn == 1) {
      board[row][col] = 'X';
      turn = 2; // switch to player 2's turn
    } else {
      board[row][col] = 'O';
      turn = 1; // switch to player 1's turn
    }
  }

  // game over, display result
  display_board();
  if (winner == 1) {
    printf("Player %d wins!\n", turn == 1 ? 2 : 1);
  } else {
    printf("Draw game.\n");
  }

  return 0;
}