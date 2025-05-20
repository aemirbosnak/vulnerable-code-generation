//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct DatabaseEntry {
  char name[256];
  int age;
  struct DatabaseEntry* next;
} DatabaseEntry;

void insertEntry(DatabaseEntry** head) {
  DatabaseEntry* newEntry = malloc(sizeof(DatabaseEntry));
  newEntry->next = NULL;

  printf("Enter name: ");
  scanf("%s", newEntry->name);

  printf("Enter age: ");
  scanf("%d", &newEntry->age);

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

void searchEntry(DatabaseEntry* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Name: %s\n", head->name);
      printf("Age: %d\n", head->age);
      return;
    }
    head = head->next;
  }

  printf("Entry not found.\n");
}

int main() {
  DatabaseEntry* head = NULL;

  insertEntry(&head);
  insertEntry(&head);
  insertEntry(&head);

  searchEntry(head, "John Doe");

  return 0;
}