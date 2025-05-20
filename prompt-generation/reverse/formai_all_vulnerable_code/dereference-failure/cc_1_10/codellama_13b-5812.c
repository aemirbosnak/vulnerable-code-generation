//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct node {
    char* data;
    struct node* next;
  };

  struct node* head = NULL;
  struct node* tail = NULL;

  void push(char* data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void pop() {
    if (head == NULL) {
      printf("Stack is empty.\n");
      return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
  }

  void print() {
    struct node* temp = head;
    while (temp != NULL) {
      printf("%s\n", temp->data);
      temp = temp->next;
    }
  }

  int main() {
    push("Hello");
    push("World");
    print();
    pop();
    print();
    return 0;
  }