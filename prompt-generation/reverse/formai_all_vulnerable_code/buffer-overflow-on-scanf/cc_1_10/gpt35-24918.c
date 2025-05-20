//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the maximum length of each contact's name and phone number
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

// Define the contact struct that holds the name and phone number of a contact
typedef struct contact {
  char name[MAX_NAME_LENGTH];
  char number[MAX_NUMBER_LENGTH];
} Contact;

// Define the phone book that holds all the contacts
Contact phone_book[MAX_CONTACTS];

// Define the number of contacts currently in the phone book
int num_contacts = 0;

// Define the function to add a contact to the phone book
void add_contact() {
  // Check if the phone book is already full
  if (num_contacts == MAX_CONTACTS) {
    printf("Phone book is full. Cannot add more contacts.\n");
    return;
  }
  // Prompt the user to enter the name and phone number of the new contact
  char name[MAX_NAME_LENGTH];
  char number[MAX_NUMBER_LENGTH];
  printf("Enter name: ");
  scanf("%s", name);
  printf("Enter number: ");
  scanf("%s", number);
  // Create the new contact and add it to the phone book
  Contact new_contact;
  strcpy(new_contact.name, name);
  strcpy(new_contact.number, number);
  phone_book[num_contacts] = new_contact;
  num_contacts++;
  printf("Contact added successfully.\n");
}

// Define the function to search for a contact in the phone book
void search_contact() {
  // Prompt the user to enter the name of the contact to search for
  char name[MAX_NAME_LENGTH];
  printf("Enter name to search: ");
  scanf("%s", name);
  // Search for the contact in the phone book
  int found = 0;
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Contact found:\n");
      printf("Name: %s\n", phone_book[i].name);
      printf("Number: %s\n", phone_book[i].number);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Contact not found.\n");
  }
}

// Define the function to print all contacts in the phone book
void print_contacts() {
  // Check if phone book is empty
  if (num_contacts == 0) {
    printf("Phone book is empty.\n");
    return;
  }
  // Print all contacts in the phone book
  printf("Phone book contacts:\n");
  for (int i = 0; i < num_contacts; i++) {
    printf("%d. Name: %s\n", i+1, phone_book[i].name);
    printf("   Number: %s\n", phone_book[i].number);
  }
}

// Define the main function that runs the phone book program
int main() {
  // Print the welcome message and menu options
  printf("Welcome to the Phone Book program.\n");
  int choice;
  do {
    printf("Menu:\n1. Add contact\n2. Search contact\n3. Print all contacts\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_contact();
        break;
      case 2:
        search_contact();
        break;
      case 3:
        print_contacts();
        break;
      case 4:
        printf("Phone Book program closed.\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
        break;
    }
  } while (choice != 4);
  return 0;
}