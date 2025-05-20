//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: creative
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* createNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insertAtBeginning(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  struct Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
  struct Node* newNode = createNode(data);
  struct Node* temp = *head;
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
  struct Node* temp = *head;
  *head = temp->next;
  free(temp);
}

void deleteAtEnd(struct Node** head) {
  struct Node* temp = *head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) {
  struct Node* temp = *head;
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void display(struct Node* head) {
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);
  insertAtPosition(&head, 6, 3);

  display(head);

  deleteAtBeginning(&head);
  deleteAtEnd(&head);
  deleteAtPosition(&head, 3);

  display(head);

  return 0;
}