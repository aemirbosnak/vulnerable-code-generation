//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_SIZE 5
#define COLOR_SIZE 3

typedef struct Node {
  int color;
  struct Node* next;
} Node;

Node* insertNode(Node* head) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->color = -1;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void graphColor(Node* head) {
  int colors[COLOR_SIZE] = {0};
  for (Node* current = head; current; current = current->next) {
    int currentColor = colors[current->color];
    if (currentColor != -1) {
      current->color = -1;
    } else {
      colors[current->color] = current;
    }
  }

  for (int i = 0; i < COLOR_SIZE; i++) {
    if (colors[i] != NULL) {
      printf("Node %p has color %d\n", colors[i], i);
    }
  }
}

int main() {
  Node* head = insertNode(NULL);
  insertNode(head);
  insertNode(head);
  insertNode(head);
  insertNode(head);

  graphColor(head);

  return 0;
}