//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: futuristic
// Linked List Operations in a Futuristic Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the Linked List
struct node {
  char* data;
  struct node* next;
};

// Function to create a new node
struct node* create_node(char* data) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the list
struct node* insert_beginning(struct node* head, char* data) {
  struct node* new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Function to insert a new node at the end of the list
struct node* insert_end(struct node* head, char* data) {
  struct node* new_node = create_node(data);
  struct node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Function to delete a node from the list
struct node* delete_node(struct node* head, char* data) {
  struct node* current = head;
  if (strcmp(current->data, data) == 0) {
    head = current->next;
    free(current);
    return head;
  }
  while (current->next != NULL) {
    if (strcmp(current->next->data, data) == 0) {
      struct node* temp = current->next;
      current->next = temp->next;
      free(temp);
      return head;
    }
    current = current->next;
  }
  return head;
}

// Function to print the list
void print_list(struct node* head) {
  struct node* current = head;
  while (current != NULL) {
    printf("%s\n", current->data);
    current = current->next;
  }
}

// Main function
int main() {
  // Initialize the list
  struct node* head = NULL;

  // Insert nodes at the beginning of the list
  head = insert_beginning(head, "Node 1");
  head = insert_beginning(head, "Node 2");

  // Insert nodes at the end of the list
  head = insert_end(head, "Node 3");
  head = insert_end(head, "Node 4");

  // Delete a node from the list
  head = delete_node(head, "Node 2");

  // Print the list
  print_list(head);

  return 0;
}