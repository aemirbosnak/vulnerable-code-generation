//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: statistical
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head_ref;
  *head_ref = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
  struct Node* newNode = createNode(data);
  struct Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node** head_ref, int data, int key) {
  struct Node* newNode = createNode(data);
  struct Node* current = *head_ref;
  while (current->data != key) {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;
  struct Node* previous = NULL;
  while (current->data != key) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    *head_ref = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

// Function to print the list
void printList(struct Node** head_ref) {
  struct Node* current = *head_ref;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Initialize the list
  struct Node* head = NULL;

  // Insert nodes at the beginning
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);

  // Insert nodes at the end
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);

  // Insert nodes after a given node
  insertAfter(&head, 50, 10);
  insertAfter(&head, 60, 30);

  // Delete nodes
  deleteNode(&head, 20);
  deleteNode(&head, 40);

  // Print the list
  printList(&head);

  // Free memory
  free(head);

  return 0;
}