//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: imaginative
// Imaginary Linked List Operations Program

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct node {
  int data;
  struct node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Function to delete a node from the list
void deleteNode(Node **head, int data) {
  Node *current = *head;
  Node *previous = NULL;
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
void printList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function to test the list operations
int main() {
  Node *head = NULL;
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  deleteNode(&head, 2);
  printList(head);
  return 0;
}