//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

void makeMove(Node* board, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (board == NULL) {
    board = newNode;
  } else {
    board->next = newNode;
    board = newNode;
  }
}

int main() {
  Node* board = NULL;
  int turn = 0;

  // Game loop
  while (!board || board->next) {
    // Get move from player
    int moveX, moveY;
    printf("Enter move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    // Validate move
    if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Make move
    makeMove(board, moveX, moveY);

    // Change turn
    turn = (turn + 1) % 2;
  }

  // Game over
  printf("Game over!\n");

  return 0;
}