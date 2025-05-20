//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: funny
/*
 * Unique C Linked List Operations Example Program in a Funny Style
 *
 * This program demonstrates various operations on a linked list in a funny style.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct node {
  int data;
  struct node *next;
};

// Define a function to create a new node
struct node* newNode(int data) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Define a function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data) {
  struct node *new_node = newNode(data);
  new_node->next = *head;
  *head = new_node;
}

// Define a function to insert a node at the end of the linked list
void insertAtEnd(struct node **head, int data) {
  struct node *new_node = newNode(data);
  struct node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

// Define a function to insert a node after a specific node in the linked list
void insertAfter(struct node **head, int data, int position) {
  struct node *new_node = newNode(data);
  struct node *current = *head;
  while (current->next != NULL && position > 0) {
    current = current->next;
    position--;
  }
  new_node->next = current->next;
  current->next = new_node;
}

// Define a function to delete a node from the linked list
void deleteNode(struct node **head, int position) {
  struct node *current = *head;
  while (current->next != NULL && position > 0) {
    current = current->next;
    position--;
  }
  current->next = current->next->next;
}

// Define a function to print the linked list
void printList(struct node **head) {
  struct node *current = *head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;

  // Insert 5 nodes at the beginning of the linked list
  for (int i = 0; i < 5; i++) {
    insertAtBeginning(&head, i);
  }
  printList(&head);

  // Insert 5 nodes at the end of the linked list
  for (int i = 5; i < 10; i++) {
    insertAtEnd(&head, i);
  }
  printList(&head);

  // Insert a node after the 3rd node in the linked list
  insertAfter(&head, 15, 3);
  printList(&head);

  // Delete the 5th node in the linked list
  deleteNode(&head, 5);
  printList(&head);

  // Delete the 2nd node in the linked list
  deleteNode(&head, 2);
  printList(&head);

  return 0;
}