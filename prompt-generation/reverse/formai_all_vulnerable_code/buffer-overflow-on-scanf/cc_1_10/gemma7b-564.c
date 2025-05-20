//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum CellState { EMPTY, PLAYER_ONE, PLAYER_TWO } CellState;

CellState board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY}};

CellState currentPlayer = PLAYER_ONE;

void printBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j] == EMPTY ? ' ' : (board[i][j] == PLAYER_ONE ? 'X' : 'O'));
    }
    printf("\n");
  }
}

int isBoardFull() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY) {
      return board[0][i] == PLAYER_ONE ? 1 : 2;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != EMPTY) {
      return board[j][0] == PLAYER_ONE ? 1 : 2;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY) {
    return board[0][0] == PLAYER_ONE ? 1 : 2;
  }

  // If all cells are filled and no winner, it's a draw
  return 0;
}

int main() {
  srand(time(NULL));

  // Play until one of the players wins or there is a draw
  while (!isBoardFull() && checkWin() == 0) {
    int row, column;

    // Get the player's move
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &column);

    // Place the player's mark on the board
    if (board[row][column] == EMPTY) {
      board[row][column] = currentPlayer;
    } else {
      printf("Error: that cell is already taken.\n");
    }

    // Switch to the next player
    currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;

    // Print the board
    printBoard();
  }

  // Print the winner or draw message
  if (checkWin() == 1) {
    printf("Player 1 won!\n");
  } else if (checkWin() == 2) {
    printf("Player 2 won!\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}