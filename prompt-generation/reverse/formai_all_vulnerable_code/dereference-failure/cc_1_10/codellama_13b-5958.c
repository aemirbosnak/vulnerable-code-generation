//Code Llama-13B DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*
 * A unique C educational example program in the style of Ada Lovelace.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

struct node {
  int data;
  struct node *next;
};

void insert(struct node **head, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL) {
    *head = new_node;
  } else {
    struct node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void print_list(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

int main() {
  struct node *head = NULL;
  char input[MAX_INPUT_LENGTH];
  while (1) {
    printf("Enter a number (0 to exit): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    if (input[0] == '0') {
      break;
    }
    int data = atoi(input);
    insert(&head, data);
  }
  print_list(head);
  return 0;
}