//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: retro
/*
 *  Linked List Operations Example Program
 *  Inspired by retro video games
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node* create_node(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insert_node(Node **head, int data) {
  Node *node = create_node(data);
  node->next = *head;
  *head = node;
}

void print_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void remove_node(Node **head, int data) {
  Node *temp = *head;
  Node *prev = NULL;
  while (temp != NULL) {
    if (temp->data == data) {
      if (prev == NULL) {
        *head = temp->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main() {
  Node *head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 5);
  print_list(head);
  remove_node(&head, 3);
  print_list(head);
  return 0;
}