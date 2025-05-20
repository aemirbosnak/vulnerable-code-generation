//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: surrealist
/*
 * A surrealist C Linked list operations example program
 *
 * This program demonstrates the basic operations of a linked list
 * in a surrealist style, using a mix of abstract and surrealist imagery.
 */

#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
typedef struct node {
  int data;
  struct node *next;
} node_t;

// The linked list
typedef struct list {
  node_t *head;
  node_t *tail;
  int size;
} list_t;

// Initialize the linked list
void init_list(list_t *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// Add a node to the front of the list
void add_front(list_t *list, int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = list->head;
  list->head = node;
  if (list->tail == NULL) {
    list->tail = node;
  }
  list->size++;
}

// Add a node to the back of the list
void add_back(list_t *list, int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  if (list->tail == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

// Remove the first node from the list
void remove_front(list_t *list) {
  if (list->head == NULL) {
    return;
  }
  node_t *node = list->head;
  list->head = node->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(node);
  list->size--;
}

// Remove the last node from the list
void remove_back(list_t *list) {
  if (list->tail == NULL) {
    return;
  }
  node_t *node = list->tail;
  node_t *prev = list->head;
  while (prev->next != list->tail) {
    prev = prev->next;
  }
  prev->next = NULL;
  list->tail = prev;
  free(node);
  list->size--;
}

// Remove a node from the list
void remove_node(list_t *list, int data) {
  node_t *node = list->head;
  node_t *prev = NULL;
  while (node != NULL) {
    if (node->data == data) {
      if (prev == NULL) {
        remove_front(list);
      } else {
        prev->next = node->next;
        if (node == list->tail) {
          list->tail = prev;
        }
        free(node);
        list->size--;
      }
      return;
    }
    prev = node;
    node = node->next;
  }
}

// Print the list
void print_list(list_t *list) {
  node_t *node = list->head;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  list_t list;
  init_list(&list);
  add_front(&list, 1);
  add_back(&list, 2);
  add_front(&list, 3);
  add_back(&list, 4);
  remove_front(&list);
  remove_back(&list);
  remove_node(&list, 2);
  print_list(&list);
  return 0;
}