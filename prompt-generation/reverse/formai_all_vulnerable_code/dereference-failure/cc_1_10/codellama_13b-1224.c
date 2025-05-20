//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: creative
/*
 * Linked List Operations Example Program
 *
 * In this program, we will demonstrate how to perform basic operations on a linked list in C.
 * We will create a linked list with 5 nodes, and then perform operations such as adding a node,
 * removing a node, and traversing the list.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
  int data;
  struct Node *next;
};

// Function to add a node to the end of the list
void addNode(struct Node **head, int data) {
  struct Node *temp = *head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Function to remove a node from the list
void removeNode(struct Node **head, int data) {
  struct Node *temp = *head;

  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (temp->data == data) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp->next != NULL) {
    if (temp->next->data == data) {
      struct Node *temp2 = temp->next->next;
      free(temp->next);
      temp->next = temp2;
      return;
    }
    temp = temp->next;
  }
  printf("Data not found in list\n");
}

// Function to traverse the list
void traverseList(struct Node *head) {
  struct Node *temp = head;

  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;

  addNode(&head, 1);
  addNode(&head, 2);
  addNode(&head, 3);
  addNode(&head, 4);
  addNode(&head, 5);

  traverseList(head);

  removeNode(&head, 3);

  traverseList(head);

  return 0;
}