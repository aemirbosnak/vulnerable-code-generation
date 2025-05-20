//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIVES 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void traverse(Node* node) {
  while (node) {
    printf("(%d, %d) ", node->x, node->y);
    node = node->next;
  }
}

int main() {
  srand(time(NULL));
  Node* head = malloc(sizeof(Node));
  head->x = rand() % 10;
  head->y = rand() % 10;
  head->next = malloc(sizeof(Node));
  head->next->x = rand() % 10;
  head->next->y = rand() % 10;
  head->next->next = malloc(sizeof(Node));
  head->next->next->x = rand() % 10;
  head->next->next->y = rand() % 10;

  int lives = MAX_LIVES;
  while (lives) {
    traverse(head);
    printf("\n");
    printf("Enter move (x, y): ");
    int x, y;
    scanf("%d %d", &x, &y);

    Node* current = head;
    while (current) {
      if (current->x == x && current->y == y) {
        printf("Boom!\n");
        lives--;
        break;
      }
      current = current->next;
    }

    if (lives) {
      printf("Remaining lives: %d\n", lives);
    }
  }

  return 0;
}