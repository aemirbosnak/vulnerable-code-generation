//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char name[20];
  int amount;
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = malloc(sizeof(Entry));
  newEntry->next = head;
  head = newEntry;

  printf("Enter name: ");
  scanf("%s", newEntry->name);

  printf("Enter amount: ");
  scanf("%d", &newEntry->amount);
}

void printEntries() {
  Entry* currentEntry = head;

  printf("Entries:\n");
  while (currentEntry) {
    printf("%s: %d\n", currentEntry->name, currentEntry->amount);
    currentEntry = currentEntry->next;
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add Entry\n");
    printf("2. Print Entries\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        printEntries();
        break;
      default:
        exit(1);
    }
  }

  return 0;
}