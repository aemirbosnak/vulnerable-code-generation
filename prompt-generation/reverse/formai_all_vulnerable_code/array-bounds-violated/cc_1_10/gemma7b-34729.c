//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum CellState { EMPTY, PLAYER_X, PLAYER_O } CellState;

CellState board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY}};

CellState currentPlayer = PLAYER_X;

void placeMove(int x, int y) {
  if (board[x][y] != EMPTY) {
    return;
  }
  board[x][y] = currentPlayer;
  currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int isWon(CellState player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
        return 1;
      }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
        return 1;
      }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int gameWon = 0;

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }

  // Game loop
  while (!gameWon) {
    // Get the player's move
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Place the move
    placeMove(x, y);

    // Check if the player has won
    gameWon = isWon(currentPlayer);

    // If the player has won, print the winner
    if (gameWon) {
      printf("Congratulations! You have won!\n");
    }
  }

  return 0;
}