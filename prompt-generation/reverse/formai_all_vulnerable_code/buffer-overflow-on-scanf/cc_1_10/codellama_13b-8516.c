//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct {
  char name[20];
  char number[12];
} contact;

// Function to add a new contact
void addContact(contact *contacts, int *size) {
  printf("Enter name: ");
  scanf("%s", contacts[*size].name);
  printf("Enter number: ");
  scanf("%s", contacts[*size].number);
  *size += 1;
}

// Function to search for a contact
int searchContact(contact *contacts, int size, char *name) {
  for (int i = 0; i < size; i++) {
    if (strcmp(contacts[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to delete a contact
void deleteContact(contact *contacts, int *size, char *name) {
  int index = searchContact(contacts, *size, name);
  if (index == -1) {
    printf("Contact not found.\n");
    return;
  }
  for (int i = index; i < *size - 1; i++) {
    contacts[i] = contacts[i + 1];
  }
  *size -= 1;
}

// Function to display all contacts
void displayAll(contact *contacts, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", contacts[i].name, contacts[i].number);
  }
}

int main() {
  contact contacts[100];
  int size = 0;
  int option;
  char name[20];

  while (1) {
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Display All\n");
    printf("5. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      addContact(contacts, &size);
      break;
    case 2:
      printf("Enter name: ");
      scanf("%s", name);
      int index = searchContact(contacts, size, name);
      if (index == -1) {
        printf("Contact not found.\n");
      } else {
        printf("Contact found at index %d.\n", index);
      }
      break;
    case 3:
      printf("Enter name: ");
      scanf("%s", name);
      deleteContact(contacts, &size, name);
      break;
    case 4:
      displayAll(contacts, size);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid option.\n");
      break;
    }
  }
  return 0;
}