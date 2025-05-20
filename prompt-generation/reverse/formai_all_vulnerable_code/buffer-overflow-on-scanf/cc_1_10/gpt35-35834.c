//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  struct Node* next;
} Node;

void addSubscriber(Node** head, char* name, char* email);
void deleteSubscriber(Node** head, char* email);
void searchSubscriber(Node* head, char* email);
void printList(Node* head);
void freeList(Node* head);

int main() {
  Node* head = NULL;
  int choice;
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];

  while (1) {
    printf("Mailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Delete Subscriber\n");
    printf("3. Search Subscriber\n");
    printf("4. Print List\n");
    printf("5. Quit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);
        addSubscriber(&head, name, email);
        break;
      case 2:
        printf("Enter email: ");
        scanf("%s", email);
        deleteSubscriber(&head, email);
        break;
      case 3:
        printf("Enter email: ");
        scanf("%s", email);
        searchSubscriber(head, email);
        break;
      case 4:
        printList(head);
        break;
      case 5:
        freeList(head);
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void addSubscriber(Node** head, char* name, char* email) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  strcpy(newNode->name, name);
  strcpy(newNode->email, email);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }

  printf("Subscriber added\n");
}

void deleteSubscriber(Node** head, char* email) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node* current = *head;
  Node* prev = NULL;
  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      if (prev == NULL) {
        *head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      printf("Subscriber deleted\n");
      return;
    }
    prev = current;
    current = current->next;
  }

  printf("Subscriber not found\n");
}

void searchSubscriber(Node* head, char* email) {
  Node* current = head;
  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      printf("Subscriber found:\n");
      printf("Name: %s\n", current->name);
      printf("Email: %s\n", current->email);
      return;
    }
    current = current->next;
  }

  printf("Subscriber not found\n");
}

void printList(Node* head) {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    Node* current = head;
    printf("Mailing List:\n");
    while (current != NULL) {
      printf("%s\t%s\n", current->name, current->email);
      current = current->next;
    }
  }
}

void freeList(Node* head) {
  Node* current = head;
  Node* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}