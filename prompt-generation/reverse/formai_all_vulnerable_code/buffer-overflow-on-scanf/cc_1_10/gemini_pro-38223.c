//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct {
  char name[50];
  char number[20];
} Contact;

// Function to add a contact
void addContact(Contact *contacts, int *numContacts) {
  printf("Enter name: ");
  scanf("%s", contacts[*numContacts].name);
  printf("Enter number: ");
  scanf("%s", contacts[*numContacts].number);
  (*numContacts)++;
}

// Function to search for a contact
int searchContact(Contact *contacts, int numContacts, char *name) {
  for (int i = 0; i < numContacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to print all contacts
void printContacts(Contact *contacts, int numContacts) {
  for (int i = 0; i < numContacts; i++) {
    printf("Name: %s\n", contacts[i].name);
    printf("Number: %s\n\n", contacts[i].number);
  }
}

// Function to delete a contact
void deleteContact(Contact *contacts, int *numContacts, char *name) {
  int index = searchContact(contacts, *numContacts, name);
  if (index == -1) {
    printf("Contact not found\n");
    return;
  }
  for (int i = index; i < *numContacts - 1; i++) {
    contacts[i] = contacts[i + 1];
  }
  (*numContacts)--;
}

// Main function
int main() {
  // Allocate memory for the contacts
  Contact *contacts = (Contact *)malloc(100 * sizeof(Contact));

  // Initialize the number of contacts to 0
  int numContacts = 0;

  // Add some contacts to the phone book
  addContact(contacts, &numContacts);
  addContact(contacts, &numContacts);
  addContact(contacts, &numContacts);

  // Print all contacts
  printContacts(contacts, numContacts);

  // Search for a contact
  char name[50];
  printf("Enter name to search for: ");
  scanf("%s", name);
  int index = searchContact(contacts, numContacts, name);
  if (index == -1) {
    printf("Contact not found\n");
  } else {
    printf("Contact found:\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Number: %s\n", contacts[index].number);
  }

  // Delete a contact
  printf("Enter name to delete: ");
  scanf("%s", name);
  deleteContact(contacts, &numContacts, name);

  // Print all contacts
  printContacts(contacts, numContacts);

  // Free the memory allocated for the contacts
  free(contacts);

  return 0;
}