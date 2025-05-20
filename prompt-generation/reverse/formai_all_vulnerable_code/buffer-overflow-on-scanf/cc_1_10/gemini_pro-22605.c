//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book.
#define MAX_CONTACTS 100

// Define the structure of a contact.
typedef struct {
  char name[50];
  char phone_number[20];
} contact;

// Define the phone book.
contact phone_book[MAX_CONTACTS];

// Get the number of contacts in the phone book.
int get_num_contacts() {
  int num_contacts;
  printf("How many contacts do you want to add? ");
  scanf("%d", &num_contacts);
  return num_contacts;
}

// Get the contact information.
void get_contact_info(contact *c) {
  printf("Enter the contact's name: ");
  scanf("%s", c->name);
  printf("Enter the contact's phone number: ");
  scanf("%s", c->phone_number);
}

// Add a contact to the phone book.
void add_contact(int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    get_contact_info(&phone_book[i]);
  }
}

// Search for a contact in the phone book.
void search_contact(char *name) {
  int found = 0;
  for (int i = 0; i < MAX_CONTACTS; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Found contact: %s, %s\n", phone_book[i].name, phone_book[i].phone_number);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Contact not found.\n");
  }
}

// Print the phone book.
void print_phone_book() {
  for (int i = 0; i < MAX_CONTACTS; i++) {
    if (strlen(phone_book[i].name) > 0) {
      printf("%s, %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
  }
}

// Main function.
int main() {
  int num_contacts;

  // Get the number of contacts.
  num_contacts = get_num_contacts();

  // Add contacts to the phone book.
  add_contact(num_contacts);

  // Search for a contact.
  char name[50];
  printf("Enter the name of the contact you want to search for: ");
  scanf("%s", name);
  search_contact(name);

  // Print the phone book.
  print_phone_book();

  return 0;
}