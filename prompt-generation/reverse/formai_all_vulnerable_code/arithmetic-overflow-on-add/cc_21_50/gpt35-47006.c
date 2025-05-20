//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include <stdio.h>

int main() {
  char board[8][8] = {
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
    {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
    {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
    {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
    {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'}
  };

  int player = 1;
  int winner = 0;
  int i, j, row_from, col_from, row_to, col_to;
  char piece;

  while (!winner) {
    printf("Player %d's turn\n", player);
    printf("Enter the row and column of the piece you want to move: ");
    scanf("%d %d", &row_from, &col_from);

    if (player == 1) {
      piece = 'x';
    } else {
      piece = 'o';
    }

    if (board[row_from][col_from] != piece) {
      printf("Invalid input! You can only move your own pieces.\n");
      continue;
    }

    printf("Enter the row and column of the square you want to move to: ");
    scanf("%d %d", &row_to, &col_to);

    if (board[row_to][col_to] != ' ') {
      printf("Invalid input! That square is already occupied.\n");
      continue;
    }

    if (player == 1) {
      if (row_to - row_from == 1) {
        if (col_to - col_from == 1 || col_to - col_from == -1) {
          board[row_to][col_to] = 'x';
          board[row_from][col_from] = ' ';
        } else {
          printf("Invalid input!\n");
          continue;
        }
      } else if (row_to - row_from == 2) {
        if (col_to - col_from == 2 && board[row_from+1][col_from+1] == 'o') {
          board[row_to][col_to] = 'x';
          board[row_from][col_from] = ' ';
          board[row_from+1][col_from+1] = ' ';
        } else if (col_to - col_from == -2 && board[row_from+1][col_from-1] == 'o') {
          board[row_to][col_to] = 'x';
          board[row_from][col_from] = ' ';
          board[row_from+1][col_from-1] = ' ';
        } else {
          printf("Invalid input!\n");
          continue;
        }
      } else {
        printf("Invalid input!\n");
        continue;
      }
    } else {
      if (row_from - row_to == 1) {
        if (col_to - col_from == 1 || col_to - col_from == -1) {
          board[row_to][col_to] = 'o';
          board[row_from][col_from] = ' ';
        } else {
          printf("Invalid input!\n");
          continue;
        }
      } else if (row_from - row_to == 2) {
        if (col_to - col_from == 2 && board[row_from-1][col_from+1] == 'x') {
          board[row_to][col_to] = 'o';
          board[row_from][col_from] = ' ';
          board[row_from-1][col_from+1] = ' ';
        } else if (col_to - col_from == -2 && board[row_from-1][col_from-1] == 'x') {
          board[row_to][col_to] = 'o';
          board[row_from][col_from] = ' ';
          board[row_from-1][col_from-1] = ' ';
        } else {
          printf("Invalid input!\n");
          continue;
        }
      } else {
        printf("Invalid input!\n");
        continue;
      }
    }

    // Check for winner
    winner = 1;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (board[i][j] == 'x') {
          winner = 0;
          break;
        }
      }
      if (winner == 0) {
        break;
      }
    }
    if (winner == 1) {
      printf("Player 2 Wins!\n");
      break;
    }

    winner = 2;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (board[i][j] == 'o') {
          winner = 0;
          break;
        }
      }
      if (winner == 0) {
        break;
      }
    }
    if (winner == 2) {
      printf("Player 1 Wins!\n");
      break;
    }

    // Switch player
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }

    // Print board
    printf("   0 1 2 3 4 5 6 7\n");
    for (i = 0; i < 8; i++) {
      printf("%d  ", i);
      for (j = 0; j < 8; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}