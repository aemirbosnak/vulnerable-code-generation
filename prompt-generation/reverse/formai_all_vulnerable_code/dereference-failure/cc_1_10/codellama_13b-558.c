//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* create_node(int data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

struct node* insert_at_head(struct node* head, int data) {
  struct node* new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

struct node* insert_at_tail(struct node* head, int data) {
  struct node* new_node = create_node(data);
  struct node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  return head;
}

struct node* insert_after(struct node* head, int data, int after) {
  struct node* new_node = create_node(data);
  struct node* temp = head;
  while (temp != NULL && temp->data != after) {
    temp = temp->next;
  }
  if (temp == NULL) {
    return NULL;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  return head;
}

struct node* delete_node(struct node* head, int data) {
  struct node* temp = head;
  while (temp != NULL && temp->data != data) {
    temp = temp->next;
  }
  if (temp == NULL) {
    return NULL;
  }
  temp->next = temp->next->next;
  free(temp->next);
  return head;
}

int main() {
  struct node* head = NULL;
  head = insert_at_tail(head, 1);
  head = insert_at_tail(head, 2);
  head = insert_at_tail(head, 3);
  head = insert_at_tail(head, 4);
  head = insert_at_tail(head, 5);
  head = delete_node(head, 2);
  head = insert_after(head, 6, 3);
  struct node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}