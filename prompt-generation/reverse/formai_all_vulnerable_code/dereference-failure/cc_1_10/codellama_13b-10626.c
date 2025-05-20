//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
/*
 * A unique C Linked list operations example program in Alan Turing style
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL");
    return;
  }
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
  struct Node* temp = *head_ref;
  struct Node* prev = NULL;
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Key not found");
    return;
  }
  if (prev == NULL) {
    *head_ref = temp->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
}

void printList(struct Node* head) {
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int main() {
  struct Node* head = NULL;
  push(&head, 5);
  push(&head, 7);
  push(&head, 3);
  insertAfter(head->next, 10);
  deleteNode(&head, 7);
  printList(head);
  return 0;
}