//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
// unique_data_structures_visualization.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structures
typedef struct {
  int data;
  struct node *next;
} node_t;

typedef struct {
  node_t *head;
  node_t *tail;
} list_t;

// Custom data structures functions
void list_init(list_t *list) {
  list->head = NULL;
  list->tail = NULL;
}

void list_push_front(list_t *list, int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = list->head;
  list->head = node;
  if (list->tail == NULL) {
    list->tail = node;
  }
}

void list_push_back(list_t *list, int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

void list_pop_front(list_t *list) {
  if (list->head == NULL) {
    return;
  }
  node_t *node = list->head;
  list->head = node->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(node);
}

void list_pop_back(list_t *list) {
  if (list->tail == NULL) {
    return;
  }
  node_t *node = list->tail;
  list->tail = node->next;
  if (list->tail == NULL) {
    list->head = NULL;
  } else {
    list->tail->next = NULL;
  }
  free(node);
}

void list_free(list_t *list) {
  node_t *node = list->head;
  while (node != NULL) {
    node_t *tmp = node->next;
    free(node);
    node = tmp;
  }
  list->head = NULL;
  list->tail = NULL;
}

// Main function
int main() {
  // Create a list
  list_t list;
  list_init(&list);

  // Add elements to the list
  list_push_front(&list, 1);
  list_push_front(&list, 2);
  list_push_front(&list, 3);
  list_push_back(&list, 4);
  list_push_back(&list, 5);
  list_push_back(&list, 6);

  // Print the list
  node_t *node = list.head;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");

  // Remove elements from the list
  list_pop_front(&list);
  list_pop_back(&list);

  // Print the list again
  node = list.head;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");

  // Free the list
  list_free(&list);

  return 0;
}