//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct node {
      int data;
      struct node* next;
  } node;

  node* create_list(int n) {
      node* head = NULL;
      node* current = NULL;
      for (int i = 0; i < n; i++) {
          current = (node*)malloc(sizeof(node));
          current->data = i + 1;
          current->next = head;
          head = current;
      }
      return head;
  }

  void display(node* head) {
      node* current = head;
      while (current != NULL) {
          printf("%d ", current->data);
          current = current->next;
      }
      printf("\n");
  }

  node* insert_beginning(node* head, int data) {
      node* current = (node*)malloc(sizeof(node));
      current->data = data;
      current->next = head;
      return current;
  }

  node* insert_end(node* head, int data) {
      node* current = head;
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = (node*)malloc(sizeof(node));
      current->next->data = data;
      current->next->next = NULL;
      return head;
  }

  node* insert_after(node* head, int data, int after_data) {
      node* current = head;
      while (current != NULL && current->data != after_data) {
          current = current->next;
      }
      if (current == NULL) {
          return head;
      }
      node* new_node = (node*)malloc(sizeof(node));
      new_node->data = data;
      new_node->next = current->next;
      current->next = new_node;
      return head;
  }

  node* insert_before(node* head, int data, int before_data) {
      node* current = head;
      if (current->data == before_data) {
          node* new_node = (node*)malloc(sizeof(node));
          new_node->data = data;
          new_node->next = current;
          return new_node;
      }
      while (current->next != NULL && current->next->data != before_data) {
          current = current->next;
      }
      if (current->next == NULL) {
          return head;
      }
      node* new_node = (node*)malloc(sizeof(node));
      new_node->data = data;
      new_node->next = current->next;
      current->next = new_node;
      return head;
  }

  node* delete_node(node* head, int data) {
      node* current = head;
      if (current->data == data) {
          head = current->next;
          free(current);
          return head;
      }
      while (current->next != NULL && current->next->data != data) {
          current = current->next;
      }
      if (current->next == NULL) {
          return head;
      }
      node* temp = current->next;
      current->next = temp->next;
      free(temp);
      return head;
  }

  int main() {
      node* head = create_list(5);
      display(head);
      head = insert_beginning(head, 0);
      display(head);
      head = insert_end(head, 6);
      display(head);
      head = insert_after(head, 7, 3);
      display(head);
      head = insert_before(head, 8, 6);
      display(head);
      head = delete_node(head, 4);
      display(head);
      return 0;
  }