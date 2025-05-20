//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

int IsBoardFull(Node* head) {
  while (head) {
    if (head->x == BOARD_SIZE - 1 && head->y == BOARD_SIZE - 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int GetRandomMove(Node* head) {
  int r = rand() % 9;
  int move = -1;
  while (move == -1) {
    switch (r) {
      case 0:
        move = 0;
        break;
      case 1:
        move = 1;
        break;
      case 2:
        move = 2;
        break;
      case 3:
        move = 3;
        break;
      case 4:
        move = 4;
        break;
      case 5:
        move = 5;
        break;
      case 6:
        move = 6;
        break;
      case 7:
        move = 7;
        break;
      case 8:
        move = 8;
        break;
    }
    if (IsMoveValid(move, head) && IsMoveEmpty(move, head)) {
      move = move;
    } else {
      r = rand() % 9;
    }
  }
  return move;
}

int IsMoveValid(int move, Node* head) {
  switch (move) {
    case 0:
      return (head->x == 0 && head->y == 0);
    case 1:
      return (head->x == 0 && head->y == 1);
    case 2:
      return (head->x == 0 && head->y == 2);
    case 3:
      return (head->x == 1 && head->y == 0);
    case 4:
      return (head->x == 1 && head->y == 1);
    case 5:
      return (head->x == 1 && head->y == 2);
    case 6:
      return (head->x == 2 && head->y == 0);
    case 7:
      return (head->x == 2 && head->y == 1);
    case 8:
      return (head->x == 2 && head->y == 2);
  }
  return 0;
}

int IsMoveEmpty(int move, Node* head) {
  switch (move) {
    case 0:
      return (head->x == 0 && head->y == 0 && head->next == NULL);
    case 1:
      return (head->x == 0 && head->y == 1 && head->next == NULL);
    case 2:
      return (head->x == 0 && head->y == 2 && head->next == NULL);
    case 3:
      return (head->x == 1 && head->y == 0 && head->next == NULL);
    case 4:
      return (head->x == 1 && head->y == 1 && head->next == NULL);
    case 5:
      return (head->x == 1 && head->y == 2 && head->next == NULL);
    case 6:
      return (head->x == 2 && head->y == 0 && head->next == NULL);
    case 7:
      return (head->x == 2 && head->y == 1 && head->next == NULL);
    case 8:
      return (head->x == 2 && head->y == 2 && head->next == NULL);
  }
  return 0;
}

int main() {
  Node* head = CreateNode(0, 0);
  head->next = CreateNode(1, 0);
  head->next->next = CreateNode(2, 0);
  head->next->next->next = CreateNode(0, 1);
  head->next->next->next->next = CreateNode(1, 1);
  head->next->next->next->next->next = CreateNode(2, 1);
  head->next->next->next->next->next->next = CreateNode(0, 2);
  head->next->next->next->next->next->next->next = CreateNode(1, 2);
  head->next->next->next->next->next->next->next->next = CreateNode(2, 2);

  int move = GetRandomMove(head);
  printf("Move: %d\n", move);

  return 0;
}