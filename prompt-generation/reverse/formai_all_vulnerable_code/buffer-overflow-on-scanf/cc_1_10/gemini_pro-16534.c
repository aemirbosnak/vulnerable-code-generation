//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct _contact {
  char name[50];
  char phone[20];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char *name, char *phone) {
  if (num_contacts >= MAX_CONTACTS) {
    printf("Phonebook is full!\n");
    return;
  }

  strcpy(phonebook[num_contacts].name, name);
  strcpy(phonebook[num_contacts].phone, phone);
  num_contacts++;
}

void print_contact(contact *c) {
  printf("%s: %s\n", c->name, c->phone);
}

void search_contact(char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phonebook[i].name, name) == 0) {
      print_contact(&phonebook[i]);
      return;
    }
  }

  printf("Contact not found!\n");
}

void remove_contact(char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phonebook[i].name, name) == 0) {
      for (int j = i + 1; j < num_contacts; j++) {
        phonebook[j - 1] = phonebook[j];
      }
      num_contacts--;
      return;
    }
  }

  printf("Contact not found!\n");
}

int main() {
  // Add some sample contacts
  add_contact("Alice", "123-456-7890");
  add_contact("Bob", "098-765-4321");
  add_contact("Charlie", "555-1212");

  // Print the phonebook
  printf("Phonebook:\n");
  for (int i = 0; i < num_contacts; i++) {
    print_contact(&phonebook[i]);
  }

  // Search for a contact
  char name[50];
  printf("Enter a name to search for: ");
  scanf("%s", name);
  search_contact(name);

  // Remove a contact
  printf("Enter a name to remove: ");
  scanf("%s", name);
  remove_contact(name);

  // Print the updated phonebook
  printf("Updated phonebook:\n");
  for (int i = 0; i < num_contacts; i++) {
    print_contact(&phonebook[i]);
  }

  return 0;
}