//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void printList(struct Node* head) {
  struct Node* curr = head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

struct Node* insertFront(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* curr = head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
  return head;
}

struct Node* insertAt(struct Node* head, int data, int position) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (position == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    struct Node* curr = head;
    int count = 0;
    while (curr->next != NULL && count < position) {
      curr = curr->next;
      count++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
  return head;
}

struct Node* deleteFront(struct Node* head) {
  if (head == NULL) {
    return NULL;
  }
  struct Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

struct Node* deleteEnd(struct Node* head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  struct Node* curr = head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
  return head;
}

struct Node* deleteAt(struct Node* head, int position) {
  if (position == 0) {
    return deleteFront(head);
  }
  struct Node* curr = head;
  int count = 0;
  while (curr->next != NULL && count < position) {
    curr = curr->next;
    count++;
  }
  if (curr->next != NULL) {
    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
  }
  return head;
}

int main() {
  struct Node* head = NULL;
  head = insertFront(head, 10);
  head = insertFront(head, 20);
  head = insertFront(head, 30);
  head = insertEnd(head, 40);
  head = insertEnd(head, 50);
  head = insertAt(head, 60, 2);
  head = deleteFront(head);
  head = deleteEnd(head);
  head = deleteAt(head, 2);
  printList(head);
  return 0;
}