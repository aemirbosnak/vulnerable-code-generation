//FormAI DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node node;

node* createNode(int data);
void displayList(node* head);
node* insertAtBeginning(node* head, int data);
void insertAtEnd(node* head, int data);
node* deleteAtBeginning(node* head);
void deleteAtEnd(node* head);

int main() {
  node* head = createNode(10); // create a new linked list with the first element as 10
  while (1) {
      printf("\nChoose operation to perform:\n");
      printf("1. Display Linked List\n");
      printf("2. Insert at Beginning\n");
      printf("3. Insert at End\n");
      printf("4. Delete at Beginning\n");
      printf("5. Delete at End\n");
      printf("6. Exit\n");

      int operation, data;
      scanf("%d", &operation);
    
      switch(operation) {
        case 1:
          displayList(head);
          break;
        case 2:
          printf("Enter the data to insert at beginning: ");
          scanf("%d", &data);
          head = insertAtBeginning(head, data);
          break;
        case 3:
          printf("Enter the data to insert at end: ");
          scanf("%d", &data);
          insertAtEnd(head, data);
          break;
        case 4:
          head = deleteAtBeginning(head);
          break;
        case 5:
          deleteAtEnd(head);
          break;
        case 6:
          exit(0);
        default:
          printf("Invalid Choice!\n");
      }
  }
  return 0;
}

// Function to create a new node
node* createNode(int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to display the linked list
void displayList(node* head) {
  if (head == NULL) {
    printf("Linked list is empty!");
    return;
  }
  node* ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

// Function to insert a node at the beginning
node* insertAtBeginning(node* head, int data) {
  node* newNode = createNode(data);
  newNode->next = head;
  head = newNode;
  return head;
}

// Function to insert a node at the end
void insertAtEnd(node* head, int data) {
  node* newNode = createNode(data);
  node* ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = newNode;
}

// Function to delete a node at the beginning
node* deleteAtBeginning(node* head) {
  node* temp = head;
  if (head == NULL) {
    printf("Linked List is empty!");
    return head;
  }
  head = head->next;
  free(temp);
  return head;
}

// Function to delete a node at the end
void deleteAtEnd(node* head) {
  if (head == NULL) {
    printf("Linked List is empty!");
    return;
  }
  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }
  node* ptr = head;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  free(ptr->next);
  ptr->next = NULL;
}