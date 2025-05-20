//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: surrealist
/*
 * A surrealist C Linked list program
 */

#include <stdio.h>
#include <stdlib.h>

// Define the Linked list structure
struct node {
  int data;
  struct node *next;
};

// Define the Linked list head and tail
struct node *head = NULL;
struct node *tail = NULL;

// Function to create a new node
struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
  struct node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
  struct node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

// Function to insert a node after a given node
void insertAfter(int data, int position) {
  struct node *newNode = createNode(data);
  if (position == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

// Function to insert a node before a given node
void insertBefore(int data, int position) {
  struct node *newNode = createNode(data);
  if (position == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp;
    temp = newNode;
  }
}

// Function to delete a node from the list
void deleteNode(int position) {
  if (position == 0) {
    struct node *temp = head;
    head = head->next;
    free(temp);
  } else {
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    struct node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
  }
}

// Function to print the list
void printList() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Initialize the list
  head = NULL;
  tail = NULL;

  // Insert nodes at the beginning and end of the list
  insertAtBeginning(1);
  insertAtEnd(5);

  // Insert nodes after and before a given node
  insertAfter(2, 0);
  insertBefore(3, 2);
  insertAfter(4, 1);
  insertBefore(6, 3);

  // Print the list
  printList();

  // Delete a node from the list
  deleteNode(3);

  // Print the list again
  printList();

  return 0;
}