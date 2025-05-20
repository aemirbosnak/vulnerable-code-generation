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

struct Node* Insert(struct Node* head, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void Evict(struct Node* head) {
  struct Node* current = head;
  struct Node* previous = NULL;

  while (current) {
    previous = current;
    current = current->next;
  }

  free(previous);
  head = current;
}

int main() {
  struct Node* head = NULL;

  Insert(head, 1);
  Insert(head, 2);
  Insert(head, 3);
  Insert(head, 4);
  Insert(head, 5);

  Evict(head);

  printf("Head: %p\n", head);

  return 0;
}
