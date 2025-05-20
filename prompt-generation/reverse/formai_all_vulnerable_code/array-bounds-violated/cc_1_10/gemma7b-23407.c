//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Cell {
  int x;
  int y;
  char value;
} Cell;

Cell cells[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      cells[r][c].x = r;
      cells[r][c].y = c;
      cells[r][c].value = ' ';
    }
  }
}

int isBoardFull() {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (cells[r][c].value == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(char player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (cells[r][0].value == player && cells[r][1].value == player && cells[r][2].value == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (cells[0][c].value == player && cells[1][c].value == player && cells[2][c].value == player) {
      return 1;
    }
  }

  // Check diagonals
  if (cells[0][0].value == player && cells[1][1].value == player && cells[2][2].value == player) {
    return 1;
  }

  // If no winner, return 0
  return 0;
}

int main() {
  initializeBoard();

  // Game loop
  while (!isBoardFull() && !checkWin('X')) {
    // Get player's move
    int moveX = -1;
    int moveY = -1;

    // Make move
    cells[moveX][moveY].value = 'X';

    // Check if player won
    if (checkWin('X')) {
      printf("Player X won!");
    }
  }

  // Game over
  if (isBoardFull()) {
    printf("It's a draw!");
  } else {
    printf("No winner!");
  }

  return 0;
}