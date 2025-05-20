//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
// Linked List Operations Example Program
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
  while (current != NULL && current->data != key) {
    current = current->next;
  }
  if (current == NULL) {
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;
  struct Node* previous = NULL;
  while (current != NULL && current->data != key) {
    previous = current;
    current = current->next;
  }
  if (current == NULL) {
    return;
  }
  if (previous == NULL) {
    *head_ref = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

// Function to display the list
void displayList(struct Node** head_ref) {
  struct Node* current = *head_ref;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function to test the above functions
int main() {
  struct Node* head = NULL;
  insertAtBeginning(&head, 10);
  insertAtEnd(&head, 20);
  insertAfter(&head, 30, 10);
  insertAfter(&head, 40, 30);
  displayList(&head);
  deleteNode(&head, 30);
  displayList(&head);
  return 0;
}