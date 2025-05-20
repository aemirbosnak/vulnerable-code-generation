//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: surprised
/*
 * Unique C Mailing List Manager Example Program
 *
 * This program allows users to manage a mailing list of email addresses.
 * It provides the ability to add, remove, and search for email addresses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an email address
struct email_address {
  char* email;
  char* name;
  int id;
};

// Structure to represent a mailing list
struct mailing_list {
  struct email_address** addresses;
  int size;
};

// Function to add an email address to the mailing list
void add_email_address(struct mailing_list* list, char* email, char* name) {
  // Create a new email address structure
  struct email_address* new_address = malloc(sizeof(struct email_address));
  new_address->email = strdup(email);
  new_address->name = strdup(name);
  new_address->id = list->size;

  // Add the new address to the list
  list->addresses[list->size] = new_address;
  list->size++;
}

// Function to remove an email address from the mailing list
void remove_email_address(struct mailing_list* list, int id) {
  // Check that the ID is valid
  if (id < 0 || id >= list->size) {
    printf("Invalid ID\n");
    return;
  }

  // Remove the address from the list
  free(list->addresses[id]->email);
  free(list->addresses[id]->name);
  free(list->addresses[id]);

  // Shift the remaining addresses to fill the gap
  for (int i = id; i < list->size - 1; i++) {
    list->addresses[i] = list->addresses[i + 1];
  }

  // Decrement the size of the list
  list->size--;
}

// Function to search for an email address in the mailing list
void search_email_address(struct mailing_list* list, char* email) {
  // Loop through the list and find the matching email address
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->addresses[i]->email, email) == 0) {
      printf("Email address found: %s (%s)\n", list->addresses[i]->email, list->addresses[i]->name);
      return;
    }
  }

  // If no match is found, print an error message
  printf("Email address not found\n");
}

int main() {
  // Create a new mailing list
  struct mailing_list* list = malloc(sizeof(struct mailing_list));
  list->addresses = malloc(10 * sizeof(struct email_address*));
  list->size = 0;

  // Add some email addresses to the list
  add_email_address(list, "john.doe@example.com", "John Doe");
  add_email_address(list, "jane.doe@example.com", "Jane Doe");
  add_email_address(list, "john.smith@example.com", "John Smith");

  // Remove an email address from the list
  remove_email_address(list, 1);

  // Search for an email address in the list
  search_email_address(list, "john.smith@example.com");

  // Free the list memory
  for (int i = 0; i < list->size; i++) {
    free(list->addresses[i]->email);
    free(list->addresses[i]->name);
    free(list->addresses[i]);
  }
  free(list->addresses);
  free(list);

  return 0;
}