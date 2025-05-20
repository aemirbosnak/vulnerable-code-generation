//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact in the phone book
typedef struct contact {
  char name[30];
  char phone_number[11];
} contact;

// Function to add a contact to the phone book
void add_contact(contact *contacts, int *num_contacts) {
  // Get the contact's name and phone number from the user
  printf("Enter the contact's name: ");
  scanf("%s", contacts[*num_contacts].name);
  printf("Enter the contact's phone number: ");
  scanf("%s", contacts[*num_contacts].phone_number);

  // Increment the number of contacts
  (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(contact *contacts, int num_contacts) {
  // Get the contact's name from the user
  char name[30];
  printf("Enter the contact's name: ");
  scanf("%s", name);

  // Search for the contact in the phone book
  int found = 0;
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      // Print the contact's information
      printf("Name: %s\n", contacts[i].name);
      printf("Phone number: %s\n", contacts[i].phone_number);
      found = 1;
      break;
    }
  }

  // If the contact was not found, print an error message
  if (!found) {
    printf("Contact not found\n");
  }
}

// Function to delete a contact from the phone book
void delete_contact(contact *contacts, int *num_contacts) {
  // Get the contact's name from the user
  char name[30];
  printf("Enter the contact's name: ");
  scanf("%s", name);

  // Search for the contact in the phone book
  int found = 0;
  for (int i = 0; i < *num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      // Delete the contact
      for (int j = i + 1; j < *num_contacts; j++) {
        contacts[j - 1] = contacts[j];
      }
      (*num_contacts)--;
      found = 1;
      break;
    }
  }

  // If the contact was not found, print an error message
  if (!found) {
    printf("Contact not found\n");
  }
}

// Function to print the phone book
void print_phone_book(contact *contacts, int num_contacts) {
  // Print the header
  printf("Phone Book\n");
  printf("---------\n");

  // Print the contacts
  for (int i = 0; i < num_contacts; i++) {
    printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
  }
}

// Main function
int main() {
  // Create an array of contacts
  contact contacts[MAX_CONTACTS];

  // Initialize the number of contacts to 0
  int num_contacts = 0;

  // Get the user's choice
  int choice;
  do {
    // Print the menu
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Delete contact\n");
    printf("4. Print phone book\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        add_contact(contacts, &num_contacts);
        break;
      case 2:
        search_contact(contacts, num_contacts);
        break;
      case 3:
        delete_contact(contacts, &num_contacts);
        break;
      case 4:
        print_phone_book(contacts, num_contacts);
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}