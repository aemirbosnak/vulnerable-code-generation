//FormAI DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node structure
typedef struct node {
  int data;
  struct node* next;
  struct node* prev;
} Node;

// Create a new node with given data
Node* create_node(int data) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(Node** head_ref, int data) {
  Node* new_node = create_node(data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  new_node->next = *head_ref;
  (*head_ref)->prev = new_node;
  *head_ref = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(Node** head_ref, int data) {
  Node* new_node = create_node(data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  Node* current = *head_ref;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  new_node->prev = current;
}

// Insert a node at a given position in the linked list
void insert_at_position(Node** head_ref, int position, int data) {
  Node* new_node = create_node(data);
  if (position == 1) {
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
    *head_ref = new_node;
    return;
  }
  Node* current = *head_ref;
  int count = 1;
  while (count < position - 1 && current->next != NULL) {
    current = current->next;
    count++;
  }
  if (current->next == NULL && count == position - 1) {
    current->next = new_node;
    new_node->prev = current;
    return;
  }
  if (count < position - 1) {
    printf("Position %d does not exist in the linked list\n", position);
    return;
  }
  new_node->next = current->next;
  new_node->prev = current;
  current->next->prev = new_node;
  current->next = new_node;
}

// Delete the first occurrence of a node with given data from the linked list
void delete_node(Node** head_ref, int data) {
  if (*head_ref == NULL) {
    printf("List is empty\n");
    return;
  }
  Node* current = *head_ref;
  while (current != NULL && current->data != data) {
    current = current->next;
  }
  if (current == NULL) {
    printf("Node with data %d does not exist in the linked list\n", data);
    return;
  }
  if (current == *head_ref) {
    *head_ref = current->next;
    if (*head_ref != NULL) {
      (*head_ref)->prev = NULL;
    }
    free(current);
    return;
  }
  current->prev->next = current->next;
  if (current->next != NULL) {
    current->next->prev = current->prev;
  }
  free(current);
}

// Print the linked list
void print_list(Node* head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node* current = head;
  printf("Linked list: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  int choice, data, position;

  do {
    printf("1. Insert node at beginning\n");
    printf("2. Insert node at end\n");
    printf("3. Insert node at position\n");
    printf("4. Delete node\n");
    printf("5. Print list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_beginning(&head, data);
        break;
      case 2:
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_end(&head, data);
        break;
      case 3:
        printf("Enter position: ");
        scanf("%d", &position);
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_position(&head, position, data);
        break;
      case 4:
        printf("Enter data: ");
        scanf("%d", &data);
        delete_node(&head, data);
        break;
      case 5:
        print_list(head);
        break;
      case 6:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 6);

  return 0;
}