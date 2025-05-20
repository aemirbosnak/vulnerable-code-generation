//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: dynamic
// Linked list operations example program in a dynamic style
#include <stdio.h>
#include <stdlib.h>

// Linked list structure
struct node {
  int data;
  struct node *next;
};

// Function to create a new node
struct node* create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(struct node **head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_end(struct node **head, int data) {
  struct node *new_node = create_node(data);
  struct node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct node **head, int data, int after) {
  struct node *new_node = create_node(data);
  struct node *temp = *head;
  while (temp->data != after) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

// Function to delete a node from the list
void delete_node(struct node **head, int data) {
  struct node *temp = *head;
  if (temp->data == data) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp->next != NULL) {
    if (temp->next->data == data) {
      struct node *to_delete = temp->next;
      temp->next = temp->next->next;
      free(to_delete);
      return;
    }
    temp = temp->next;
  }
}

// Function to print the list
void print_list(struct node **head) {
  struct node *temp = *head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;
  insert_beginning(&head, 1);
  insert_end(&head, 2);
  insert_after(&head, 3, 1);
  print_list(&head);
  delete_node(&head, 2);
  print_list(&head);
  return 0;
}