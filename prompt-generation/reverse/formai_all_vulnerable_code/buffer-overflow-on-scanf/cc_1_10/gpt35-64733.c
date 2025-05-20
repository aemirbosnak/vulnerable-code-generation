//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACT 100

struct contact {
  char name[50];
  char phone_number[20];
  char email_address[50];
};

void add_contact(struct contact* phone_book, int* contact_count) {
  if (*contact_count >= MAX_CONTACT) {
    printf("Phone book is full! Cannot add new contacts.\n");
    return;
  }

  struct contact new_contact;

  printf("Enter name: ");
  fgets(new_contact.name, 50, stdin);
  new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

  printf("Enter phone number: ");
  fgets(new_contact.phone_number, 20, stdin);
  new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = '\0';

  printf("Enter email address: ");
  fgets(new_contact.email_address, 50, stdin);
  new_contact.email_address[strcspn(new_contact.email_address, "\n")] = '\0';

  phone_book[*contact_count] = new_contact;
  *contact_count += 1;

  printf("Contact added successfully!\n");
}

void search_contact(struct contact* phone_book, int contact_count) {
  char search_str[50];
  int found = 0;

  printf("Enter search query: ");
  fgets(search_str, 50, stdin);
  search_str[strcspn(search_str, "\n")] = '\0';

  for (int i = 0; i < contact_count; i++) {
    if (strstr(phone_book[i].name, search_str) ||
        strstr(phone_book[i].phone_number, search_str) ||
        strstr(phone_book[i].email_address, search_str)) {
      printf("Name: %s\n", phone_book[i].name);
      printf("Phone number: %s\n", phone_book[i].phone_number);
      printf("Email address: %s\n", phone_book[i].email_address);
      printf("\n");
      found = 1;
    }
  }

  if (!found) {
    printf("No results found.\n");
  }
}

void display_all_contacts(struct contact* phone_book, int contact_count) {
  if (contact_count == 0) {
    printf("Phone book is empty!\n");
    return;
  }

  printf("Total contacts: %d\n\n", contact_count);

  for (int i = 0; i < contact_count; i++) {
    printf("Name: %s\n", phone_book[i].name);
    printf("Phone number: %s\n", phone_book[i].phone_number);
    printf("Email address: %s\n", phone_book[i].email_address);
    printf("\n");
  }
}

int main() {
  struct contact phone_book[MAX_CONTACT];
  int contact_count = 0;
  int choice;

  while (1) {
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Display all contacts\n");
    printf("4. Exit\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1:
        add_contact(phone_book, &contact_count);
        break;
      case 2:
        search_contact(phone_book, contact_count);
        break;
      case 3:
        display_all_contacts(phone_book, contact_count);
        break;
      case 4:
        printf("Exiting program. Goodbye!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice! Please enter a valid choice (1-4).\n");
    }
  }

  return 0;
}