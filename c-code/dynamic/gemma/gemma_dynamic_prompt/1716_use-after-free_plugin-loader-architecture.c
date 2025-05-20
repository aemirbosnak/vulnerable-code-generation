#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  int data;
} Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void freeList(Node** head) {
  Node* current = *head;
  Node* next = NULL;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}

int main() {
  Node* head = NULL;
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);

  freeList(&head);

  // Use after free vulnerability
  printf("%d", head->data);

  return 0;
}
