//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
  int data;
  struct Node* next;
};

//Starting Node pointer
struct Node* start = NULL;

//Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  return newNode;
}

//Function to insert node at the beginning
void insertAtBeginning(int data) {
  struct Node* newNode = createNode(data);
  newNode -> next = start;
  start = newNode;
}

//Function to insert node at the end
void insertAtEnd(int data) {
  struct Node* newNode = createNode(data);
  if(start == NULL) {
    start = newNode;
    return;
  }
  struct Node* temp = start;
  while(temp -> next != NULL) {
    temp = temp -> next;
  }
  temp -> next = newNode;
  return;
}

//Function to insert node at a specific position
void insertAtPosition(int data, int position) {
  if(position == 1) {
    insertAtBeginning(data);
    return;
  }
  struct Node* newNode = createNode(data);
  if(start == NULL) {
    start = newNode;
    return;
  }
  struct Node* temp = start;
  for(int i = 1; i < position - 1; i++) {
    if(temp -> next == NULL) {
      printf("Invalid Position!\n");
      return;
    }
    temp = temp -> next;
  }
  newNode -> next = temp -> next;
  temp -> next = newNode;
}

//Function to delete node from the beginning
void deleteFromBeginning() {
  if(start == NULL) {
    printf("The list is already empty!\n");
    return;
  }
  struct Node* temp = start;
  start = start -> next;
  free(temp);
}

//Function to delete node from the end
void deleteFromEnd() {
  if(start == NULL) {
    printf("The list is already empty!\n");
    return;
  }
  struct Node* temp = start;
  if(temp -> next == NULL) {
    start = NULL;
    free(temp);
    return;
  }
  while(temp -> next -> next != NULL) {
    temp = temp -> next;
  }
  free(temp -> next);
  temp -> next = NULL;
}

//Function to delete node from a specific position
void deleteFromPosition(int position) {
  if(start == NULL) {
    printf("The list is already empty!\n");
    return;
  }
  if(position == 1) {
    deleteFromBeginning();
    return;
  }
  struct Node* temp1 = start;
  for(int i = 1; i < position - 1; i++) {
    if(temp1 -> next == NULL) {
      printf("Invalid Position!\n");
      return;
    }
    temp1 = temp1 -> next;
  }
  struct Node* temp2 = temp1 -> next;
  temp1 -> next = temp2 -> next;
  free(temp2);
}

//Function to display the linked list
void display() {
  if(start == NULL) {
    printf("The list is empty!\n");
    return;
  }
  struct Node* temp = start;
  printf("The linked list is:\n");
  while(temp != NULL) {
    printf("%d ", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}

//Main Function
int main() {
  int choice, data, position;
  while(1) {
    printf("Enter your choice:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at a specific position\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete from the end\n");
    printf("6. Delete from a specific position\n");
    printf("7. Display the linked list\n");
    printf("8. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("Enter the data:\n");
              scanf("%d", &data);
              insertAtBeginning(data);
              break;
      case 2: printf("Enter the data:\n");
              scanf("%d", &data);
              insertAtEnd(data);
              break;
      case 3: printf("Enter the data and position:\n");
              scanf("%d %d", &data, &position);
              insertAtPosition(data, position);
              break;
      case 4: deleteFromBeginning();
              break;
      case 5: deleteFromEnd();
              break;
      case 6: printf("Enter the position:\n");
              scanf("%d", &position);
              deleteFromPosition(position);
              break;
      case 7: display();
              break;
      case 8: exit(0);
              break;
      default: printf("Invalid choice!\n");
               break;
    }
  }
  return 0;
}