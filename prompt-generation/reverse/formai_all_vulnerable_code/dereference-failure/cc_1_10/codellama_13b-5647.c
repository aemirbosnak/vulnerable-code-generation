//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: standalone
/*
 * Linked list operations example program in a standalone style
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Linked list node structure
 */
struct node {
  int data;
  struct node *next;
};

/*
 * Linked list structure
 */
struct list {
  struct node *head;
  struct node *tail;
};

/*
 * Function to create a new linked list
 */
struct list* create_list() {
  struct list *new_list = malloc(sizeof(struct list));
  new_list->head = NULL;
  new_list->tail = NULL;
  return new_list;
}

/*
 * Function to add an element to the front of the linked list
 */
void push_front(struct list *list, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
}

/*
 * Function to add an element to the back of the linked list
 */
void push_back(struct list *list, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail != NULL) {
    list->tail->next = new_node;
  }
  list->tail = new_node;
  if (list->head == NULL) {
    list->head = new_node;
  }
}

/*
 * Function to remove an element from the front of the linked list
 */
void pop_front(struct list *list) {
  if (list->head != NULL) {
    struct node *old_head = list->head;
    list->head = list->head->next;
    free(old_head);
    if (list->head == NULL) {
      list->tail = NULL;
    }
  }
}

/*
 * Function to remove an element from the back of the linked list
 */
void pop_back(struct list *list) {
  if (list->tail != NULL) {
    struct node *old_tail = list->tail;
    struct node *new_tail = list->tail->next;
    free(old_tail);
    list->tail = new_tail;
    if (list->tail == NULL) {
      list->head = NULL;
    } else {
      list->tail->next = NULL;
    }
  }
}

/*
 * Function to get the length of the linked list
 */
int length(struct list *list) {
  int len = 0;
  struct node *cur = list->head;
  while (cur != NULL) {
    len++;
    cur = cur->next;
  }
  return len;
}

/*
 * Function to print the linked list
 */
void print_list(struct list *list) {
  struct node *cur = list->head;
  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  struct list *list = create_list();

  push_front(list, 1);
  push_front(list, 2);
  push_back(list, 3);
  push_back(list, 4);

  print_list(list);

  pop_front(list);
  pop_back(list);

  print_list(list);

  return 0;
}