//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 12
#define MAX_CONTACTS 10

typedef struct {
  char name[MAX_NAME_LEN];
  char number[MAX_NUM_LEN];
} phonebook_contact;

void add_contact(phonebook_contact *contacts, int *num_contacts) {
  if (*num_contacts >= MAX_CONTACTS) {
    printf("Phonebook is full!\n");
    return;
  }

  printf("Enter name: ");
  scanf("%s", contacts[*num_contacts].name);

  printf("Enter number: ");
  scanf("%s", contacts[*num_contacts].number);

  (*num_contacts)++;
}

void find_contact(phonebook_contact *contacts, int num_contacts) {
  char name[MAX_NAME_LEN];

  printf("Enter name to find: ");
  scanf("%s", name);

  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      printf("Found contact:\n");
      printf("Name: %s\n", contacts[i].name);
      printf("Number: %s\n", contacts[i].number);
      return;
    }
  }

  printf("Contact not found.\n");
}

void list_contacts(phonebook_contact *contacts, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    printf("Name: %s\n", contacts[i].name);
    printf("Number: %s\n", contacts[i].number);
    printf("\n");
  }
}

void delete_contact(phonebook_contact *contacts, int *num_contacts) {
  char name[MAX_NAME_LEN];

  printf("Enter name to delete: ");
  scanf("%s", name);

  for (int i = 0; i < *num_contacts; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      for (int j = i; j < *num_contacts - 1; j++) {
        contacts[j] = contacts[j + 1];
      }

      (*num_contacts)--;
      return;
    }
  }

  printf("Contact not found.\n");
}

int main() {
  phonebook_contact contacts[MAX_CONTACTS];
  int num_contacts = 0;

  int choice;

  while (1) {
    printf("\n\n---------------\n");
    printf("1. Add contact\n");
    printf("2. Find contact\n");
    printf("3. List contacts\n");
    printf("4. Delete contact\n");
    printf("5. Quit\n");
    printf("---------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_contact(contacts, &num_contacts);
        break;
      case 2:
        find_contact(contacts, num_contacts);
        break;
      case 3:
        list_contacts(contacts, num_contacts);
        break;
      case 4:
        delete_contact(contacts, &num_contacts);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}