//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
// Linked List Operations Example Program
#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  struct Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Function to insert a node after a specific node
void insertAfter(struct Node *node, int data) {
  struct Node *newNode = createNode(data);
  newNode->next = node->next;
  node->next = newNode;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position) {
  struct Node *current = *head;
  for (int i = 0; i < position; i++) {
    current = current->next;
  }
  current->next = current->next->next;
  free(current->next);
}

// Function to display the list
void displayList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Function to reverse the list
void reverseList(struct Node **head) {
  struct Node *current = *head;
  struct Node *previous = NULL;
  while (current != NULL) {
    struct Node *next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *head = previous;
}

int main() {
  struct Node *head = NULL;
  insertAtBeginning(&head, 1);
  insertAtEnd(&head, 2);
  insertAfter(head->next, 3);
  displayList(head);
  deleteAtPosition(&head, 1);
  displayList(head);
  reverseList(&head);
  displayList(head);
  return 0;
}