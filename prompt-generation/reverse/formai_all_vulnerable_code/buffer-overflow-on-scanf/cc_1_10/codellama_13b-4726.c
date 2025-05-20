//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: rigorous
// C Phone Book Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store contact information
struct Contact {
  char name[20];
  char phone[20];
  char email[50];
};

// Function to add a new contact
void addContact(struct Contact *contacts, int *numContacts) {
  printf("Enter name: ");
  scanf("%s", contacts[*numContacts].name);
  printf("Enter phone number: ");
  scanf("%s", contacts[*numContacts].phone);
  printf("Enter email: ");
  scanf("%s", contacts[*numContacts].email);
  *numContacts += 1;
}

// Function to search for a contact
struct Contact *searchContact(struct Contact *contacts, int numContacts, char *name) {
  for (int i = 0; i < numContacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      return &contacts[i];
    }
  }
  return NULL;
}

// Function to display all contacts
void displayContacts(struct Contact *contacts, int numContacts) {
  printf("Name\tPhone\tEmail\n");
  for (int i = 0; i < numContacts; i++) {
    printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
  }
}

int main() {
  struct Contact contacts[100];
  int numContacts = 0;
  char name[20];

  while (1) {
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addContact(contacts, &numContacts);
        break;
      case 2:
        printf("Enter name: ");
        scanf("%s", name);
        struct Contact *contact = searchContact(contacts, numContacts, name);
        if (contact != NULL) {
          printf("Name: %s\nPhone: %s\nEmail: %s\n", contact->name, contact->phone, contact->email);
        } else {
          printf("Contact not found\n");
        }
        break;
      case 3:
        displayContacts(contacts, numContacts);
        break;
      case 4:
        return 0;
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}