//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: genius
// Genius Memory Management Example Program
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void create_list(struct Node** head, int n) {
  struct Node* current = NULL;
  struct Node* temp = NULL;

  for (int i = 0; i < n; i++) {
    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = i;
    current->next = NULL;

    if (*head == NULL) {
      *head = current;
    } else {
      temp->next = current;
    }

    temp = current;
  }
}

void print_list(struct Node* head) {
  struct Node* current = head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

void free_list(struct Node** head) {
  struct Node* current = *head;

  while (current != NULL) {
    struct Node* temp = current->next;
    free(current);
    current = temp;
  }

  *head = NULL;
}

int main() {
  struct Node* head = NULL;
  create_list(&head, 10);
  print_list(head);
  free_list(&head);
  return 0;
}