//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int check_winner() {
  int i, j;

  // Check rows
  for (i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0];
    }
  }

  // Check columns
  for (j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j];
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2];
  }

  return ' ';
}

void print_board() {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int turn = 0;
  int x, y;

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Game loop
  while (check_winner() == ' ') {
    if (turn % 2 == 0) {
      printf("Player 1's turn (X): ");
    } else {
      printf("Player 2's turn (O): ");
    }

    scanf("%d %d", &x, &y);

    if (x < 1 || x > BOARD_SIZE || y < 1 || y > BOARD_SIZE) {
      printf("Invalid move. Try again.\n");
      continue;
    }

    if (board[x - 1][y - 1] != ' ') {
      printf("That space is already occupied. Try again.\n");
      continue;
    }

    if (turn % 2 == 0) {
      board[x - 1][y - 1] = 'X';
    } else {
      board[x - 1][y - 1] = 'O';
    }

    print_board();

    turn++;
  }

  int winner = check_winner();

  if (winner == ' ') {
    printf("Tie game.\n");
  } else {
    printf("Player %c wins!\n", winner);
  }

  return 0;
}