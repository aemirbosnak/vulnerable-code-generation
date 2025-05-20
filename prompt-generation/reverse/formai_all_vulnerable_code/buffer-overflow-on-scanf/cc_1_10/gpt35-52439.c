//FormAI DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Linked list structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function declarations
Node* createNode(int data);
void insertNode(Node **head, int data);
void deleteNode(Node **head, int data);
void displayList(Node *head);

int main() {
  Node *head = NULL;
  
  printf("Welcome to the Linked List Operations Program!\n\n");
  
  int choice, value;
  
  do {
    printf("Please choose an operation:\n");
    printf("1) Insert a node\n");
    printf("2) Delete a node\n");
    printf("3) Display the list\n");
    printf("4) Exit the program\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        insertNode(&head, value);
        printf("%d was inserted into the linked list!\n\n", value);
        break;
      case 2:
        printf("Enter the value to delete: ");
        scanf("%d", &value);
        deleteNode(&head, value);
        printf("%d was deleted from the linked list!\n\n", value);
        break;
      case 3:
        printf("The current list is: ");
        displayList(head);
        printf("\n\n");
        break;
      case 4:
        printf("Thank you for using our program! Goodbye!\n");
        break;
      default:
        printf("That's an invalid choice! Please try again.\n\n");
        break;
    }
  
  } while (choice != 4);
  
  return 0;
}

// Function to create a new node
Node* createNode(int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the list
void insertNode(Node **head, int data) {
  Node *new_node = createNode(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to delete a node with a given value
void deleteNode(Node **head, int data) {
  Node *temp = *head, *prev;

  if (temp != NULL && temp->data == data) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  prev->next = temp->next;

  free(temp);
}

// Function to display the list
void displayList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}