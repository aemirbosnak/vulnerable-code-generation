//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
// C Data Structures Visualization Program
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the list
struct Node {
  int data;
  struct Node *next;
};

// Define a structure to represent a list
struct List {
  struct Node *head;
  struct Node *tail;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to create a new list
struct List* createList() {
  struct List *list = (struct List*)malloc(sizeof(struct List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

// Function to add a node to the end of the list
void addNode(struct List *list, int data) {
  struct Node *node = createNode(data);
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

// Function to print the list
void printList(struct List *list) {
  struct Node *node = list->head;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Driver code
int main() {
  struct List *list = createList();
  addNode(list, 1);
  addNode(list, 2);
  addNode(list, 3);
  printList(list);
  return 0;
}