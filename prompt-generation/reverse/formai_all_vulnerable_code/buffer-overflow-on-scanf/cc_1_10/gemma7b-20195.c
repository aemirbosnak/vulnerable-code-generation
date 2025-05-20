//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 21

char board[BOARD_SIZE] = {0};

void drawBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%c ", board[i]);
  }
  printf("\n");
}

void placeBall() {
  int x = rand() % BOARD_SIZE;
  board[x] = 'O';
}

int main() {
  srand(time(NULL));

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = '_';
  }

  // Place the ball
  placeBall();

  // Human's turn
  int move = 0;
  printf("Enter your move (1-21): ");
  scanf("%d", &move);

  // Check if the move is valid
  if (move < 1 || move > BOARD_SIZE) {
    printf("Invalid move.\n");
    return 1;
  }

  // Place the ball
  board[move] = 'O';

  // AI's turn
  move = rand() % BOARD_SIZE;
  board[move] = 'A';

  // Draw the board
  drawBoard();

  // Check if the game is over
  if (board[0] == 'A' || board[BOARD_SIZE - 1] == 'A') {
    printf("AI wins!\n");
  } else if (board[0] == 'O' || board[BOARD_SIZE - 1] == 'O') {
    printf("Human wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}