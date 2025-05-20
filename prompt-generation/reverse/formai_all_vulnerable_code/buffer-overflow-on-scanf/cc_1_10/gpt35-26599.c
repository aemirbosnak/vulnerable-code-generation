//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

typedef struct Node{
  char email[MAX_EMAIL_LENGTH];
  struct Node* next;
} Node;

typedef struct {
  Node* head;
  int num_emails;
} List;

List* createList() {
  List* newList = malloc(sizeof(List));
  newList->head = NULL;
  newList->num_emails = 0;
  return newList;
}

void addEmail(List* emailList, char* newEmail) {
  if (emailList->num_emails >= MAX_EMAILS) {
    printf("Error: Maximum number of emails reached.\n");
    return;
  }

  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->email, newEmail);
  newNode->next = emailList->head;

  emailList->head = newNode;
  emailList->num_emails++;
}

void printList(List* emailList) {
  Node* current = emailList->head;
  printf("Email List:\n");
  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

void deleteEmail(List* emailList, char* targetEmail) {
  Node* current = emailList->head;
  Node* prev = NULL;
  while (current != NULL) {
    if (strcmp(current->email, targetEmail) == 0) {
      if (prev == NULL) {
        emailList->head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      emailList->num_emails--;
      printf("Email \"%s\" deleted from list.\n", targetEmail);
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("Error: Email not found in list.\n");
}

int main() {
  List* emailList = createList();
  int option = -1;
  char newEmail[MAX_EMAIL_LENGTH];
  char targetEmail[MAX_EMAIL_LENGTH];

  while (option != 0) {
    printf("\nSelect an option:\n");
    printf("1. Add email to list\n");
    printf("2. Delete email from list\n");
    printf("3. Print email list\n");
    printf("0. Quit\n");
    scanf("%d", &option);

    if (option == 1) {
      printf("Enter email to add:\n");
      scanf("%s", newEmail);
      addEmail(emailList, newEmail);
    } else if (option == 2) {
      printf("Enter email to delete:\n");
      scanf("%s", targetEmail);
      deleteEmail(emailList, targetEmail);
    } else if (option == 3) {
      printList(emailList);
    } else if (option != 0) {
      printf("Error: Invalid option.\n");
    }
  }

  printf("Goodbye!\n");
  return 0;
}