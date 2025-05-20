//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
// Visualize data structures in a rigorous style
#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
  int data;
  struct Node* next;
};

// Array of linked lists
struct List {
  struct Node** nodes;
  int size;
};

// Initialize a linked list
void initList(struct List* list, int size) {
  list->nodes = malloc(sizeof(struct Node*) * size);
  list->size = size;
  for (int i = 0; i < size; i++) {
    list->nodes[i] = NULL;
  }
}

// Add a node to the end of the linked list
void addNode(struct List* list, int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  if (list->size == 0) {
    list->nodes[0] = node;
  } else {
    struct Node* last = list->nodes[list->size - 1];
    last->next = node;
  }
  list->size++;
}

// Print the linked list
void printList(struct List* list) {
  struct Node* current = list->nodes[0];
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Main function
int main() {
  struct List list;
  initList(&list, 5);
  addNode(&list, 1);
  addNode(&list, 2);
  addNode(&list, 3);
  addNode(&list, 4);
  addNode(&list, 5);
  printList(&list);
  return 0;
}