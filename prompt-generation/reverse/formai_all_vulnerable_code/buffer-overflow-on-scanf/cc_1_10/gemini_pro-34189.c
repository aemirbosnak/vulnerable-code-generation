//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j];
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }

  if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    return board[2][0];
  }

  return ' ';
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  printf("   |   |  \n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("  \n");
  }
}

int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Game loop
  int turn = 1;
  int x, y;
  while (1) {
    // Print the board
    print_board(board);

    // Get the player's move
    printf("Player %d's turn:\n", turn);
    printf("Enter the row and column (1-3): ");
    scanf("%d %d", &x, &y);

    // Check if the move is valid
    if (x < 1 || x > 3 || y < 1 || y > 3 || board[x - 1][y - 1] != ' ') {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Place the player's move on the board
    board[x - 1][y - 1] = turn == 1 ? 'X' : 'O';

    // Check if there is a winner
    char winner = check_winner(board);
    if (winner != ' ') {
      // Print the winner
      printf("Player %d wins!\n", turn);
      break;
    }

    // Switch turns
    turn = turn == 1 ? 2 : 1;
  }

  return 0;
}