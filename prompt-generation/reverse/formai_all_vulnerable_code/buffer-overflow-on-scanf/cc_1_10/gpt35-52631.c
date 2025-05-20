//FormAI DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold contact information
struct Contact {
  char name[50];
  char phone_number[20];
  char email[50];
};

// Declare an array of Contacts
struct Contact contacts[100];

// Declare a variable to keep track of number of contacts
int num_contacts = 0;

// Function to display all contacts
void display_all_contacts() {
  printf("\nAll Contacts:\n");
  for (int i = 0; i < num_contacts; i++) {
    printf("Name: %s\n", contacts[i].name);
    printf("Phone Number: %s\n", contacts[i].phone_number);
    printf("Email: %s\n\n", contacts[i].email);
  }
}

// Function to add a new contact
void add_contact() {
  struct Contact new_contact;
  printf("Enter Name: ");
  fgets(new_contact.name, 50, stdin);
  printf("Enter Phone Number: ");
  fgets(new_contact.phone_number, 20, stdin);
  printf("Enter Email: ");
  fgets(new_contact.email, 50, stdin);
  contacts[num_contacts] = new_contact;
  num_contacts++;
  printf("\nContact added successfully!\n");
}

// Function to search for a contact by name
void search_contact() {
  char search_name[50];
  printf("Enter Name to Search: ");
  fgets(search_name, 50, stdin);
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(search_name, contacts[i].name) == 0) {
      printf("\nContact Found!\n");
      printf("Name: %s\n", contacts[i].name);
      printf("Phone Number: %s\n", contacts[i].phone_number);
      printf("Email: %s\n\n", contacts[i].email);
      return;
    }
  }
  printf("\nContact Not Found!\n");
}

int main() {
  int choice;
  do {
    printf("\n--- C Phone Book ---\n\n");
    printf("1. Display All Contacts\n");
    printf("2. Add a New Contact\n");
    printf("3. Search for Contact\n");
    printf("4. Exit\n");
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);
    getchar();  // to clear the newline character from input buffer
    switch (choice) {
      case 1:
        display_all_contacts();
        break;
      case 2:
        add_contact();
        break;
      case 3:
        search_contact();
        break;
      case 4:
        printf("\nExiting Program. Goodbye!\n");
        break;
      default:
        printf("\nInvalid Choice. Try Again!\n");
    }
  } while (choice != 4);
  return 0;
}