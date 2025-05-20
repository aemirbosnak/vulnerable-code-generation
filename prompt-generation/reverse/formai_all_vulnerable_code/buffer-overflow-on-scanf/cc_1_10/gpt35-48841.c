//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

struct contact {
  char name[50];
  char phone_number[20];
};

int size = 0; // current number of contacts

void add_contact(struct contact contacts[]);
void search_contact(struct contact contacts[]);
void display_contacts(struct contact contacts[]);

// Recursive menu function
void menu(struct contact contacts[]) {
  printf("\nMenu:\n");
  printf("1. Add contact\n");
  printf("2. Search contact\n");
  printf("3. Display all contacts\n");
  printf("4. Exit\n");

  int choice;
  printf("\nEnter choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      add_contact(contacts);
      menu(contacts);
      break;
    case 2:
      search_contact(contacts);
      menu(contacts);
      break;
    case 3:
      display_contacts(contacts);
      menu(contacts);
      break;
    case 4:
      printf("Goodbye!");
      exit(0);
    default:
      printf("Invalid choice. Try again.");
      menu(contacts);
  }
}

// Recursive function to add a contact
void add_contact(struct contact contacts[]) {
  if (size == CAPACITY) {
    printf("\nError: Contact list is full!\n");
    menu(contacts);
  }

  printf("\nEnter name: ");
  scanf("%s", contacts[size].name);

  printf("Enter phone number: ");
  scanf("%s", contacts[size].phone_number);

  size++;

  printf("\nContact added successfully!\n");
  menu(contacts);
}

// Recursive function to search for a contact
void search_contact(struct contact contacts[]) {
  if (size == 0) {
    printf("\nContact list is empty!\n");
    menu(contacts);
  }

  char search_name[50];
  printf("\nEnter name to search: ");
  scanf("%s", search_name);

  int found = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(search_name, contacts[i].name) == 0) {
      printf("\nName: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone_number);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Contact not found!");
  }

  menu(contacts);
}

// Recursive function to display all contacts
void display_contacts(struct contact contacts[]) {
  if (size == 0) {
    printf("\nContact list is empty!\n");
    menu(contacts);
  }

  printf("\nContacts:\n");
  for (int i = 0; i < size; i++) {
    printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone_number);
  }

  menu(contacts);
}

int main() {
  struct contact contacts[CAPACITY];
  menu(contacts);
  return 0;
}