//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Cell {
  int value;
  struct Cell* next;
} Cell;

Cell* createCell(int value) {
  Cell* cell = malloc(sizeof(Cell));
  cell->value = value;
  cell->next = NULL;
  return cell;
}

void playMove(Cell* board, int move) {
  if (board->value == 0) {
    board->value = move;
  } else {
    printf("Invalid move\n");
  }
}

int checkWin(Cell* board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->value == board->next->value && board->value == board->next->next->value) {
      return board->value;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->value == board->next->value && board->value == board->next->next->value) {
      return board->value;
    }
  }

  // Check diagonals
  if (board->value == board->next->next->value && board->value == board->next->value) {
    return board->value;
  }

  return 0;
}

int main() {
  Cell* board = createCell(0);
  board->next = createCell(0);
  board->next->next = createCell(0);

  // Game loop
  int move = 1;
  while (!checkWin(board) && move <= BOARD_SIZE * BOARD_SIZE) {
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    playMove(board, move);

    move++;
  }

  // Game over
  if (checkWin(board) != 0) {
    printf("Winner: %d\n", checkWin(board));
  } else {
    printf("Draw\n");
  }

  return 0;
}