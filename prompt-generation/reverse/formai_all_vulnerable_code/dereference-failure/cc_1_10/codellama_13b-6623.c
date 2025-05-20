//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: future-proof
/* Linked list operations example program in a future-proof style */

#include <stdio.h>
#include <stdlib.h>

/* Define a structure to represent a node in the linked list */
struct node {
  int data;
  struct node *next;
};

/* Define a structure to represent the linked list */
struct linked_list {
  struct node *head;
  struct node *tail;
};

/* Initialize a linked list */
void init_linked_list(struct linked_list *list) {
  list->head = NULL;
  list->tail = NULL;
}

/* Insert a new node at the beginning of the linked list */
void insert_begin(struct linked_list *list, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
}

/* Insert a new node at the end of the linked list */
void insert_end(struct linked_list *list, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

/* Delete the node at the beginning of the linked list */
void delete_begin(struct linked_list *list) {
  struct node *temp = list->head;
  list->head = temp->next;
  free(temp);
  if (list->head == NULL) {
    list->tail = NULL;
  }
}

/* Delete the node at the end of the linked list */
void delete_end(struct linked_list *list) {
  struct node *temp = list->head;
  while (temp->next != list->tail) {
    temp = temp->next;
  }
  list->tail = temp;
  temp->next = NULL;
}

/* Search for a node in the linked list */
void search_node(struct linked_list *list, int data) {
  struct node *temp = list->head;
  while (temp != NULL) {
    if (temp->data == data) {
      printf("Found node with data %d\n", data);
      return;
    }
    temp = temp->next;
  }
  printf("Node with data %d not found\n", data);
}

/* Print the linked list */
void print_linked_list(struct linked_list *list) {
  struct node *temp = list->head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct linked_list list;
  init_linked_list(&list);
  insert_begin(&list, 1);
  insert_begin(&list, 2);
  insert_end(&list, 3);
  insert_end(&list, 4);
  search_node(&list, 3);
  search_node(&list, 5);
  delete_begin(&list);
  delete_end(&list);
  print_linked_list(&list);
  return 0;
}