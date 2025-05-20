//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* newNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void playGame(Node* board) {
  int moveCounter = 0;
  char currentPlayer = 'X';
  int gameWon = 0;

  while (!gameWon && moveCounter < BOARD_SIZE * BOARD_SIZE) {
    // Get the player's move
    int xMove, yMove;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &xMove, &yMove);

    // Validate the move
    if (xMove < 0 || xMove >= BOARD_SIZE || yMove < 0 || yMove >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Check if the move is valid
    if (board->x == xMove && board->y == yMove) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board->x = xMove;
    board->y = yMove;

    // Increment the move counter
    moveCounter++;

    // Check if the player has won
    gameWon = checkWin(board);

    // Switch players
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  // End the game
  if (gameWon) {
    printf("Congratulations! You won!\n");
  } else {
    printf("It's a draw.\n");
  }
}

int checkWin(Node* board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->x == board->next->x && board->x == board->next->next->x) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->y == board->next->y && board->y == board->next->next->y) {
      return 1;
    }
  }

  // Check diagonals
  if (board->x == board->next->y && board->x == board->next->next->x) {
    return 1;
  }

  // No winner
  return 0;
}

int main() {
  Node* board = newNode(0, 0);
  playGame(board);

  return 0;
}