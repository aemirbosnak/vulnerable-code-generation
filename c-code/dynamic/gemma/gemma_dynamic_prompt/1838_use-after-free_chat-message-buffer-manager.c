#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

struct Node {
  char *data;
  struct Node *next;
};

struct Node *insert(struct Node *head, char *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void freeList(struct Node *head) {
  struct Node *current = head;
  struct Node *next = NULL;

  while (current) {
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
}

int main() {
  struct Node *head = NULL;

  insert(head, "Hello, world!");
  insert(head, "This is a message.");

  freeList(head);

  return 0;
}
