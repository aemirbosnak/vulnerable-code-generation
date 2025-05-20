//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
  char name[50];
  char phone[20];
} contact;

// Define the phone book as an array of contacts
contact phone_book[MAX_CONTACTS];

// Define the current number of contacts in the phone book
int num_contacts = 0;

// Function to add a new contact to the phone book
void add_contact(char *name, char *phone) {
  // Check if the phone book is full
  if (num_contacts == MAX_CONTACTS) {
    printf("Phone book is full. Cannot add new contact.\n");
    return;
  }

  // Copy the name and phone number into the new contact
  strcpy(phone_book[num_contacts].name, name);
  strcpy(phone_book[num_contacts].phone, phone);

  // Increment the number of contacts
  num_contacts++;
}

// Function to search for a contact in the phone book
int search_contact(char *name) {
  // Iterate over the phone book
  for (int i = 0; i < num_contacts; i++) {
    // Check if the name matches the search term
    if (strcmp(phone_book[i].name, name) == 0) {
      // Return the index of the contact
      return i;
    }
  }

  // Return -1 if the contact was not found
  return -1;
}

// Function to print the phone book
void print_phone_book() {
  // Iterate over the phone book
  for (int i = 0; i < num_contacts; i++) {
    // Print the contact's name and phone number
    printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
  }
}

// Function to get a valid name from the user
char *get_name() {
  // Allocate memory for the name
  char *name = malloc(50);

  // Get the name from the user
  printf("Enter the contact's name: ");
  scanf(" %s", name);

  // Return the name
  return name;
}

// Function to get a valid phone number from the user
char *get_phone() {
  // Allocate memory for the phone number
  char *phone = malloc(20);

  // Get the phone number from the user
  printf("Enter the contact's phone number: ");
  scanf(" %s", phone);

  // Return the phone number
  return phone;
}

// Main function
int main() {
  // Add some example contacts to the phone book
  add_contact("John Doe", "555-123-4567");
  add_contact("Jane Doe", "555-234-5678");
  add_contact("Bob Smith", "555-345-6789");

  // Print the phone book
  print_phone_book();

  // Get the name of the contact to search for
  char *name = get_name();

  // Search for the contact
  int index = search_contact(name);

  // If the contact was found, print their phone number
  if (index != -1) {
    printf("Phone number: %s\n", phone_book[index].phone);
  } else {
    printf("Contact not found.\n");
  }

  // Free the allocated memory
  free(name);

  return 0;
}