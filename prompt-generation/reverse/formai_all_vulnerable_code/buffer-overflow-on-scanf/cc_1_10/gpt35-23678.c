//FormAI DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a global struct for the Mailing List
struct MailingList {
  char name[100];
  char email[100];
  struct MailingList* next;
};

// Function to print the Mailing List
void printList(struct MailingList* head) {
  struct MailingList* current = head;

  while (current != NULL) {
    printf("\nName: %s", current->name);
    printf("\nEmail: %s", current->email);
    printf("\n");

    current = current->next;
  }
}

// Function to add new contacts to the Mailing List
void addContact(struct MailingList** head, char* name, char* email) {
  struct MailingList* newContact = (struct MailingList*) malloc(sizeof(struct MailingList));

  strcpy(newContact->name, name);
  strcpy(newContact->email, email);
  newContact->next = (*head);
  (*head) = newContact;
}

int main() {
  struct MailingList* head = NULL;
  char name[100], email[100];
  char choice;

  do {
    // Display the Menu
    printf("\n");
    printf("==============================================\n");
    printf("Welcome to the Mailing List Management Program\n");
    printf("==============================================\n");
    printf("1. Add a Contact\n");
    printf("2. Print the Mailing List\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");

    // Read user's choice
    scanf(" %c", &choice);

    switch(choice) {
      case '1':
        printf("\nEnter the Name: ");
        scanf(" %[^\n]", name);
        printf("Enter the Email: ");
        scanf(" %[^\n]", email);
        addContact(&head, name, email);
        break;
      case '2':
        printf("\nPrinting Mailing List:\n\n");
        printList(head);
        break;
      case '3':
        printf("\nThank you for using the Mailing List Management Program!\n");
        break;
      default:
        printf("\nInvalid choice. Please select again.\n");
        break;
    }

  } while(choice != '3');

  return 0;
}