//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: excited
// A unique C Phone Book example program in an excited style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact details
struct Contact {
  char name[50];
  char phone[15];
  char email[50];
};

// Function to add a new contact
void addContact(struct Contact *contact) {
  printf("Enter name: ");
  scanf("%s", contact->name);
  printf("Enter phone: ");
  scanf("%s", contact->phone);
  printf("Enter email: ");
  scanf("%s", contact->email);
}

// Function to search for a contact
int searchContact(struct Contact *contacts, int numContacts, char *name) {
  for (int i = 0; i < numContacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to display all contacts
void displayContacts(struct Contact *contacts, int numContacts) {
  for (int i = 0; i < numContacts; i++) {
    printf("%s - %s - %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
  }
}

int main() {
  struct Contact contacts[10];
  int numContacts = 0;

  // Add new contacts
  for (int i = 0; i < 10; i++) {
    addContact(&contacts[i]);
    numContacts++;
  }

  // Search for a contact
  char searchName[50];
  printf("Enter name to search: ");
  scanf("%s", searchName);
  int index = searchContact(contacts, numContacts, searchName);
  if (index != -1) {
    printf("Contact found: %s - %s - %s\n", contacts[index].name, contacts[index].phone, contacts[index].email);
  } else {
    printf("Contact not found\n");
  }

  // Display all contacts
  displayContacts(contacts, numContacts);

  return 0;
}