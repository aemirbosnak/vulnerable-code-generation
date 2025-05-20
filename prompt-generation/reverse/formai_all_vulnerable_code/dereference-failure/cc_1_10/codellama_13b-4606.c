//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: optimized
// Linked list operations example program

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

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
  struct Node* node = createNode(data);
  node->next = *head;
  *head = node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
  struct Node* node = createNode(data);
  struct Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
  struct Node* temp = *head;
  struct Node* prev = NULL;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    return;
  }
  if (prev == NULL) {
    *head = temp->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
}

// Function to traverse the list
void traverse(struct Node** head) {
  struct Node* temp = *head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Initialize list
  struct Node* head = NULL;

  // Insert nodes at the beginning of the list
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);

  // Insert nodes at the end of the list
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);

  // Traverse the list
  traverse(&head);

  // Delete a node from the list
  deleteNode(&head, 3);

  // Traverse the list again
  traverse(&head);

  return 0;
}