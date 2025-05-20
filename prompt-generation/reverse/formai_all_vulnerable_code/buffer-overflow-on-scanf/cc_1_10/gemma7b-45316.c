//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUM_LENGTH 10

struct PhoneBookEntry {
  char name[MAX_NAME_LENGTH];
  char number[MAX_NUM_LENGTH];
  struct PhoneBookEntry* next;
};

struct PhoneBookEntry* insertEntry(struct PhoneBookEntry* head) {
  struct PhoneBookEntry* newEntry = malloc(sizeof(struct PhoneBookEntry));
  newEntry->next = NULL;

  printf("Enter name: ");
  scanf("%s", newEntry->name);

  printf("Enter number: ");
  scanf("%s", newEntry->number);

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void searchEntry(struct PhoneBookEntry* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Name: %s\n", head->name);
      printf("Number: %s\n", head->number);
      return;
    }
    head = head->next;
  }

  printf("Entry not found.\n");
}

int main() {
  struct PhoneBookEntry* head = NULL;

  // Insert entries
  insertEntry(head);
  insertEntry(head);
  insertEntry(head);

  // Search for an entry
  searchEntry(head, "John Doe");

  return 0;
}