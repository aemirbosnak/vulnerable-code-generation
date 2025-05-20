//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct node {
    int data;
    struct node *next;
  };

  struct node *head = NULL;

  void insert(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
  }

  void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }

  void delete(int value) {
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL) {
      if (temp->data == value) {
        if (prev == NULL) {
          head = temp->next;
        } else {
          prev->next = temp->next;
        }
        free(temp);
        break;
      }
      prev = temp;
      temp = temp->next;
    }
  }

  int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print_list();
    delete(3);
    print_list();
    return 0;
  }