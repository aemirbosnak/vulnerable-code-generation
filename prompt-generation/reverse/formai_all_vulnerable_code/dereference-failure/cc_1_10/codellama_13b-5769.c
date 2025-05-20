//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: surrealist
/*
 *  Linked List Operations Example Program
 *  Surrealist Style
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void create_list(int n) {
  struct node *temp, *newnode;
  int i;

  for (i = 1; i <= n; i++) {
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = i;
    newnode->next = NULL;

    if (head == NULL) {
      head = newnode;
    } else {
      temp->next = newnode;
    }

    temp = newnode;
  }
}

void print_list() {
  struct node *temp = head;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  create_list(5);
  print_list();

  return 0;
}