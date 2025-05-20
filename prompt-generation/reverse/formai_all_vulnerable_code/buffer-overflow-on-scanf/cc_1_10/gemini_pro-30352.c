//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 32
#define MAX_NUMBER_LEN 16

typedef struct {
  char name[MAX_NAME_LEN];
  char number[MAX_NUMBER_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
  if (num_contacts == MAX_CONTACTS) {
    printf("Phone book is full!\n");
    return;
  }

  printf("Enter name: ");
  scanf(" %s", contacts[num_contacts].name);

  printf("Enter number: ");
  scanf(" %s", contacts[num_contacts].number);

  num_contacts++;
}

void remove_contact() {
  char name[MAX_NAME_LEN];

  printf("Enter name to remove: ");
  scanf(" %s", name);

  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {

      for (int j = i; j < num_contacts - 1; j++) {
        contacts[j] = contacts[j + 1];
      }

      num_contacts--;
      break;
    }
  }

  printf("Contact removed.\n");
}

void search_contact() {
  char name[MAX_NAME_LEN];

  printf("Enter name to search: ");
  scanf(" %s", name);

  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      printf("Contact found:\n");
      printf("Name: %s\n", contacts[i].name);
      printf("Number: %s\n", contacts[i].number);
      return;
    }
  }

  printf("Contact not found.\n");
}

void print_contacts() {
  for (int i = 0; i < num_contacts; i++) {
    printf("Contact %d:\n", i + 1);
    printf("Name: %s\n", contacts[i].name);
    printf("Number: %s\n\n", contacts[i].number);
  }
}

int main() {
  int choice;

  do {
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Search contact\n");
    printf("4. Print contacts\n");
    printf("5. Exit\n");
    printf(">> ");
    scanf(" %d", &choice);

    switch (choice) {
      case 1:
        add_contact();
        break;
      case 2:
        remove_contact();
        break;
      case 3:
        search_contact();
        break;
      case 4:
        print_contacts();
        break;
      case 5:
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}