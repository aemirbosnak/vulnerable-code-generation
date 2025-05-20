//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: decentralized
// Decentralized Linked List Operations Example Program

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* create_node(int data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

struct Node* insert_at_head(struct Node **head, int data) {
  struct Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
  return new_node;
}

struct Node* insert_at_tail(struct Node **head, int data) {
  struct Node *new_node = create_node(data);
  struct Node *curr = *head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
  return new_node;
}

struct Node* insert_after(struct Node **head, int data, int position) {
  struct Node *new_node = create_node(data);
  struct Node *curr = *head;
  for (int i = 0; i < position; i++) {
    curr = curr->next;
  }
  new_node->next = curr->next;
  curr->next = new_node;
  return new_node;
}

struct Node* delete_node(struct Node **head, int position) {
  struct Node *curr = *head;
  for (int i = 0; i < position; i++) {
    curr = curr->next;
  }
  struct Node *temp = curr->next;
  curr->next = temp->next;
  free(temp);
  return curr;
}

struct Node* search_node(struct Node **head, int data) {
  struct Node *curr = *head;
  while (curr != NULL) {
    if (curr->data == data) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

void print_list(struct Node **head) {
  struct Node *curr = *head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;
  head = insert_at_head(&head, 1);
  head = insert_at_head(&head, 2);
  head = insert_at_tail(&head, 3);
  head = insert_after(&head, 4, 1);
  head = delete_node(&head, 2);
  print_list(&head);
  struct Node *node = search_node(&head, 3);
  if (node != NULL) {
    printf("Found %d at position %d\n", node->data, node->data);
  } else {
    printf("Not found\n");
  }
  return 0;
}