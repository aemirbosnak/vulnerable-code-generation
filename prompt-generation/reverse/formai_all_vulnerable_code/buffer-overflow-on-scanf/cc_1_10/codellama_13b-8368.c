//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: active
/*
 * A simple C phone book program
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15

// Struct to represent a contact
typedef struct {
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Contact;

// Function to add a contact
void addContact(Contact* contact) {
  // Get the name and phone number from the user
  printf("Enter the name: ");
  scanf("%s", contact->name);
  printf("Enter the phone number: ");
  scanf("%s", contact->phone);
}

// Function to search for a contact
void searchContact(Contact* contact) {
  // Get the name to search for from the user
  printf("Enter the name to search for: ");
  scanf("%s", contact->name);

  // Search for the contact
  for (int i = 0; i < 10; i++) {
    if (strcmp(contact[i].name, contact->name) == 0) {
      printf("Found contact: %s %s\n", contact[i].name, contact[i].phone);
      break;
    }
  }
}

// Function to delete a contact
void deleteContact(Contact* contact) {
  // Get the name to delete from the user
  printf("Enter the name to delete: ");
  scanf("%s", contact->name);

  // Search for the contact and delete it
  for (int i = 0; i < 10; i++) {
    if (strcmp(contact[i].name, contact->name) == 0) {
      for (int j = i; j < 9; j++) {
        contact[j] = contact[j + 1];
      }
      printf("Deleted contact: %s %s\n", contact[i].name, contact[i].phone);
      break;
    }
  }
}

int main() {
  // Declare an array of 10 contacts
  Contact contacts[10];

  // Add a few contacts
  addContact(&contacts[0]);
  addContact(&contacts[1]);
  addContact(&contacts[2]);

  // Search for a contact
  searchContact(&contacts[3]);

  // Delete a contact
  deleteContact(&contacts[4]);

  // Print the remaining contacts
  for (int i = 0; i < 10; i++) {
    if (strcmp(contacts[i].name, "") != 0) {
      printf("%s %s\n", contacts[i].name, contacts[i].phone);
    }
  }

  return 0;
}