//FormAI DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
  char name[50];
  char number[20];
} Contact;

void addContact(Contact *contacts, int *numContacts) {
  Contact newContact;
  printf("Enter name: ");
  scanf("%s", newContact.name);
  printf("Enter number: ");
  scanf("%s", newContact.number);
  contacts[*numContacts] = newContact;
  (*numContacts)++;
}

void printContacts(Contact *contacts, int numContacts) {
  if (numContacts == 0) {
    printf("No contacts found.\n");
    return;
  }
  printf("%-30s | %-20s\n", "Name", "Number");
  for (int i = 0; i < numContacts; i++) {
    printf("%-30s | %-20s\n", contacts[i].name, contacts[i].number);
  }
}

void deleteContact(Contact *contacts, int *numContacts, char *name) {
  for (int i = 0; i < *numContacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      for (int j = i+1; j < *numContacts; j++) {
        contacts[j-1] = contacts[j];
      }
      (*numContacts)--;
      printf("Contact deleted successfully.\n");
      return;
    }
  }
  printf("Contact not found.\n");
}

int main() {
  Contact contacts[MAX_CONTACTS];
  int numContacts = 0;
  printf("Welcome to the Phone Book!\n\n");
  while (1) {
    printf("What would you like to do?\n");
    printf("1. Add a contact\n");
    printf("2. View all contacts\n");
    printf("3. Delete a contact\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        addContact(contacts, &numContacts);
        break;
      case 2:
        printContacts(contacts, numContacts);
        break;
      case 3:
        printf("Enter name to delete: ");
        char name[50];
        scanf("%s", name);
        deleteContact(contacts, &numContacts, name);
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
    printf("\n");
  }
}