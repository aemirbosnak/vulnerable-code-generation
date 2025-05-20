//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void playTicTacToe() {
  Node* head = NULL;

  // Create a board
  char board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

  // Place the first move
  insertAtTail(&head, 1);
  board[1][1] = 'X';

  // Loop until the game is over
  while (board[2][2] == 0) {
    // Get the player's move
    int move = getMove();

    // Place the move
    insertAtTail(&head, move);
    board[move][move] = 'X';

    // Check if the player has won
    if (hasWon(board, move)) {
      printf("You have won!\n");
      break;
    }
  }

  // If the game is over, but there is no winner, it's a draw
  if (board[2][2] == 0) {
    printf("It's a draw.\n");
  }
}

int getMove() {
  // Prompt the player for their move
  int move = -1;
  printf("Enter your move (1-9): ");
  scanf("%d", &move);

  // Validate the move
  while (move < 1 || move > 9) {
    printf("Invalid move. Please try again: ");
    scanf("%d", &move);
  }

  return move;
}

int hasWon(char** board, int move) {
  // Check if the player has won horizontally
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[move][i] == 'X' && board[move][i] == board[move][i + 1] && board[move][i] == board[move][i + 2]) {
      return 1;
    }
  }

  // Check if the player has won vertically
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][move] == 'X' && board[i][move] == board[i + 1][move] && board[i + 2][move] == 'X') {
      return 1;
    }
  }

  // Check if the player has won diagonally
  if (board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') {
    return 1;
  }

  // If the player has not won, return 0
  return 0;
}

int main() {
  playTicTacToe();

  return 0;
}