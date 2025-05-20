//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char email[50];
  struct Node* next;
} Node;

Node* head = NULL; // head of linked list

void addToList(char* email) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strncpy(newNode->email, email, 50);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* currNode = head;
    while (currNode->next != NULL) {
      currNode = currNode->next;
    }
    currNode->next = newNode;
  }
}

void printList() {
  printf("\nMailing List:\n");
  Node* currNode = head;
  while (currNode != NULL) {
    printf("%s\n", currNode->email);
    currNode = currNode->next;
  }
  printf("\n");
}

void deleteFromList(char* email) {
  Node* currNode = head;
  Node* prevNode = NULL;

  while (currNode != NULL) {
    if (strcmp(currNode->email, email) == 0) {
      // email match found
      if (prevNode == NULL) {
        // email match found at head of list
        head = currNode->next;
      } else {
        prevNode->next = currNode->next;
      }
      free(currNode);
      printf("%s has been removed from the mailing list.\n\n", email);
      return;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  printf("Error: %s not found in the mailing list.\n\n", email);
}

int main() {
  char selection;
  
  printf("Welcome to the Mailing List Manager!\n");
  printf("===================================\n\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Add email to mailing list\n");
    printf("2. Delete email from mailing list\n");
    printf("3. Print mailing list\n");
    printf("4. Quit\n\n");

    selection = getchar();
    fflush(stdin);

    switch(selection) {
      case '1': {
        char email[50];
        printf("\nEnter email to add: ");
        scanf("%s", email);
        addToList(email);
        printf("\n%s has been added to the mailing list.\n\n", email);
        break;
      }
      case '2': {
        char email[50];
        printf("\nEnter email to delete: ");
        scanf("%s", email);
        deleteFromList(email);
        break;
      }
      case '3': {
        printList();
        break;
      }
      case '4': {
        printf("\nThank you for using the Mailing List Manager!\n\n");
        exit(0);
      }
      default: {
        printf("\nError: Invalid selection. Please try again.\n\n");
        break;
      }
    }
  }

  return 0;
}