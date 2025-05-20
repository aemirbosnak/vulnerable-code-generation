#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node* next;
};

void insert(struct Node** head, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
    *head = newNode;
  }
}

void evict(struct Node** head, int index) {
  struct Node* current = *head;
  struct Node* previous = NULL;

  for (int i = 0; current && i < index; i++) {
    previous = current;
    current = current->next;
  }

  if (previous) {
    previous->next = current->next;
  } else {
    *head = current->next;
  }

  free(current);
}

int main() {
  struct Node* head = NULL;
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  evict(&head, 2);

  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  return 0;
}
