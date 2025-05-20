//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: funny
// Linked list operations in a funny style

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  struct Node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Function to insert a new node after a given node
void insertAfter(struct Node** head, int data, int after) {
  struct Node* newNode = createNode(data);
  struct Node* current = *head;
  while (current->data != after) {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head, int data) {
  struct Node* current = *head;
  struct Node* previous = NULL;
  while (current->data != data) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    *head = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

// Function to print the list
void printList(struct Node* head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main() {
  // Initialize list with 3 nodes
  struct Node* head = createNode(1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);

  // Insert a node after node with data 2
  insertAfter(&head, 4, 2);

  // Delete a node with data 3
  deleteNode(&head, 3);

  // Print the list
  printList(head);

  return 0;
}