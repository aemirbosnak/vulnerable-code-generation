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
  }
}

void evict(struct Node** head) {
  struct Node* tail = *head;
  struct Node* middle = NULL;

  while (tail) {
    middle = tail;
    tail = tail->next;
  }

  free(middle);
  *head = (*head)->next;
}

int main() {
  struct Node* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  evict(&head);

  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}
