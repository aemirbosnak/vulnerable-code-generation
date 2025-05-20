//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Structure to store contact information
  typedef struct {
    char name[50];
    char phone[15];
    char email[50];
  } Contact;

  // Function to add a new contact
  void addContact(Contact *contacts, int *numContacts) {
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter email: ");
    scanf("%s", contacts[*numContacts].email);
    (*numContacts)++;
  }

  // Function to search for a contact by name
  void searchContact(Contact *contacts, int numContacts, char *name) {
    for (int i = 0; i < numContacts; i++) {
      if (strcmp(contacts[i].name, name) == 0) {
        printf("Contact found: %s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        break;
      }
    }
  }

  // Function to delete a contact
  void deleteContact(Contact *contacts, int *numContacts, char *name) {
    for (int i = 0; i < *numContacts; i++) {
      if (strcmp(contacts[i].name, name) == 0) {
        for (int j = i; j < *numContacts - 1; j++) {
          contacts[j] = contacts[j + 1];
        }
        (*numContacts)--;
        break;
      }
    }
  }

  // Function to display all contacts
  void displayContacts(Contact *contacts, int numContacts) {
    for (int i = 0; i < numContacts; i++) {
      printf("%s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
  }

  int main() {
    // Initialize the number of contacts to 0
    int numContacts = 0;

    // Create an array of Contact structures
    Contact contacts[100];

    // Add a few contacts
    addContact(contacts, &numContacts);
    addContact(contacts, &numContacts);
    addContact(contacts, &numContacts);

    // Search for a contact
    searchContact(contacts, numContacts, "John Doe");

    // Delete a contact
    deleteContact(contacts, &numContacts, "Jane Doe");

    // Display all contacts
    displayContacts(contacts, numContacts);

    return 0;
  }