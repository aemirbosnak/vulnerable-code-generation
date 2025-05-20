//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for storing data
typedef struct node {
  char name[20];
  int age;
  struct node *next;
} node_t;

typedef struct linked_list {
  node_t *head;
  node_t *tail;
} linked_list_t;

// Function to add a new node to the linked list
void add_node(linked_list_t *list, char *name, int age) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  strcpy(new_node->name, name);
  new_node->age = age;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

// Function to print the linked list
void print_list(linked_list_t *list) {
  node_t *current = list->head;

  while (current != NULL) {
    printf("%s (%d)\n", current->name, current->age);
    current = current->next;
  }
}

int main() {
  linked_list_t list;
  list.head = NULL;
  list.tail = NULL;

  add_node(&list, "Alice", 25);
  add_node(&list, "Bob", 30);
  add_node(&list, "Charlie", 35);

  print_list(&list);

  return 0;
}