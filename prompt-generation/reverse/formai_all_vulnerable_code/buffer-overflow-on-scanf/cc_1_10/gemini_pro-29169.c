//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_CONTACTS 100

typedef struct contact {
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
  if (num_contacts >= MAX_CONTACTS) {
    printf("Phonebook is full!\n");
    return;
  }

  printf("Enter name: ");
  scanf("%s", phonebook[num_contacts].name);
  printf("Enter phone: ");
  scanf("%s", phonebook[num_contacts].phone);

  num_contacts++;
}

void search_contact() {
  char name[MAX_NAME_LEN];

  printf("Enter name to search for: ");
  scanf("%s", name);

  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phonebook[i].name, name) == 0) {
      printf("Name: %s\n", phonebook[i].name);
      printf("Phone: %s\n", phonebook[i].phone);
      return;
    }
  }

  printf("Contact not found!\n");
}

void print_all_contacts() {
  for (int i = 0; i < num_contacts; i++) {
    printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Print all contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_contact();
        break;
      case 2:
        search_contact();
        break;
      case 3:
        print_all_contacts();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}