//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
/*
 * A Linked list operations example program in a Claude Shannon style
 */

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head_ref;
  *head_ref = newNode;
}

// Function to insert a new node after a given node
void insertAfter(struct Node* prevNode, int data) {
  if (prevNode == NULL) {
    printf("The given previous node cannot be NULL");
    return;
  }
  struct Node* newNode = createNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int data) {
  struct Node* temp = *head_ref;
  struct Node* prev = NULL;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("The given data is not present in the linked list");
    return;
  }
  if (prev == NULL) {
    *head_ref = temp->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Creating a linked list
  struct Node* head = createNode(1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAfter(head->next, 4);
  insertAfter(head->next->next, 5);
  insertAfter(head->next->next->next, 6);

  // Printing the linked list
  printf("The linked list is: ");
  printList(head);

  // Deleting a node from the linked list
  deleteNode(&head, 4);

  // Printing the linked list after deletion
  printf("The linked list after deletion is: ");
  printList(head);

  return 0;
}