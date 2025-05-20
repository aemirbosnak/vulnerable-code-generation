//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
// Linked list operations in a shape shifting style
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
  int data;
  struct node *next;
};

// Function to create a new node
struct node* create_node(int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(struct node **head_ref, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(struct node **head_ref, int data) {
  struct node *new_node = create_node(data);
  struct node *last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node **head_ref, int data, int key) {
  struct node *new_node = create_node(data);
  struct node *current = *head_ref;
  while (current->data != key) {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
}

// Function to delete a node
void delete_node(struct node **head_ref, int key) {
  struct node *current = *head_ref;
  if (current->data == key) {
    *head_ref = current->next;
    free(current);
    return;
  }
  while (current->next != NULL) {
    if (current->next->data == key) {
      struct node *temp = current->next;
      current->next = temp->next;
      free(temp);
      return;
    }
    current = current->next;
  }
}

// Function to print the list
void print_list(struct node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  struct node *head = NULL;
  insert_at_beginning(&head, 10);
  insert_at_end(&head, 5);
  insert_after(&head, 15, 10);
  delete_node(&head, 15);
  print_list(head);
  return 0;
}