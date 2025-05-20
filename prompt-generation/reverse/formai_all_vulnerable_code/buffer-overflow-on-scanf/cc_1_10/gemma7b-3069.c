//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void playGame() {
  Cell* board = createCell(0);
  board->next = createCell(0);
  board->next->next = createCell(0);

  int player = 1;
  char move;

  // Game loop
  while (!board->next->next->value) {
    // Get player move
    printf("Enter your move (e.g. a1, b2, c3): ");
    scanf("%c", &move);

    // Validate move
    if (move < 'a' || move > 'c') {
      printf("Invalid move.\n");
      continue;
    }

    // Place move
    switch (move) {
      case 'a1':
        board->value = player;
        break;
      case 'b2':
        board->next->value = player;
        break;
      case 'c3':
        board->next->next->value = player;
        break;
    }

    // Switch player
    player *= -1;
  }

  // Game over
  printf("Game over! The winner is: ");
  if (board->value == 1) {
    printf("Player 1\n");
  } else if (board->value == -1) {
    printf("Player 2\n");
  } else {
    printf("It's a draw\n");
  }
}

int main() {
  playGame();
  return 0;
}