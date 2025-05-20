//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BOARD_SIZE 3

typedef struct Node {
  char symbol;
  struct Node* next;
} Node;

Node* newNode(char symbol) {
  Node* node = malloc(sizeof(Node));
  node->symbol = symbol;
  node->next = NULL;
  return node;
}

void playGame() {
  Node* head = newNode('X');
  head->next = newNode('O');
  head->next->next = newNode('X');
  head->next->next->next = newNode('O');
  head->next->next->next->next = newNode('X');

  char currentPlayer = 'X';
  int moveMade = 0;

  while (!moveMade) {
    char move;
    printf("Make your move (1-9): ");
    scanf("%c", &move);

    switch (move) {
      case '1':
        if (head->next->symbol == ' ') {
          head->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '2':
        if (head->next->next->symbol == ' ') {
          head->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '3':
        if (head->next->next->next->symbol == ' ') {
          head->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '4':
        if (head->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '5':
        if (head->next->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '6':
        if (head->next->next->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '7':
        if (head->next->next->next->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '8':
        if (head->next->next->next->next->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      case '9':
        if (head->next->next->next->next->next->next->next->next->next->symbol == ' ') {
          head->next->next->next->next->next->next->next->next->next->symbol = currentPlayer;
          moveMade = 1;
        }
        break;
      default:
        printf("Invalid move. Please try again.\n");
    }
  }

  if (currentPlayer == 'X') {
    printf("You won!\n");
  } else {
    printf("You lost.\n");
  }
}

int main() {
  playGame();
  return 0;
}