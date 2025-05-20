#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

  Node* moves = createNode(0, 0);

  // Player's turn
  printf("Enter your move (x, y): ");
  int move_x, move_y;
  scanf("%d %d", &move_x, &move_y);

  // Place the move
  board[move_x][move_y] = 1;

  // AI's turn
  move_x = rand() % BOARD_SIZE;
  move_y = rand() % BOARD_SIZE;

  // Place the AI's move
  board[move_x][move_y] = 2;

  // Check if the game is over
  if (board[move_x][move_y] == 3) {
    printf("It's a draw!");
  } else if (board[move_x][move_y] == 1) {
    printf("You win!");
  } else {
    printf("AI wins!");
  }

  return 0;
}
