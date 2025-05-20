//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
// A unique C Linked list operations example program in a unmistakable style

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
  int data;
  struct Node* next;
};

// Linked list structure
struct LinkedList {
  struct Node* head;
  struct Node* tail;
};

// Creates a new linked list
struct LinkedList* createLinkedList() {
  struct LinkedList* list = malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

// Adds a node to the front of the linked list
void addNodeFront(struct LinkedList* list, int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = list->head;
  list->head = node;
}

// Adds a node to the back of the linked list
void addNodeBack(struct LinkedList* list, int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

// Prints the linked list
void printLinkedList(struct LinkedList* list) {
  struct Node* node = list->head;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Frees the memory used by the linked list
void freeLinkedList(struct LinkedList* list) {
  struct Node* node = list->head;
  while (node != NULL) {
    struct Node* next = node->next;
    free(node);
    node = next;
  }
  free(list);
}

int main() {
  struct LinkedList* list = createLinkedList();

  // Add nodes to the front and back of the linked list
  addNodeFront(list, 1);
  addNodeFront(list, 2);
  addNodeBack(list, 3);
  addNodeBack(list, 4);

  // Print the linked list
  printLinkedList(list);

  // Free the memory used by the linked list
  freeLinkedList(list);

  return 0;
}