//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to store a contact's information
typedef struct contact {
  char name[50];
  char phone_number[20];
  char email[50];
} contact_t;

// A function to add a contact to the phone book
void add_contact(contact_t *phone_book, int *num_contacts, char *name, char *phone_number, char *email) {
  // Check if the phone book is full
  if (*num_contacts >= 100) {
    printf("Sorry, the phone book is full!\n");
    return;
  }

  // Copy the contact's information into the phone book
  strcpy(phone_book[*num_contacts].name, name);
  strcpy(phone_book[*num_contacts].phone_number, phone_number);
  strcpy(phone_book[*num_contacts].email, email);

  // Increment the number of contacts
  (*num_contacts)++;
}

// A function to search for a contact in the phone book
void search_contact(contact_t *phone_book, int num_contacts, char *name) {
  // Loop through the contacts in the phone book
  for (int i = 0; i < num_contacts; i++) {
    // Check if the contact's name matches the search term
    if (strcmp(phone_book[i].name, name) == 0) {
      // Print the contact's information
      printf("Name: %s\n", phone_book[i].name);
      printf("Phone number: %s\n", phone_book[i].phone_number);
      printf("Email: %s\n", phone_book[i].email);
      return;
    }
  }

  // If no contact was found, print an error message
  printf("Sorry, no contact found with that name!\n");
}

// A function to print the phone book
void print_phone_book(contact_t *phone_book, int num_contacts) {
  // Loop through the contacts in the phone book
  for (int i = 0; i < num_contacts; i++) {
    // Print the contact's information
    printf("Name: %s\n", phone_book[i].name);
    printf("Phone number: %s\n", phone_book[i].phone_number);
    printf("Email: %s\n\n", phone_book[i].email);
  }
}

// The main function
int main() {
  // Create the phone book
  contact_t phone_book[100];

  // Initialize the number of contacts to 0
  int num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(phone_book, &num_contacts, "John Smith", "555-123-4567", "john.smith@example.com");
  add_contact(phone_book, &num_contacts, "Jane Doe", "555-234-5678", "jane.doe@example.com");
  add_contact(phone_book, &num_contacts, "Bill Jones", "555-345-6789", "bill.jones@example.com");

  // Print the phone book
  print_phone_book(phone_book, num_contacts);

  // Search for a contact in the phone book
  char name[50];
  printf("Enter the name of the contact you want to search for: ");
  scanf("%s", name);
  search_contact(phone_book, num_contacts, name);

  return 0;
}