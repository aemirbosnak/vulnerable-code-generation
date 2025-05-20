//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
};

void printList(struct LinkedList *list) {
  struct Node *current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void push(struct LinkedList *list, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

void insertAfter(struct LinkedList *list, int data, int position) {
  struct Node *current = list->head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  if (position == 0) {
    newNode->next = list->head;
    list->head = newNode;
  } else {
    for (int i = 0; i < position; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

void insertBefore(struct LinkedList *list, int data, int position) {
  struct Node *current = list->head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  if (position == 0) {
    newNode->next = list->head;
    list->head = newNode;
  } else {
    for (int i = 0; i < position; i++) {
      current = current->next;
    }
    newNode->next = current;
    current = newNode;
  }
}

void deleteNode(struct LinkedList *list, int position) {
  struct Node *current = list->head;
  if (position == 0) {
    list->head = current->next;
    free(current);
  } else {
    for (int i = 0; i < position; i++) {
      current = current->next;
    }
    current->next = current->next->next;
    free(current->next);
  }
}

int main() {
  struct LinkedList list;
  list.head = NULL;

  push(&list, 1);
  push(&list, 2);
  push(&list, 3);

  printList(&list);

  insertAfter(&list, 4, 2);
  printList(&list);

  insertBefore(&list, 5, 1);
  printList(&list);

  deleteNode(&list, 2);
  printList(&list);

  return 0;
}